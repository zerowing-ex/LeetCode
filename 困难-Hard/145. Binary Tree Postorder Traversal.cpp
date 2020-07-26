/*
145. 二叉树的后序遍历
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/
/*
145. Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
struct StackUnit{
public:
    TreeNode* ptr;
    bool dir;
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* current) {
        vector<int> res;
        stack<StackUnit> s;
	    StackUnit n;
	    do {
		    while (current != nullptr)
            {
			    n.ptr = current;
			    n.dir = 0;
			    s.push(n);
			    current = current->left;
		    }
		    int cnt = 1;
		    while (cnt && !s.empty())
            {
			    n = s.top(), s.pop();
                current = n.ptr;
			    switch (n.dir)
                {
			    case 0:
				    n.dir = 1; s.push(n);
				    cnt = false;
				    current = current->right;
				    break;
			    case 1:
				    res.push_back(current->val);
                    break;
			    }
		    }
	    } while (!s.empty());
        return res;
    }
};