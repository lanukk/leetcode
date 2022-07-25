class Solution {
public:
    
    bool recursion(int i, int j, int k, string &word, vector<vector<char>> & board){
        if(k == word.length())
            return true;
        
        if(board[i][j] != word[k])
            return false;
        
        bool possible = false;
        
        char realCharacter = board[i][j];
        board[i][j] = '.';
        
        if(i + 1 < board.size()){
            possible = (possible | recursion(i + 1, j, k + 1, word, board));
        }
        
        if(i - 1 >= 0){
            possible = (possible | recursion(i - 1, j, k + 1, word, board));
        }
        
        if(j + 1 < board[0].size()){
            possible = (possible | recursion(i, j + 1, k + 1, word, board));
        }
        
        if(j - 1 >= 0){
            possible = (possible | recursion(i, j - 1, k + 1, word, board));
        }
        
        board[i][j] = realCharacter;
        return (possible | (k + 1 == (int)word.length()));
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for(int i = 0; i < (int)board.size(); i++){
            for(int j = 0; j < (int)board[0].size(); j++){
                ans = (ans | recursion(i, j, 0, word, board));
            }
        }
        return ans;
    }
};