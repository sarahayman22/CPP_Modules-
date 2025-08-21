/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:31:17 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/08/21 19:10:24 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include "replacer.hpp"

//open a file, read everything inside, and return the contents as a single string.
bool read_data(const std::string& path, std::string& out)
{
    std::ifstream in(path.c_str());   // open file for reading
    if (!in) {
        std::cerr << "Error: cannot open input file: " << path << "\n";
        return false;
    }

    out.clear();                       // make sure output string is empty
    std::string line;

    while (std::getline(in, line)) {   // read file line by line
        out += line;                   // add the line text
        out += '\n';                   // add newline back (getline removes it)
    }

    return true;                       // success
}

std::string replace_all(const std::string& input, const std::string& s1, const std::string& s2)
{
    if(s1.empty())
    {
        return input;
    }
    std::string out;
    //With reserve, you avoid repeated reallocations by giving it a big enough buffer from the start.
    out.reserve(input.size());
    
    for (std::size_t i=0; i<input.size();)
    {
        bool match = false;
        // check if s1 matches starting at position i
        if (i + s1.size() <= input.size())
        {
            match = true;
            for(std::size_t j = 0; j < s1.size(); j++)
            {
                if (input[i+j] != s1[j])
                {
                    match = false;
                    break;
                }
            }
        }
        if (match)
        {
            // found s1 at i -> append s2, jump over s1
            out += s2;
            i += s1.size();
        }
        else
        {
          // no match -> copy one character and move on
            out += input[i];
            ++i;
        }
    }
    return out;
}
bool write_data(const std::string& path, const std::string& data)
{
    std::ofstream out(path.c_str()); // truncates by default
    if (!out) {
        std::cerr << "Error: cannot create output file: " << path << "\n";
        return false;
    }

    out << data;

    if (!out) {
        std::cerr << "Error: write failed for output file: " << path << "\n";
        return false;
    }
    return true;
}

int copy_data(const std::string& src, const std::string& s1, const std::string& s2)
{
    if(s1.empty())
    {
        std::cerr << "Error: search string cannot be empty.\n";
        return 1;
    }
    std::string input ;
    if(!read_data(src, input))
    {
        return 1;
    }
    std::string output;
    if (s1  == s2)
    {
        output = input ;
        
    }
    else 
    {
        output = replace_all(input, s1, s2);
    }
    const std::string dst =  src + ".replace";
    if (!write_data(dst, output))
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
