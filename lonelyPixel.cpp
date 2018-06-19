
Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row R and column C that align with all the following rules:

Row R and column C both contain exactly N black pixels.
For all rows that have a black pixel at column C, they should be exactly the same as row R.


class Solution {
public:
    
    bool compare(vector<pair<int,int>> &p, int row, int col, vector<vector<char>>& picture) {
        
        for(auto it:p) {
            if(it.second == col) {
                if (picture[it.first] != picture[row]) return false;
            }
        }
 
        return true;
    }
    
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        
        unordered_map<int,int> col;
        unordered_map<int,int> row;
        vector<pair<int,int>> cord;
        int count = 0;
        
        for(int i =0; i< picture.size();i++) {
            
            for(int j =0; j< picture[0].size();j++) {
                
                if (picture[i][j] == 'B') {
                    col[i]++;
                    row[j]++;
                    cord.push_back(make_pair(i,j));
                }
            }
        }
        for(auto it:cord) {
            
            if(N == row[it.second] && col[it.first] == N ) {
                
                if (compare(cord,it.first, it.second, picture))
                count++;
            }
            
        }
        
        return count;
    }
};
