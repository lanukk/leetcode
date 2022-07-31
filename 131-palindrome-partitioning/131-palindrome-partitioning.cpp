class Solution {
public:
    
    bool palindrome[16][16];
    vector<vector<string>> ans;
    
    void recursion(int begin, vector<string> temp, string &s){
        if(begin == s.length()){
            ans.push_back(temp);
            return;
        }
        
        for(int i = begin; i < (int)s.length(); i++){
            if(palindrome[begin][i]){
                temp.push_back(s.substr(begin, i - begin + 1));
                recursion(i + 1, temp, s);
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        int n = (int)s.length();
        for(int i = 0; i < n; i++){
            for(int j = i ; j < n; j++){
                string k = s.substr(i, j - i + 1);
                string t = k;
                reverse(t.begin(), t.end());
                
                if(k == t){
                    palindrome[i][j] = true;
                }
                else
                    palindrome[i][j] = false;
            }
        }
        
        recursion(0, {}, s);
        
        return ans;        
    }
};