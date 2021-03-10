#include<bits/stdc++.h>
using namespace std;

/**
 * @brief  116. Populating Next Right Pointers in Each Node
 * 填充每个节点的下一个右侧节点指针
 * @author sichengLv
 * @date   2021年3月7日21:33:26
 */


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (NULL == root) return NULL;
        connectTwoNode(root->left, root->right);
        return root;
    }

    /**
     * @brief 这里必须要定义两个节点,因为跨父节点的连接无法通过递归来实现
     * 
     */
    void connectTwoNode(Node* p1, Node* p2) {
        if (NULL == p1 || NULL == p2) {
            return;
        }
        // 将传入的两个节点连接
        p1->next = p2;

        // 递归地连接剩余节点

        // 连接相同父节点的两个子节点
        connectTwoNode(p1->left, p1->right);
        connectTwoNode(p2->left, p2->right);
        // 连接跨父节点的两个相邻节点
        connectTwoNode(p1->right, p2->left);
    }
};

