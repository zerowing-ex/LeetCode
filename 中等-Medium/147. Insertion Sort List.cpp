/*
147. 对链表进行插入排序
对链表进行插入排序。


插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

 

插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

输入: 4->2->1->3
输出: 1->2->3->4
示例 2：

输入: -1->5->3->4->0
输出: -1->0->3->4->5
*/
/*
147. Insertion Sort List
Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
			return head;
		//The first node sorted already
		ListNode* firstNode = head;
		//The last node sorted already
		ListNode* lastNode = head;
		//The next node needed to be sorted
		ListNode* nextNode = head->next;
		while (nextNode != nullptr)
		{
			if (nextNode->val >= lastNode->val)
			{
				lastNode = nextNode;
				nextNode = nextNode->next;
			}
			else if (nextNode->val <= firstNode->val)
			{
				auto tmp = nextNode;
				nextNode = nextNode->next;
				lastNode->next = nextNode;
				tmp->next = firstNode;
				firstNode = tmp;
			}
			else
			{
				auto tmp = nextNode;
				nextNode = nextNode->next;
				lastNode->next = nextNode;
				auto pre = firstNode;
				for (auto cur = firstNode; cur != lastNode->next; cur = cur->next)
				{
					if (tmp->val <= cur->val)
					{
						tmp->next = cur;
						pre->next = tmp;
						break;
					}
					if (cur != firstNode)
					{
						pre = pre->next;
					}
				}
			}
		}
		return firstNode;
    }
};