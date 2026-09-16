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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;

        priority_queue<pair<int,ListNode*>,  vector<pair<int,ListNode*>>,
            greater<pair<int,ListNode*>> > pq;

        int k = lists.size();

        for(int i=0;i<k;i++){

            if(lists[i]){
                pq.push({lists[i]->val,lists[i]});
            }

        }

        while(pq.size()>0){

            ListNode* node = pq.top().second;
            pq.pop();

            res->next = node;
            res=node;

            if(node->next) pq.push({node->next->val,node->next});
        }

        return dummy->next;
    }
};
