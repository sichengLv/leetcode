#include<bits/stdc++.h>
#include "treenode.h"
using namespace std;

/**
 * @brief  105. Construct Binary Tree from Preorder and Inorder Traversal
 *         通过前序和中序遍历结果构造二叉树
 * @author sichengLv
 * @date   2021年3月10日23:11:08
 */

class Solution {
public:
    /**
     * @brief 关键点: 找到root节点
     * 
     * @param preorder      [3,9,20,15,7]
     * @param inorder       [9,3,15,20,7]
     * @return TreeNode* 
     */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, (preorder.size() - 1), inorder, 0, (inorder.size() - 1));
    }

    /**
     * @brief 
     */
    TreeNode* build(vector<int>& preorder, int pre_start, int pre_end, 
                        vector<int>& inorder, int in_start, int in_end) {
        // base case
        if (pre_start > pre_end) {
            return NULL;
        }
        // 得到头节点:preorder第一个节点即为root节点
        int val = preorder[pre_start];
        int index = -1;
        int i = 0;
        // 在inorder搜寻root节点的位置
        for (i = in_start; i <= in_end; i++) {
            if (inorder[i] == val) {
                index = i;
                break;
            }
        }
        // 以防万一
        if (i > in_end) {
            return NULL;
        }
        // 计算左子树长度(这一步很容易出错)
        int left_size = index - in_start;
        // 构造root节点
        TreeNode* root = new TreeNode(val);
        // 递归构造左右子树
        // 这里特别注意,左右子树的传参,加起来一定要是对应的
        root->left = build(preorder, pre_start + 1, pre_start + left_size,
                           inorder, in_start, in_start + left_size - 1);
        root->right = build(preorder, pre_start + left_size + 1, pre_end,
                            inorder, in_start + left_size + 1, in_end);
        return root;
    }

};

