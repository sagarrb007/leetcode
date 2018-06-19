Problem : Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.


class Solution {
public:
    int minDistance(string word1, string word2) {
        
        vector<vector<int>> dp (word1.size()+1,vector<int>(word2.size()+1,0));
        int comm;
 
        for(int i = 1; i < word1.size()+1; i++) {
            
            for(int j = 1 ; j < word2.size()+1;j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
       
        }
       
        comm = dp[word1.size()][word2.size()];
        return word1.length() + word2.length() - (comm*2);
    }
};
