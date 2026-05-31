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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;

        ListNode* temp = head;
        int x = 0;
        while(temp)
        {
            x++;
            if(x==k) break;
            temp = temp->next;
        }

        if(x < k) return head;

        ListNode* l2 = temp->next;
        temp->next = nullptr;

        ListNode* l1 = head;
        l1 = reverseList(l1);
        l2 = reverseKGroup(l2, k);

        if(!l2) return l1;

        temp = l1;
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = l2;

        return l1;
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
