class Solution {
public:
    /*
    
    Q...
    ...Q
    ..Q.
    ....
    
    1. no queen in the same column
    2. no queen in the upper right diagonal to the cell
    3. no queen in the upper left diagonal to the cell
    
    */
    
    vector<vector<string>> ans;
    
    bool check(int i, int j, vector<string> &configuration){
        int ti = i;
        
        while(ti >= 0){
            if(configuration[ti][j] == 'Q'){
                return false;
            }
            ti--;
        }
        ti = i;
        int tj = j;
        
        while(ti >= 0 && tj < (int)configuration.size()){
            if(configuration[ti][tj] == 'Q'){
                return false;
            }
            ti--;
            tj++;
        }
        
        ti = i;
        tj = j;
        
        while(ti >=0 && tj >= 0){
            if(configuration[ti][tj] == 'Q'){
                return false;
            }
            ti--;
            tj--;
        }
        return true;        
    }
    
    
    void recursion(int i, vector<string> configuration){
        if(i == (int)configuration.size()){
            ans.push_back(configuration);
            return;
        }
        
        for(int j = 0; j < (int)configuration.size(); j++){
            if(check(i, j, configuration)){
                configuration[i][j] = 'Q';
                recursion(i + 1, configuration);
                configuration[i][j] = '.';
            }
        }
        return;
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> configuration(n);
        for(int i = 0; i < n; i++){
            string t = "";
            for(int j = 0; j < n; j++)
                t += '.';
            configuration[i] = t;
        }
        recursion(0, configuration);
        return ans;
    }
};