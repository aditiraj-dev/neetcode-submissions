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
        int length = 0;
        ListNode* temp = head;
        while(temp)
        {
            length++;
            temp = temp->next;
        }

        cout << length;

        //traverse length - n nodes

        if(length - n == 0) return head->next;

        temp = head;
        int ctr = 0;

        while(temp)
        {
            ctr++;
            if(ctr == length - n)
            {
                ListNode* next = temp->next;
                temp->next = next->next;
                break;
            }

            temp = temp->next;
        }

        return head;
    }
};
