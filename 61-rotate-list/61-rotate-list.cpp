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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)return NULL;
        map<int, ListNode*> mp;
        int d = 0;
        ListNode*temp = head;
        
        while(temp != NULL){
            mp[d] = temp;
            d++;
            temp = temp->next;
        }
        
        k = k % d;
        if(k == 0)
            return head;
        
        mp[d - k - 1]->next = NULL;
        mp[d - 1]->next = head;
        return mp[d - k];        
    }
};