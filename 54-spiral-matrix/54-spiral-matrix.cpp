class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int>ans;
        int n = (int)a.size();
        int m = (int)a[0].size();
        
        int colRightLimit = m, colLeftLimit = -1, rowUpLimit = -1, rowDownLimit = n;
        int x = n * m;
        cout<<colRightLimit<<"\n\n";
        while(1){
            int i = rowUpLimit + 1;
            int j = colLeftLimit + 1;

            
            while(j != colRightLimit){
                cout<<i<<" "<<j<<"\n";
                ans.push_back(a[i][j]);
                x--;
                cout<<a[i][j]<<"\n";
                j++;
            }
            if(x == 0)break;
            j--;
            rowUpLimit++;
            
            i = rowUpLimit + 1;
            
            while(i != rowDownLimit){
                ans.push_back(a[i][j]);x--;
                i++;
            }
            if(x == 0)break;
            i--;
            colRightLimit--;
            // 
            
            j = colRightLimit - 1;
            
            while(j != colLeftLimit){
                ans.push_back(a[i][j]);x--;
                j--;
            }
            if(x == 0)break;
            j++;
            
            rowDownLimit--;
            
            i = rowDownLimit - 1;
            
            while(i != rowUpLimit){cout<<"?";
                ans.push_back(a[i][j]);x--;
                i--;
            }
            if(x == 0)break;
            i++;
            colLeftLimit++;
            // break;
        }
        
        return ans;
        
    }
};