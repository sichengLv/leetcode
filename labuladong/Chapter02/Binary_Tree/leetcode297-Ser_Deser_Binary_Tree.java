package Chapter02.Binary_Tree;

import java.util.LinkedList;

/**
 * @author sichengLv
 * @brief 297. Serialize and Deserialize Binary Tree
 * 二叉树的序列化与反序列化
 * @date 2021年3月15日23:16:34
 */


public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serialize(root, sb);
        return sb.toString();
    }

    /**
     * 辅助函数, 将二叉树序列化为string
     */
    private void serialize(TreeNode root, StringBuilder sb) {
        // 遇到空指针,则返回#
        // 后面加个逗号,用来做标记
        if (root == null) {
            sb.append("#").append(",");
            return;
        }
        // 前序遍历
        sb.append(root.val).append(",");
        // 递归序列化左右子树
        serialize(root.left, sb);
        serialize(root.right, sb);
    }

    // Decodes your encoded data to tree.
    /**
     * 反序列化时,这里需要借助一个辅助的数据结构:LinkedList<String>
     */
    public TreeNode deserialize(String data) {
        if (data.isEmpty()) {
            return null;
        }
        LinkedList<String> nodes = new LinkedList<>();
        for (String s : data.split(",")) {
            nodes.addLast(s);
        }
        return deserialize(nodes);
    }

    private TreeNode deserialize(LinkedList<String> nodes) {
        if (nodes.isEmpty()) {
            return null;
        }
        /****** 前序遍历位置 ******/
        // 读取root节点并删除,这一步是关键;保证向下递归时,条件是满足的.
        String first = nodes.removeFirst();
        // 字符串比较要用equals方法
        if (first.equals("#")) {
            return null;
        }
        TreeNode root = new TreeNode(Integer.valueOf(first));
        root.left = deserialize(nodes);
        root.right = deserialize(nodes);
        return root;
    }


}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
