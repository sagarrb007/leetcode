/*
* Regex Match in DP https://leetcode.com/problems/regular-expression-matching/description/
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        
        bool dp[s.length()+1][p.length()+1];
        
        for(int i=0; i < s.length()+1;i++) dp[i][0] = false;
        
        for(int j = 0; j < p.length()+1; j++) dp[0][j] = false;
        
        dp[0][0] = true;
        
        
        for(int i=1;i < p.length()+1;i++) 
            if(p[i-1] == '*') dp[0][i] = i>1 && dp[0][i-2]; 

        
        for(int i=1; i < s.length()+1;i++) {
            
            for(int j =1; j < p.length()+1;j++) {
        
                if(p[j-1] == '*')
                    dp[i][j] = dp[i][j-2] || (s[i-1] == p[j-2] || p[j-2]=='.') && dp[i-1][j];
                
                else if(p[j-1] == '.' || p[j-1] == s[i-1])
                  dp[i][j] = dp[i-1][j-1];
                
                else dp[i][j] = false;
                
                cout << dp[i][j];
            }
            cout << endl;
        }
        
        return dp[s.length()][p.length()];
        
    }
};
