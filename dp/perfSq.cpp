/*
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
*/


class Solution {
public:
    int numSquares(int n) {
        
        vector<vector<int>> dp;
        vector<int> sqs;
        
        int ps = 1;
        cout << dp.size() << endl;
        while(ps * ps <= n) {
            sqs.push_back(ps*ps);
            ps++;   
        }
        
        for(int i=0; i < ps-1; i++) {
            
            vector<int> temp(n+1,0);
            dp.push_back(temp);
        }
        
        cout << dp[0].size() << dp.size() << endl;
        
        for(auto i =0; i < dp.size() + 1;i++) {
            
            for(auto j = 0; j < n + 1; j++) {
                
                if(i==0 || j ==0) dp[i][j] = 0;
                
                else if(j == sqs[j]) dp[i][j] = 1;
                
                else if()
                
                else {
                    
                    dp[i][j] = min(dp[i][sqs[j]])
                    
                }
            }
            
        }
        
        
        return 9;

    }
};
