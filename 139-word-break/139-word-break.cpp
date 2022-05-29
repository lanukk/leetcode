class Solution {
public:
    map<string, bool> mp;
    int dp[305];
    
    int recursion(string &s, int i){
        if(i == s.length())
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        bool ans = 0;
        string temp = "";
        for(int j = i ; j < s.length(); j++){
            temp += s[j];
            if(mp.find(temp) != mp.end())
                ans = (ans | recursion(s, j + 1));
        }
        return dp[i] = ans;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x : wordDict)
            mp[x] = 1;
        for(int i = 0 ; i <= s.length(); i++)
            dp[i] = -1;
        return recursion(s, 0);
    }
};