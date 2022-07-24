class Solution {
public:
    /*
    
    
    
    */
    
    int majorityElement(vector<int>& nums) {
        int n = (int)nums.size();
        
        int bit[32] = {0};
        for(int i : nums){
            for(int j = 0; j < 32; j++){
                if(i & (1 << j)){
                    bit[j] += 1;
                }
            }
        }
        
        
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(bit[i] > n / 2){
                //this bit will be set in our answer definately
                ans = (ans | (1 << i));
            }
        }
        
        return ans;        
    }
};