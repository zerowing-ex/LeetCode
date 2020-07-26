/*
24. 两两交换链表中的节点
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
*/
/*
24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        auto pre = head; bool tag = false;
        for (auto cur = head; cur != nullptr && cur->next != nullptr; cur = cur->next, tag = !tag)
        {
            if (!tag && pre != head)
            {
                auto tmp = cur->next;
                pre->next = tmp;
                cur->next = tmp->next;
                tmp->next = cur;
                cur = tmp;
            }
            else if (!tag && pre == head)
            {
                auto tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = cur;
                cur = tmp;
                head = tmp;
            }
            pre = cur;
        }
        return head;
    }
};