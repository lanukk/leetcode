class Solution {
public:
    
    int countWater(vector<int> & a, bool equal){
        int ans = 0;
        
        int index = 0;
        int sum = 0;
        
        for(int i = 1; i < (int)a.size(); i++){
            if(a[i] > a[index]){
                ans += (a[index] * (i - index - 1)) - sum;
                sum = 0;
                index= i;
            } else if(a[i] == a[index] && equal){
                ans += (a[index] * (i - index - 1)) - sum;
                sum = 0;
                index= i;
            } else {
                sum += a[i];
            }
        }
        return ans;
    }
    
    int trap(vector<int>& a) {
        int ans = 0;
        ans += countWater(a, true);
        cout<<ans<<"\n";
        reverse(a.begin(), a.end());
        ans += countWater(a, false);
        
        return ans;
    }
};