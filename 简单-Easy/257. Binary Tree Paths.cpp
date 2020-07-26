/*
257. 二叉树的所有路径
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
*/
/*
257. Binary Tree Paths
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(res, "", root);
        return res;
    }
    void dfs(vector<string>& res, string path, TreeNode * root)
    {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr)
        {
            path += to_string(root->val);
            res.push_back(path);
            return;
        }
        path += to_string(root->val) + "->";
        if (root->left != nullptr)
            dfs(res, path, root->left);
        if (root->right != nullptr)
            dfs(res, path, root->right);
    }
};