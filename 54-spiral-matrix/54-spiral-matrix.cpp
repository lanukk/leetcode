class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int>ans;
        int n = (int)a.size();
        int m = (int)a[0].size();
        
        int colRightLimit = m, colLeftLimit = -1, rowUpLimit = -1, rowDownLimit = n;
        int x = n * m;
        while(1){
            int i = rowUpLimit + 1;
            int j = colLeftLimit + 1;

            
            while(j != colRightLimit){
                ans.push_back(a[i][j]);
                x--;
                j++;
            }
            
            j--;
            rowUpLimit++;
            
            if(!x)break;
                        
            i = rowUpLimit + 1;
            
            while(i != rowDownLimit){
                ans.push_back(a[i][j]);
                x--;
                i++;
            }
            
            i--;
            colRightLimit--;
            
            if(!x)break;
            
            j = colRightLimit - 1;
            
            while(j != colLeftLimit){
                ans.push_back(a[i][j]);
                x--;
                j--;
            }
            
            j++;
            
            rowDownLimit--;
            
            if(!x)break;
            
            i = rowDownLimit - 1;
            
            while(i != rowUpLimit){
                ans.push_back(a[i][j]);
                x--;
                i--;
            }
            
            i++;
            colLeftLimit++;
            
            if(!x)break;
        }
        
        return ans;
        
    }
};