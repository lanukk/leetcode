class Solution {
public:
    /*
    
    2^4 = 2 ^ 2 * 2 ^ 2 = 2 ^ 1 * 2 ^ 1 * 2 ^ 1 * 2 ^ 1
    
    
    a^8 = a^4 * a ^ 4 = a ^ 2 * a ^ 2 * a ^ 2 * a ^ 2 =...
    
    */
    
    double helper(double x, long long n){
        if(n == 0)
            return 1.00;
        
        double smallAns = helper(x, n / 2);
        smallAns *= smallAns;
        
        if(n % 2)
            smallAns*= x;
        
        return smallAns;
    }
    
    double myPow(double x, int n) {
        long long p = n;
        if(n < 0){
            x = 1/x;
            p = -p;
        }
        
        return helper(x, p);
    }
};