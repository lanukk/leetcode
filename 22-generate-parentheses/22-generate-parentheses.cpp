class Solution {
public:
    bool balanced(string s){
        int sum = 0;
        for(char c : s){
            if(c == '(')
                sum++;
            else
                sum--;
            if(sum < 0)
                return 0;
        }
        return (sum == 0);
    }
    vector<string> generateParenthesis(int n) {
        n *= 2;
        string s = "";
        for(int i = 1; i <= n; i++)
            s += '(';
        vector<string> ans;
        for(int mask = 0 ; mask < (1 << n); mask++){
            for(int i = 0; i < n; i++){
                if(mask & (1 << i))
                    s[i] = '(';
                else
                    s[i] = ')';
            }
            if(balanced(s))
                ans.push_back(s);
        }
        return ans;
    }
};