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
    int getDecimalValue(ListNode* head) {
        vector<int> a;
        while(head != NULL){
            for(int & i : a)
                i *= 2;
            if(head->val)
                a.push_back(1);
            head = head->next;
        }
        return accumulate(a.begin(), a.end(), 0);
    }
};