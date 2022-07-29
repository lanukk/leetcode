class Solution {
public:
    
    int findSolve(vector<int> &a, bool equal){
        int n = (int) a.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int curr = a[i];
            int j = i + 1;
            int sum = 0;
            while(j < n){
                if(equal && a[i] == a[j])
                    break;
                if(a[i] < a[j])
                    break;
                sum += a[j];
                j++;
            }
            if(j == n)
                break;
            
            ans += (a[i] * (j - i - 1)) - sum;
            i = j - 1;
        }
        return ans;
    }
    
    int trap(vector<int>& height) {
        int ans = 0;
        
        ans = findSolve(height, 1);
        reverse(height.begin(), height.end());
        ans += findSolve(height, 0);
        
        return ans;        
    }
};