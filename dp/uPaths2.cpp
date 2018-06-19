/* 
 *A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

LC 63

*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int dp[grid.size()+1][grid[0].size()+1];
        int m = grid.size();
        int n = grid[0].size()+1;
        for(int i =0;i<=m;i++) {
            
             for(int j =0;j<n;j++) {
            
                 if (i ==0 || j==0) dp[i][j] = 0;
                 else if (i ==1 && j==1) dp[i][j] = 1 - grid[i-1][j-1];
                 else {
                     
                     
                     if(!grid[i-1][j-1]) dp[i][j] = dp[i-1][j] + dp[i][j-1];
                     else dp[i][j] = 0;
                 }
            
        }
           
    }
        return dp[grid.size()][grid[0].size()];
    }
};
