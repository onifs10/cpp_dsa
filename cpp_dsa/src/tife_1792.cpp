//
//  tife_1792.cpp
//  first_cli
//
//  Created by Boluwatife Onifade on 15/12/2024.
//
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "tife_solution.h"



namespace tife {
namespace leetcode {

namespace {
double round_to(double value, double precision = 1.0)
{
    return std::round(value / precision) * precision;
}
}


class Solution1792: public Solution {
public:
    double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
        std::vector<std::pair<double, std::vector<int>>> passRatioToIndex;
        
        for(auto& v: classes){
            double increase = double(v[0]+1)/double(v[1]+1) - double(v[0])/double(v[1]);
            passRatioToIndex.push_back({increase, v});
        }
        
        std::make_heap(passRatioToIndex.begin(), passRatioToIndex.end(), [](auto& a, auto& b){
            return a.first < b.first;
        });
        
        for(int i = 0; i < extraStudents; ++i){
            // get class with max incr
            std::pop_heap(passRatioToIndex.begin(), passRatioToIndex.end(), [](auto& a, auto& b){
                return a.first < b.first;
            });
            auto max_inc = passRatioToIndex.back();
            passRatioToIndex.pop_back();

            // std::cout << max_inc.first << " " << max_inc.second[0] << " " << max_inc.second[1] << std::endl;
            // add the new pass student to max incr
            max_inc.second[0] += 1;
            max_inc.second[1] += 1;
            max_inc.first = double(max_inc.second[0]+1)/double(max_inc.second[1]+1) - double(max_inc.second[0])/double(max_inc.second[1]);

            // std::cout << max_inc.first << " " << max_inc.second[0] << " " << max_inc.second[1] << std::endl;
            passRatioToIndex.push_back(max_inc);

            // add new max incr to heap
            std::push_heap(passRatioToIndex.begin(), passRatioToIndex.end(), [](auto& a, auto& b){
                return a.first < b.first;
            });
        }
        double sum = 0;
        for(auto& v: passRatioToIndex){
//          std::cout << v.second[0] << " " << v.second[1] << std::endl;
            sum += double(v.second[0])/double(v.second[1]);
        }
        return sum / passRatioToIndex.size();
    }
    void run() override {
        std::vector<std::vector<int>> input = {{1,2},{3,5},{2,2}};
//        std::cout << (round_to(maxAverageRatio(input, 2), 0.0001)) << std::endl;
        assert((round_to(maxAverageRatio(input, 2), 0.0001)) == 0.7833);
    }
};

}
}
