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

struct comp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for(ListNode* node: lists){
            if(node != NULL)
                pq.push(node);
        }
        ListNode* head = new ListNode();
        ListNode* temp = head;
        
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            if(node == NULL)continue;
            temp->next = node;
            temp = node;
            if(node->next != NULL)
                pq.push(node->next);            
        }
        
        return head->next;
    }
};