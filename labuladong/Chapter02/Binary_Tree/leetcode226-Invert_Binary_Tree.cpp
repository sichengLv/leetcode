#include<bits/stdc++.h>
using namespace std;

/**
 * @brief  翻转一棵二叉树
 * @author sichengLv
 * @date   2021年3月7日20:49:03
 */

// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    // 前序遍历
    TreeNode* invertTree(TreeNode* root) {
        // 1.处理边界
        if (NULL == root) {
            return NULL;
        }
        // 2.交换左右节点指针(即交换左右子树)
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        // 3.递归的去翻转子节点
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }


    // 后序遍历
    TreeNode* invertTree2(TreeNode* root) {
        // 1.处理边界
        if (NULL == root) {
            return NULL;
        }
        // 3.递归的去翻转子节点
        invertTree(root->left);
        invertTree(root->right);
        // 2.交换左右节点指针(即交换左右子树)
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        return root;
    }
};


int main() {
    cout << "leetcode226-Invert_Binary_Tree" << endl;
    system("pause");
    
    return 0;
}
