class Solution {
public:
    
    
    /*
    
    sort(a, a + n);
    count 
    
    low, mid and high
    
    low  -> 0th index
    mid  -> 0th index
    high -> (n - 1)th index
    
    0 0 in prefix and 2's in prefix and predicting that 1's will be at correct position as by product of using this algorithm.
    
    till mid < high
    arr[mid] == 0:
        swap(arr[low], arr[mid]);
        low ++;
        mid++;
    arr[mid] == 1:
        mid++;
    arr[mid] == 2:
        swap(arr[high], arr[mid]);
        
    */
    
    void sortColors(vector<int>& nums) {
        int n = (int)nums.size();
        int low = 0, mid = 0, high = n - 1;
        
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else if(nums[mid] == 1){
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
                
    }
};