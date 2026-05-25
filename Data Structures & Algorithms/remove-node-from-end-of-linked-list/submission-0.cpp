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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int N = 1;

        while(temp->next) {
            temp = temp->next;
            N++;
        }

        temp = head;
        if(N == n)
        {
            head = head->next;
        }
        else
        {
            N = N - n - 1;
            while(temp->next && N)
            {
                temp = temp->next;
                N--;
            }

            temp->next = temp->next->next;
        }

        return head;
    }
};
