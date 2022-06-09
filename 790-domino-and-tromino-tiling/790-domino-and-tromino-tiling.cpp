class Solution {
public:
    int dp[1024];
    const int mod = 1e9 + 7;
    int recursion(int i, int & n){
        if(i == n)
            return 1;
        if(i > n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        long long ans = 0;
        
        (ans += recursion(i + 1, n)) %= mod;
        (ans += recursion(i + 2, n)) %= mod;
        for(int j = 3; ; j++){
            if(i + j > n)
                break;
            (ans += recursion(i + j, n) + recursion(i + j, n)) %= mod;
        }
        return dp[i] = ans;
    }
    
    int numTilings(int n) {
        memset(dp, -1, sizeof(dp));
        return recursion(0, n);
    }
};