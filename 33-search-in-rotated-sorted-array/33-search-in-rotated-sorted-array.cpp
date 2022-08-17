class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            
            //if target and mid present in the first part
            if(nums[mid] >= nums[0] && target >= nums[0]){
                if(nums[mid] > target){
                    r = mid - 1;
                    continue;
                } else if(nums[mid] < target) {
                    l = mid + 1;
                    continue;
                } else {
                    return mid;
                }
            } //if target and mid are present in the second
            else if (nums[mid] < nums[0] && target < nums[0]){
                if(nums[mid] > target){
                    r = mid - 1;
                    continue;
                } else if(nums[mid] < target) {
                    l = mid + 1;
                    continue;
                } else {
                    return mid;
                }
            } //if mid is present in first half and target is in the second half
            else if(nums[mid] >= nums[0] && target < nums[0]){
                l = mid + 1;
                continue;
            } //if mid is present in second half and target is in the first half
            else if(nums[mid] < nums[0] && target >= nums[0]){
                r = mid - 1;
                continue;
            }
        }
        
        return -1;
    }
};