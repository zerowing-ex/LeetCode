/*
86. 分隔链表
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
*/
/*
86. Partition List
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) return head;
        queue<int> q1;
        queue<int> q2;
        ListNode * current = nullptr;
        for(current = head; current != nullptr; current = current->next)
        {
            if(current->val < x) q1.push(current->val);
            else q2.push(current->val);
        }
        int m = q1.size();
        int n = q2.size();
        current = head;
        for(int i = 0; i < m; ++i)
        {
            current->val = q1.front();
            q1.pop();
            current = current->next;
        }
        for(int i = 0; i < n; ++i)
        {
            current->val = q2.front();
            q2.pop();
            current = current->next;
        }
        return head;
    }
};