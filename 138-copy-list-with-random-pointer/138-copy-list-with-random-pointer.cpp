/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*
O-> original
N-> new

7->13->11->10->1->null
O->O->O->O->O->null

7->7->13->13->11->11->10->10->1->1->null
O->N->O->N->O->N->O->N->O->N->null


O -> N -> O -> N -> O .....
1    2    3    4    5


randompointer of node 1 is pointing to node 3

point random pointer of node 2 to the next node of the random-pointed node by node 1.

node 2 ----> node 4 throught(node 3)

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        
        while(temp != NULL){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            
            temp->next = newNode;
            
            temp = temp->next->next;
        }
        

        Node* node=head;
while(node){
	if(node->random)
		node->next->random=node->random->next;
	node=node->next->next; // go to next old node
}  
        
  Node* ans=new Node(0); // first node is a dummy node
Node* helper=ans;

while(head){
	// Copy the alternate added nodes from the old linklist
	helper->next=head->next;
	helper=helper->next;

	// Restoring the old linklist, by removing the alternative newly added nodes
	head->next=head->next->next;
	head=head->next; // go to next alternate node   
}
return ans->next; // Since first node is a dummy node
    }
};