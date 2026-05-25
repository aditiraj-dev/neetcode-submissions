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
        ListNode* curr = head;

        while(curr->next->next && curr->next)
        {
            ListNode* end = curr;
            while(end->next) 
            {
                if(end->next->next == nullptr)
                {
                    ListNode* temp = end;
                    end = end->next;
                    temp->next = nullptr;
                    break;
                }
                end = end->next;
            }
            end->next = curr->next;
            curr->next = end;

            curr = curr->next->next;
        }

        return;
    }
};
