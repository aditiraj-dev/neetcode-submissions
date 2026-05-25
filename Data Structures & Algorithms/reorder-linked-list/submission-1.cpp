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
        //first to find mid

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //do reverse after slow, also unlinked slow and slow->next nodes
        ListNode* curr = slow->next;
        ListNode* prev = slow->next = nullptr;

        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        //now merge nodes at head and prev
        ListNode* list1 = head;
        ListNode* list2 = prev;
        while(list2)
        {
            ListNode* t1 = list1->next;
            ListNode* t2 = list2->next;

            list1->next = list2;
            list2->next = t1;
            list1 = t1;
            list2 = t2;
        }
    }
};
