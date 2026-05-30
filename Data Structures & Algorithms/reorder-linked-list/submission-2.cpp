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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l2 = slow->next;
        slow->next = nullptr;

        l2 = reverseList(l2);
        ListNode* l1= head;
        while(l2)
        {
            ListNode* t1 = l1->next;
            ListNode* t2 = l2->next;

            l1->next = l2;
            l2->next = t1;

            l1 = t1;
            l2 = t2;
        }
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};
