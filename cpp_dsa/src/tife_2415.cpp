//
//  tife_2415.cpp
//  first_cli
//
//  Created by Boluwatife Onifade on 20/12/2024.
// Reverse Odd levels of Binary Tree
// Link - https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/
//
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include "tife_solution.h"

namespace tife {
namespace leetcode {
namespace {
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right):
    val(x),
    left(left),
    right(right) {}
};


TreeNode* generateTreeNode(const std::vector<int>& list, int index){
    TreeNode* root = nullptr;
    if(list.size() > index){
        root = new TreeNode(list[index]);
        root->left = generateTreeNode(list, (index * 2) + 1);
        root->right = generateTreeNode(list, (index * 2) + 2);
    }
    return root;
}

void generateVectorFromTreeNode(const TreeNode* node, std::vector<int>& list, int index){
    list[index] = node->val;
    if(node->left){
        generateVectorFromTreeNode(node->left, list, (index * 2) + 1);
    }
    if(node->right)
    {
        generateVectorFromTreeNode(node->right, list, (index * 2) + 2);
    }
}

}

class Solution2415: public Solution {
    void dfs(std::unordered_map<int, std::vector<TreeNode*>>& levelMap, TreeNode* node, int levelIndex){
        if((levelIndex % 2) == 1)
        {
            levelMap[levelIndex].push_back(node);
        }
        if(node->left)
        {
            dfs(levelMap, node->left, levelIndex+1);
        }
        if(node->right)
        {
            dfs(levelMap, node->right, levelIndex+1);
        }
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
            std::unordered_map<int, std::vector<TreeNode*>> levelMap;
            if(root) dfs(levelMap, root, 0);
            for(const auto& [key, value]: levelMap)
            {
                size_t p1 = 0;
                size_t p2 = value.size() - 1;
                while(p1 < p2)
                {
                    int temp = value[p1]->val;
                    value[p1]->val = value[p2]->val;
                    value[p2]->val = temp;
                    ++p1;
                    --p2;
                }
            }
            return root;
    }
    
    
    
    void run() override {
        std::vector<int> input = {2,3,5,8,13,21,34};
        std::vector<int> expected_result = {2,5,3,8,13,21,34};
        TreeNode* input_tree = generateTreeNode(input, 0);
        TreeNode* reversed_tree = reverseOddLevels(input_tree);
        std::vector<int> reversed_result(input.size(), 0);
        generateVectorFromTreeNode(reversed_tree, reversed_result, 0);
        assert(expected_result == reversed_result);
    }
};

}
}
