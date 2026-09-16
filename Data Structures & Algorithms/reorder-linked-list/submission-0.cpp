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
        
        // find middle element
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){

            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow->next;
        slow->next = NULL;

        // reverse list

        ListNode* prev = NULL;
        ListNode* curr = temp;
        ListNode* next = NULL;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // now head of reversed list after middle elements is on prev

        ListNode* l1 = head;
        ListNode* r1 = head->next;
        ListNode* l2 = prev;
        ListNode* r2 = prev->next;

        while(l2!=NULL){

            l1->next = l2;
            l2->next = r1;
            l1=r1;
            r1=r1->next;
            l2=r2;
            r2=r2->next;
        }

    }
};
