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
    ListNode* newHead;
    ListNode* reverse(ListNode*head){
        if(head->next == NULL){
            newHead = head;
            return head;
        }
        ListNode* result = reverse(head->next);
        
        result->next = head;
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        
        ListNode *newTail;
        newTail = reverse(head);
        newTail->next = NULL;
    
        
        return newHead;
    }
};