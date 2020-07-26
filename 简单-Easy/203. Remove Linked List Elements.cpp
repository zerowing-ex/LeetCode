/*
203. 移除链表元素
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/
/*
203. Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        auto first = new ListNode(0);
        first->next = head;
        auto cur = head; auto pre = first;
        while (cur != nullptr)
        {
            if (cur->val == val)
            {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            else
            {
                pre = cur;
                cur = cur->next; 
            }
        }
        head = first->next;
        delete first;
        return head;
    }
};