/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    void retainOriginal(ListNode* head){
        while(head != nullptr){
            head->val = abs(head->val);
            head = head->next;
        }
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* i = headA;
        while(i != nullptr){
            i->val =  -1 * (i -> val);
            i = i->next;
        }
        
        ListNode*culprit, *j = headB;
        
        while(j != nullptr){
            if(j->val < 0){
                culprit = j;
                break;
            }
            j = j->next;
        }
        retainOriginal(headA);
        retainOriginal(headB);
        
        return culprit;        
    }
};