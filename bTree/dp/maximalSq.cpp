/**
  * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
  * LC 221
  *
**/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(!matrix.size()) return 0;
        int val = 0;
        int dp[matrix.size()+1][matrix[0].size()+1] = {0};
        
        for(int i=0;i <= matrix.size();i++) dp[i][0] = 0;
        for(int i=0;i <= matrix[0].size();i++) dp[0][i] = 0;
        
        for(int i=1; i <= matrix.size();i++) {
            
            for(int j = 1; j <= matrix[0].size();j++) {
                if((i==1 || j == 1) && matrix[i-1][j-1] == '1') {
                    dp[i][j] = 1;
                }
            else if(matrix[i-1][j-1] == '1' && matrix[i-2][j-2]=='1' && matrix[i-2][j-1]=='1' &&matrix[i-1][j-2]=='1')
                    dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
            else if(matrix[i-1][j-1] == '1' ) dp[i][j] = 1;
                val = max(val,dp[i][j]);
                //cout << dp[i][j];
              }
           //cout << endl << val;
        }
        
        return val*val;
        
        }
        
};
