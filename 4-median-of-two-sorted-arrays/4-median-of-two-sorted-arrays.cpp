class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);
        int n = (int)nums1.size();
        int m = (int)nums2.size();
        
        int l = 0, r = n;
        int middle_position = ((n + m - 1)/2) + 1;
        while(l <= r){
            int mid = (l + r) / 2;
            
            int p11 = (mid - 1) >= 0? nums1[mid - 1] : INT_MIN;
            int p12 = (mid) < n ? nums1[mid] : INT_MAX;
            
            int p21 = (middle_position - mid - 1) >= 0? nums2[middle_position - mid - 1]: INT_MIN;
            int p22 = (middle_position - mid) < m? nums2[middle_position - mid] : INT_MAX;
            
            //validate partitions
            
            if(max(p11, p21) <= min(p12, p22)){
                if((n + m) % 2 == 0)
                    return (max(p11, p21) + min(p12, p22))/2.0;
                
                return max(p11, p21);
            }
            
            //updating pointers
            if(max(p11, p21) == p11){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return 0;
    }
};