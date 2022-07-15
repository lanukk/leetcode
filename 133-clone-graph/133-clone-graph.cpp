/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        map<int, Node*> mp;
        map<int, bool> visited;
        Node* root = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        visited[node->val] = 1;
        mp[root->val] = root;
        
        while(!q.empty()){
            Node* f = q.front();
            q.pop();
            
            for(Node* v : f->neighbors){
                if(mp.find(v->val) == mp.end()){
                    Node* n = new Node(v->val);
                    mp[n->val] = n;
                }
                Node* temp = mp[f->val];
                temp->neighbors.push_back(mp[v->val]);
                if(visited[v->val] == 0){
                    visited[v->val] = 1;
                    q.push(v);
                }
            }
        }
        return root;
    }
};