class Solution {
public:
    
    /*


    */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumG = 0, sumC = 0;
        int n = (int)gas.size();
        vector<int> p;
        
        for(int i = 0; i < n; i++){
            sumG += gas[i];
            sumC += cost[i];
            p.push_back(gas[i] - cost[i]);
        }
        if(sumG < sumC)
            return -1;
        
        int index = - 1;
        int sum = 0;
        
        
        for(int i = 0; i < n; i++){
            sum += p[i];
            // cout<<p[i]<<"\n";
            if(sum < 0){
                index = - 1;
                sum = 0;
            } else if(index == -1){
                index = i;
            }
        }
        
        return index;
    }
};