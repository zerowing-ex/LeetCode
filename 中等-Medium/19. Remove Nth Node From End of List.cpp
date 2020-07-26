/*
19. 删除链表的倒数第N个节点
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/
/*
19. Remove Nth Node From End of List
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto slow = head;
        auto fast = head;
        for(int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }
        auto pre = head;
        while(fast != nullptr)
        {
            if(pre != slow)
                pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if(slow == head)
        {
            auto tmp = head->next;
            delete head;
            head = tmp;
        }
        else
        {
            pre->next = slow->next;
            delete slow; slow = nullptr;
        }
        
        return head;
    }
};