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
            temp = temp->next;
        }

        if(x < k) return head;
        else {
            x = 0;
            temp = head;
        }

        while(temp)
        {
            x++;
            if(x == k) break;
            temp = temp->next;
        }

        ListNode* rest = temp->next;
        temp->next = nullptr;

        ListNode* l1 = reverseList(head);
        ListNode* l2 = reverseKGroup(rest, k);

        temp = l1;

        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = l2;

        return l1;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

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
