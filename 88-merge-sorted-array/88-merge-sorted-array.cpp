class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        
        if(n == 0){
            int j = 0;
            for(int &i : nums1){
                i = nums2[j];
                j++;
            }
            return;
        } 
        
        if(m == 0)
            return;
        
        int i = n - 1;
        int j = m - 1;
        
        int k = n + m - 1;
        while(k >= 0 && i >= 0 && j >= 0){
            if(i >= 0 && j >= 0 && nums1[i] > nums2[j]){
                swap(nums1[i], nums1[k]);
                i--;
            } else {
                swap(nums2[j], nums1[k]);
                j--;
            }
            k--;
        }
        
        while(k >= 0 && j >= 0){
            swap(nums1[k], nums2[j]);
            j--;
            k--;
        }
        
    }
};