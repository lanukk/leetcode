class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        
        vector<bool> r(n, false), c(m, false);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    r[i] = true;
                    c[j] = true;
                }
            }
        }
        
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(r[i] == true || c[j] == true){
                    matrix[i][j] = 0;
                }
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }       
    
        
    }
};