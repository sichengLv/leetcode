#include<bits/stdc++.h>
#include "treenode.h"
using namespace std;

/**
 * @brief  114. Flatten Binary Tree to Linked List
 *      将二叉树展开为链表
 * @author 吕思诚
 * @date   2021年3月8日22:59:02
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    // 后序遍历
    void flatten(TreeNode* root) {
        if (NULL == root) return;
        flatten(root->left);
        flatten(root->right);

        // 处理root节点
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        // 因为最终结果是以右指针为单链表的指针
        // 所以将左子树作为右子树
        root->right = left;
        root->left = NULL;
        // 将原来的右子树插入到当前右子树的末尾
        TreeNode* p = root;
        while (p->right != NULL) {
            p = p->right;
        }
        p->right = right;
    }
};

