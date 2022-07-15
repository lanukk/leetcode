class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto x : prerequisites)
            adj[x[1]].push_back(x[0]);
        
        vector<int> inDegree(numCourses);
        for(int i = 0; i < numCourses; i++){
            for(int v : adj[i])
                inDegree[v]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            numCourses--;
            q.pop();
            
            for(int i : adj[u]){
                inDegree[i]--;
                if(inDegree[i] == 0){
                    q.push(i);
                }
            }
        }
        
        return numCourses == 0;        
    }
};