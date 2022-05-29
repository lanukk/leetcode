class Solution {
public:
    
    int solve(vector<int>& a, bool equal){
        int ans = 0;
        int n = (int)a.size();
        
        for(int i = 0; i < n; i++){
            int j = i + 1;
            int sum = 0;
            
            while(j < n){
                if(a[i] < a[j])
                    break;
                if(a[i] == a[j] && equal)
                    break;
                j++;
            }
            if(j == n)
                break;
            if(j - i == 1)
                continue;
            
            for(int k = i + 1; k < j; k++)
                sum += a[k];
            
            // cout<<i<<" "<<j<<" "<<a[i]<<" "<<sum<<"\n";
            ans += (j - i - 1) * a[i] - sum;
            i = j - 1;
        }
        return ans;
    }
    
    int trap(vector<int>& height) {
        int ans = solve(height, 1);
        reverse(height.begin(), height.end());
        ans += solve(height, 0);
        
        return ans;
    }
};