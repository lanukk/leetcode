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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val)
            head = head->next;
        
        if(head == nullptr)
            return head;
        
        ListNode* curr = head;
        while(curr && curr->next){
            ListNode*traverse = curr->next;
            while(traverse && traverse->val == val)
                traverse = traverse->next;
            
            curr->next = traverse;
            curr = traverse;
        }
        
        return head;                
    }
};