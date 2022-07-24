class Solution {
public:
    /*
    
    
    arr    = [1,   2,  4,  3,  1,  3,  3,  3,  3]
    temp   = [-1, -1, -1, +1, -1, +1, +1, +1, +1]
    
    
    For all the elements which are majorityElement I will set temp[i] = +1
    
    For all the elements which are majorityElement I will set temp[i] = -1
    
    majorityElement = 3
    3 is repeating more than n / 2 times.
    
    */
    
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = -1;
        
        for(int i : nums){
            if(count == 0)
                candidate = i;
            count += (i == candidate) ? +1 : -1;
        }
        
        return candidate;
    }
};