/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silver.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:05:10 by mhuszar           #+#    #+#             */
/*   Updated: 2024/12/08 21:35:41 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

std::map<int, std::vector<int> > map;
std::vector<int> vect;
size_t res = 0;

void add_middle_to_res()
{
    res += *(vect.begin() + vect.size() / 2);
    //std::cout << "adding " << *(vect.begin() + vect.size() / 2) << std::endl;
}

void validate_vector()
{
    int idx = 0;
    bool valid = true;
    while (idx < vect.size())
    {
        std::vector<int> should_be_after = map[vect[idx]];
        int idx2 = 0;
        while (idx2 < should_be_after.size())
        {
            if (std::find(vect.begin(), vect.begin() + idx, should_be_after[idx2]) < vect.begin() + idx)
                valid = false;
            idx2++;
        }
        idx++;
    }
    if (valid)
        add_middle_to_res();
    vect.clear();
}

int main(void)
{
    std::ifstream file("input.txt");
    std::string line;
    int first, second = 0;
    std::getline(file, line);
    while (!line.empty())
    {
        std::stringstream stream(line);
        int first, second;
        char pipe;
        stream >> first;
        stream >> pipe;
        stream >> second;
        map[first].push_back(second);
        std::getline(file, line);
    }
    while (std::getline(file, line))
    {
        std::stringstream stream(line);
        int num;
        char comma;
        while (!stream.eof())
        {
            stream >> num;
            vect.push_back(num);
            stream >> comma;
        }
        validate_vector();
    }
    std::cout << res << std::endl;
}