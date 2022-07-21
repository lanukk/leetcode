class Solution {
public:
    
    /*
    
    M:
    1 2 3
    4 5 6
    7 8 9
    
    Transpose(M):
    1 4 7
    2 5 8
    3 6 9
    
    Mirror(Transpose(M)):
    
    7 4 1
    8 5 2
    9 6 3
    
    90degree Rotation!
    
    
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    
    1 5 8 13
    2 6 10 14
    3 7 11 15
    4 8 12 16
    
    13 8 5 1
    14 10 6 2
    15 11 7 3
    16 12 8 4
    
    */
    
    void rotate(vector<vector<int>>& a) {
        
        int n = (int)a.size();
        
        //Transpose
        for(int i = 0; i < n; i++){
            int j = i + 1;
            int k = i + 1;
            while(j < n && k < n){
                swap(a[j][i], a[i][k]);
                j++;
                k++;
            }
        }
        
        //Mirror
        
        for(int i = 0; i < n; i++){
            int j = 0;
            int k = n - 1;
            while(j < k){
                swap(a[i][j], a[i][k]);
                j++;
                k--;
            }
        }
        
        
        
        
        
        
    }
};