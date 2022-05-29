class Solution {
public:
    
    int recursion(string &s, string &p, int i, int j){
        if(i >= s.length() && j >= p.length())
            return 1;
        if(i >= s.length())
            return 0;
        if(j == p.length()){
            if(s[i] == '*')
                return recursion(s, p, i + 2, j);
            return 0;
        }
         
        if(s[i] == '.')
            return recursion(s, p, i + 1, j + 1);
        
        if(s[i] != '*'){
            if(s[i] == p[j])
                return recursion(s, p, i + 1, j + 1);
            return 0;
        }
        // cout<<s<<" "<<p<<" "<<i<<" "<<j<<"\n";
        bool ans = recursion(s, p, i + 2, j);
        
        char c = '1';
        if(s[i + 1] == '.')
            c = '1';
        else
            c = s[i + 1];
        
       
        
        while(j < p.length() && (c == '1' || c == p[j])){
            j++;
            ans = (ans | recursion(s, p, i + 2, j));
        }   
        
        return ans;
    }
    
    bool isMatch(string s, string p) {
        reverse(s.begin(), s.end());
        reverse(p.begin(), p.end());
        swap(s, p);
        return recursion(s, p, 0, 0);
    }
};