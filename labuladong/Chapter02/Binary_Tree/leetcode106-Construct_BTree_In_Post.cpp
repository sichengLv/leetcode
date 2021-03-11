#include<bits/stdc++.h>
#include "treenode.h"
using namespace std;

/**
 * @brief  106. Construct Binary Tree from Inorder and Postorder Traversal
 *         通过后序和中序遍历结果构造二叉树
 * @author sichengLv
 * @date   2021年3月11日22:48:57
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    /**
     * @brief 关键点: 和前序+中序构造二叉树类似
     * 
     */
    TreeNode* build(vector<int>& inorder, int in_start, int in_end,
                    vector<int>& postorder, int post_start, int post_end) {
        // base case
        if (in_start > in_end) return NULL;

        // 构造root节点
        // postorder的最后一个节点即为root节点
        int val = postorder[post_end];
        TreeNode* root = new TreeNode(val);
        // 在inorder中找到root节点的位置
        int index = in_start;
        for (int i = in_start; i <= in_end; i++) {
            if (val == inorder[i]) {
                index = i;
                break;
            }
        }
        // 递归构造左右子树(左右子树谁先构造都OK)
        int right_size = in_end - index;        // 右子树的长度
        root->left = build(inorder, in_start, index - 1,
                            postorder, post_start, post_end - right_size - 1);
        root->right = build(inorder, index + 1, in_end,
                            postorder, post_end - right_size, post_end - 1);
        return root;
    }
};
