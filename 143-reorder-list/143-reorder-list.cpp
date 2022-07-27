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
        stack<ListNode*> st;
        ListNode* slow = head, *fast = head;
        char c = '?';
        
        while(1){
            if(fast->next == NULL){
                c = 'o';
                break;
            }
            if(fast->next->next == NULL){
                c = 'e';
                break;
            }
            st.push(slow);
            slow = slow -> next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;
        ListNode* prev = slow;
        
        if(c == 'e')
            slow = slow->next->next;
        else
            slow = slow->next;
        // if(c == 'e')
        //     prev = prev->next;
        
        // prev->next = NULL;
        
        while(!st.empty()){
            st.top()->next = slow;
            // cout<<st.top()->val<<"\n";
            ListNode* temp = slow;
            slow = slow->next;
            temp->next = prev;
            cout<<prev->val<<"\n";
            prev = st.top();
            st.pop();
        }
        
        if(c == 'o')
            mid->next = NULL;
        else
            mid->next->next = NULL;
        
        // return head;        
    }
};