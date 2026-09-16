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
        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            temp = temp->next;
            count++;
        }

        if(count==1) return NULL;
        if(n==count) return head->next;

        int k = count - n;

        temp = head;
        for (int i = 0; i < k - 1; i++) {
            temp = temp->next;
        }

        if (temp->next) temp->next = temp->next->next;

        return head;
    }
};
