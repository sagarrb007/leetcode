/*
* LC 750
* Given a grid where each entry is only 0 or 1, find the number of corner rectangles.
* A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned rectangle. Note that only the corners need to have the value 1. Also, all four 1s used must be distinct.
*
*/


class Solution {
public:
    
    int countCornerRectangles(vector<vector<int>>& grid) {
        
        vector<pair<int,int>> result;
        int count = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            
            for(int j = 0; j < grid[0].size();j++) {
                if(grid[i][j] == 1) {
                  for(auto it:result) {
                    
                    if(it.first < i && it.second < j) count += (grid[i][it.second]==1 && grid[it.first][j]==1);
                  }
                
                  result.push_back(make_pair(i,j));
                }
            }
        }
        
        return count;
        
    }
};
