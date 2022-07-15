class Solution {
public:
    
    bool dfs(int v, vector<vector<int>> & adj, vector<int> & color){
        color[v] = 1;
        bool ans = true;
        for(int u : adj[v]){
            if(color[u] == 0){
                ans = (ans & dfs(u, adj, color));
            } else if(color[u] == 1){
                ans = false;
            }
        }
        color[v] = 2;
        
        return ans;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto x : prerequisites)
            adj[x[1]].push_back(x[0]);
        
        vector<int> color(numCourses);
        bool ans = true;
        for(int i = 0; i < numCourses; i++){
            if(color[i] == 0){
                ans = (ans & dfs(i, adj, color));
            }
        }
        
        return ans;
    }
};