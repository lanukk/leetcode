class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0, e1 = 0, e2 = 0;
        for(int i : nums){
            if(e1 == i){
                c1++;
            } else if(e2 == i){
                c2++;
            } else if(c1 == 0){
                e1 = i;
                c1 = 1;
            } else if(c2 == 0){
                e2 = i;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
            cout<<e1<<" "<<e2<<"\n";
            cout<<c1<<" "<<c2<<"\n";
            cout<<"\n";
        }
        c1 = 0, c2 = 0;
        for(int i : nums){
            if(i == e1)
                c1++;
            else if(i == e2)
                c2++;
        }
        int n = (int)nums.size();
        vector<int> ans;
        if(c1 > n / 3)
            ans.push_back(e1);
        
        if(c2 > n / 3)
            ans.push_back(e2);
        cout<<e1<<" "<<e2<<"\n";
        cout<<c1<<" "<<c2<<"\n";
        
        return ans;
    }
};