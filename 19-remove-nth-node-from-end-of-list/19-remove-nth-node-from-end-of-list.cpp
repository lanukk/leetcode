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
        ListNode* end = head;
        while(n--)
            end = end->next;
        
        ListNode*prev = NULL;
        ListNode*curr = head;
        
        while(end != NULL){
            prev = curr;
            curr = curr->next;
            end = end->next;
        }
        if(prev == NULL)
            return head->next;
        
        if(curr->next == NULL){
            prev->next = NULL;
            return head;
        }
        prev->next = curr->next;
        
        return head;
    }
};