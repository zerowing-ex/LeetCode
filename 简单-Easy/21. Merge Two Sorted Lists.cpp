/*
21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/
/*
21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        ListNode * res = new ListNode;
        ListNode * tmp = res;
        auto cur1 = l1, cur2 = l2;
        bool tag = false;
        while(cur1 != nullptr && cur2 != nullptr)
        {
            if(cur1->val <= cur2->val)
            {
                tmp->next = new ListNode(cur1->val);
                tmp = tmp->next;
                cur1 = cur1->next;
            }
            else
            {
                tmp->next = new ListNode(cur2->val);
                tmp = tmp->next;
                cur2 = cur2->next;
            }
        }
        while(cur1 != nullptr)
        {
            ListNode* newNode = new ListNode(cur1->val);
            tmp->next = newNode;
            tmp = newNode;
            cur1 = cur1->next;
        }
        while(cur2 != nullptr)
        {
            ListNode* newNode = new ListNode(cur2->val);
            tmp->next = newNode;
            tmp = newNode;
            cur2 = cur2->next;
        }
        auto head = res->next;
        delete res;
        return head;
    }
};