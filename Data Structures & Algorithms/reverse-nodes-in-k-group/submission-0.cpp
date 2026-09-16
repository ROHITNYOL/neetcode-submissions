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
        int count = k - 1;

        ListNode* temp = head;
        if (temp == NULL) return head;

        while (count != 0) {
            temp = temp->next;
            if (temp == NULL) return head;
            count--;
        }

        if (temp == NULL) return head;

        ListNode* nextPtr = reverseKGroup(temp->next,k);

        temp = head;
        ListNode* next;
        
        while(k>0){
            next = temp->next;
            temp->next = nextPtr;
            nextPtr = temp;
            temp=next;
            k--;
        }

        return nextPtr;
    }
};
