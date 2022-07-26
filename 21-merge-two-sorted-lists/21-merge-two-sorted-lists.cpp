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
    
    ListNode* merge(ListNode* list1, ListNode* list2){
        if(list1 == NULL && list2 == NULL)
            return NULL;
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        
        if(list2->val < list1->val)
            swap(list1, list2);
        
        list1->next = merge(list1->next, list2);
        
        return list1;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1, list2);
    }
};