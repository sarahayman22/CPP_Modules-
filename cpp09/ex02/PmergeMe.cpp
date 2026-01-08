/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:52:28 by saabo-sh          #+#    #+#             */
/*   Updated: 2026/01/08 17:52:50 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
        
PmergeMe::PmergeMe(const std::vector<int>& v, const std::deque<int>& q)
    : _v(v), _q(q)
{
    createPairsVector();
    sortPairsBySecond();
    buildMainChain();
    insertPending();   // ← هذا ضروري
        _v = _mainChain;   
}

void PmergeMe::createPairsVector()
{
    _pairs.clear();
    hasStraggler = false;
    
    size_t i = 0;
    while (i +1 < _v.size())
    {
        int a = _v[i];
        int b = _v[i+1];
        
        if (a < b)
            _pairs.push_back(std::make_pair(a, b));
        else
            _pairs.push_back(std::make_pair(b, a));
        
         i += 2;
    }
    
    if (_v.size() % 2 != 0)
    {
        straggler = _v.back();
        hasStraggler = true ;
    }
}

void PmergeMe::sortPairsBySecond()
{
    if (_pairs.size() < 2)
        return;
    for (size_t size = 1; size < _pairs.size(); size *= 2)
    {
//   What does left mean?
// left = start index of two blocks to merge
// Each iteration merges two blocks of size size
        for (size_t left = 0; left+size < _pairs.size(); left += 2 * size)
        {
            // mid = end of the left block
            size_t mid = left + size -1;
//right = end of the right block
// Why min?
// Prevents out-of-bounds access when size isn’t power of 2
            size_t right = std::min(left + 2 * size - 1, _pairs.size() - 1);
            // [left .. mid] + [mid+1 .. right]
            mergePairs(left, mid, right);
            
        }
    }
}

void PmergeMe::mergePairs(size_t left, size_t mid, size_t right)
{
    std::vector<std::pair< int,int> > temp;
    size_t i = left;
    size_t j = mid + 1;
    // As long as both blocks still have elements:
    while (i <= mid && j <= right)
    {
        //_pairs[i].second That’s the larger element of the Ford–Johnson pair
        if (_pairs[i].second <= _pairs[j].second)
            temp.push_back(_pairs[i++]);
        else
            temp.push_back(_pairs[j++]);
    }

    while (i <= mid)
        temp.push_back(_pairs[i++]);

    while (j <= right)
        temp.push_back(_pairs[j++]);

    for (size_t k = 0; k < temp.size(); k++)
        _pairs[left + k] = temp[k];    
}

// Why Ford–Johnson does this

// Classic merge sort:

// Sorts everything at once

// Ford–Johnson:

// Sorts half the elements

// Inserts the rest optimally

// This reduces comparisons — that’s the magic.
void PmergeMe::buildMainChain()
{
    _mainChain.clear();
    _pending.clear();
    
    for (size_t i = 0; i < _pairs.size(); ++i)
    {
        _mainChain.push_back(_pairs[i].second);
        _pending.push_back(_pairs[i].first);
    }
    if(hasStraggler)
        _pending.push_back(straggler);

        // What this guarantees (important)
// ✔ _mainChain is already sorted
// ✔ _pending contains only elements to be inserted later
// ✔ Straggler is handled correctly
// ✔ No sorting is performed here
// ✔ Ford–Johnson logic is respected
}

void PmergeMe::binaryInsert(int value)
{
    size_t left = 0;
    size_t right = _mainChain.size();

    while (left < right)
    {
        size_t mid = (left + right) / 2;
        if (value < _mainChain[mid])
            right = mid;
        else
            left = mid + 1;
    }
    _mainChain.insert(_mainChain.begin() + left, value);
}

static std::vector<size_t> generateJacobsthal(size_t n)
{
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);

    while (jacob.back() < n)
        jacob.push_back(jacob[jacob.size() - 1] +
                         2 * jacob[jacob.size() - 2]);

    return jacob;
}

void PmergeMe::insertPending()
{
    if (_pending.empty())
        return;

    std::vector<size_t> jacob = generateJacobsthal(_pending.size());
    std::vector<bool> inserted(_pending.size(), false);

    for (size_t j = 1; j < jacob.size(); j++)
    {
        size_t start = jacob[j];
        size_t end = jacob[j - 1];

        for (size_t i = std::min(start, _pending.size()) - 1;
             i >= end && i < _pending.size();
             i--)
        {
            if (!inserted[i])
            {
                binaryInsert(_pending[i]);
                inserted[i] = true;
            }
            if (i == 0)
                break;
        }
    }
}


void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _v.size(); i++)
        std::cout << _v[i] << " ";
    std::cout << std::endl;
}


void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _v.size(); i++)
        std::cout << _v[i] << " ";
    std::cout << std::endl;
}


/* ===== DEBUG ONLY ===== */
void PmergeMe::debugPrintPairs() const
{
    std::cout << "Pairs:" << std::endl;
    for (size_t i = 0; i < _pairs.size(); i++)
        std::cout << "(" << _pairs[i].first << ", " << _pairs[i].second << ")" << std::endl;

    if (hasStraggler)
        std::cout << "Straggler: " << straggler << std::endl;
}

void PmergeMe::debugPrintMainChain() const
{
    std::cout << "Main chain: ";
    for (size_t i = 0; i < _mainChain.size(); i++)
        std::cout << _mainChain[i] << " ";
    std::cout << std::endl;

    std::cout << "Pending: ";
    for (size_t i = 0; i < _pending.size(); i++)
        std::cout << _pending[i] << " ";
    std::cout << std::endl;
}


/////////////////////////////queue//////////////////////////////////////

void PmergeMe::makePairsDeque(const std::deque<int>& input)
{
    _pairsD.clear();

    size_t i = 0;
    while (i + 1 < input.size())
    {
        int a = input[i];
        int b = input[i + 1];

        if (a > b)
            std::swap(a, b);

        _pairsD.push_back(std::make_pair(a, b));
        i += 2;
    }

    // odd element
    if (i < input.size())
        _pairsD.push_back(std::make_pair(input[i], -1));
}

void PmergeMe::mergePairsDeque(size_t left, size_t mid, size_t right)
{
    std::deque< std::pair<int,int> > temp;
    size_t i = left;
    size_t j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (_pairsD[i].second <= _pairsD[j].second)
            temp.push_back(_pairsD[i++]);
        else
            temp.push_back(_pairsD[j++]);
    }

    while (i <= mid)
        temp.push_back(_pairsD[i++]);
    while (j <= right)
        temp.push_back(_pairsD[j++]);

    for (size_t k = 0; k < temp.size(); k++)
        _pairsD[left + k] = temp[k];
}

void PmergeMe::sortPairsDeque()
{
    if (_pairsD.size() < 2)
        return;

    for (size_t size = 1; size < _pairsD.size(); size *= 2)
    {
        for (size_t left = 0; left + size < _pairsD.size(); left += 2 * size)
        {
            size_t mid = left + size - 1;
            size_t right = std::min(left + 2 * size - 1, _pairsD.size() - 1);
            mergePairsDeque(left, mid, right);
        }
    }
}

void PmergeMe::buildMainChainDeque()
{
    _mainChainD.clear();
    _pendingD.clear();

    for (size_t i = 0; i < _pairsD.size(); i++)
    {
        if (_pairsD[i].second != -1)
            _mainChainD.push_back(_pairsD[i].second);

        if (_pairsD[i].first != -1)
            _pendingD.push_back(_pairsD[i].first);
    }
}

void PmergeMe::binaryInsertDeque(int value)
{
    size_t left = 0;
    size_t right = _mainChainD.size();

    while (left < right)
    {
        size_t mid = (left + right) / 2;

        if (value < _mainChainD[mid])
            right = mid;
        else
            left = mid + 1;
    }

    _mainChainD.insert(_mainChainD.begin() + left, value);
}

void PmergeMe::insertPendingDeque()
{
    if (_pendingD.empty())
        return;

    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);

    while (jacob.back() < _pendingD.size())
    {
        size_t n = jacob.size();
        jacob.push_back(jacob[n - 1] + 2 * jacob[n - 2]);
    }

    std::vector<bool> used(_pendingD.size(), false);

    for (size_t i = 1; i < jacob.size(); i++)
    {
        size_t start = std::min(jacob[i], _pendingD.size());
        size_t end = std::min(jacob[i - 1], _pendingD.size());

        for (size_t j = start; j-- > end; )
        {
            if (!used[j])
            {
                binaryInsertDeque(_pendingD[j]);
                used[j] = true;
            }
        }
    }
}

void PmergeMe::printAfterDeque() const
{
    std::cout << "After (deque): ";
    for (size_t i = 0; i < _mainChainD.size(); i++)
        std::cout << _mainChainD[i] << " ";
    std::cout << std::endl;
}
