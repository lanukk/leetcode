class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = (int)nums.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            
            if(mid % 2 == 0){
                //check whether the element is in the first part
                if(mid + 1 < n && nums[mid] == nums[mid + 1]){
                    l = mid + 1;
                    continue;
                } //check whether the element is in the second part
                else if(mid - 1 >= 0 && nums[mid] == nums[mid - 1]){
                    r = mid - 1;
                    continue;
                } //we can say that the element is unique for sure here
                else {
                    return nums[mid];
                }
            } else {
                //check whether the element is in the first part
                if(mid - 1 >= 0 && nums[mid] == nums[mid - 1]){
                    l = mid + 1;
                    continue;
                } // check whether the element is in the second part
                else if(mid + 1 < n && nums[mid] == nums[mid + 1]){
                    r = mid - 1;
                    continue;
                } else { //surely the element is unique
                    return nums[mid];
                }
            }
        }
        return - 1;
    }
};