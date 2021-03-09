#include<bits/stdc++.h>
#include "treenode.h"
using namespace std;

/**
 * @brief  654. Maximum Binary Tree
 *         构造最大二叉树
 * @author 吕思诚
 * @date   2021年3月9日21:58:53
 */

class Solution {
public:
    /**
     * @brief 思路
     *      1.首先构造根节点
     *      2.然后递归构造左右子树
     * 
     * PS: 参数不够用,需要另外构造一个方法
     * @param nums          [3,2,1,6,0,5]
     * @return TreeNode*    root
     */
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // 注意数组长度
        return build(nums, 0, (nums.size() - 1));
    }

    /**
     * @brief 参数不够用,需要另外构造一个方法
     * 
     */
    TreeNode* build(vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }

        // 构造根节点: 遍历数组,找到最大值
        int index = start;  // 这里不要写成-1了
        for (int i = start; i <= end ; i++) {
            if (nums[i] > nums[index]) {
                index = i;
            }
        }
        TreeNode* root = new TreeNode(nums[index]);
        // 递归构造左右子树
        root->left = build(nums, start, index - 1);
        root->right = build(nums, index + 1, end);

        return root;
    }
};

