/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:52:20 by saabo-sh          #+#    #+#             */
/*   Updated: 2026/01/11 15:21:42 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <utility>
#include <cstddef>
#include <iostream>
#include <ctime>

class PmergeMe 
{
private:
 
    std::vector<int> _v;
    std::vector<std::pair<int,int> > _pairs;
    std::vector<int> _mainChain;
    std::vector<int> _pending;
    bool hasStraggler;
    int straggler;

    void createPairsVector();
    void sortPairsBySecond();
    void mergePairs(size_t left, size_t mid, size_t right);
    void buildMainChain();
    void binaryInsert(int value);
    void insertPending();

    std::deque<int> _q;
    std::deque<std::pair<int,int> > _pairsD;
    std::deque<int> _mainChainD;
    std::deque<int> _pendingD;

    void makePairsDeque(const std::deque<int>& input);
    void mergePairsDeque(size_t left, size_t mid, size_t right);
    void sortPairsDeque();
    void buildMainChainDeque();
    void binaryInsertDeque(int value);
    void insertPendingDeque();

public:
    PmergeMe(const std::vector<int>& v, const std::deque<int>& q);

    void printAfter() const;
    void printAfterDeque() const;
    
    void makePairsDequePublic(const std::deque<int>& input) { makePairsDeque(input); }
    void sortPairsDequePublic() { sortPairsDeque(); }
    void buildMainChainDequePublic() { buildMainChainDeque(); }
    void insertPendingDequePublic() { insertPendingDeque(); }
        
    double sortVectorWithTime();
    double sortDequeWithTime();


};

#endif

