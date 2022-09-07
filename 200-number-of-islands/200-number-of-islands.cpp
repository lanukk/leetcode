class Solution {
    vector<vector<bool>>visited;
public:
    
    void dfs(int i, int j, int &n, int &m, vector<vector<char>> & grid){
        visited[i][j] = true;
        if(i + 1 < n && grid[i + 1][j] == '1' && visited[i + 1][j] == false)
            dfs(i + 1, j, n, m, grid);
        if(i - 1 >= 0 && grid[i - 1][j] == '1' && visited[i - 1][j] == false)
            dfs(i - 1, j, n, m, grid);
        if(j + 1 < m && grid[i][j + 1] == '1' && visited[i][j + 1] == false)
            dfs(i, j + 1, n, m, grid);
        if(j - 1 >= 0 && grid[i][j - 1] == '1' && visited[i][j - 1] == false)
            dfs(i, j - 1, n, m, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        
        visited.assign(n, vector<bool>(m, false));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    dfs(i, j, n, m, grid);
                    ans ++;
                }
            }
        }
        
        return ans;
    }
};