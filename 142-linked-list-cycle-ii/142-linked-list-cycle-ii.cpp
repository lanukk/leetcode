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
    ListNode *detectCycle(ListNode *head) {
        if(!head)return head;
        
        ListNode* slow = head, *fast = head;
        
        do{
            if(slow->next == NULL || fast->next == NULL || fast->next->next == NULL)
                return nullptr;
            
            slow = slow->next;
            fast = fast->next->next;
        }while(slow != fast);
        
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow;
    }
};