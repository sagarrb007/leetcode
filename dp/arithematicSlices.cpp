/*
 * A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
 * LC 413
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        if(A.size() < 3) return 0;
        
        vector<int> dp (A.size(),0);
        
        for(int i = 2; i < A.size(); i++) {
            
            dp[i] = ((A[i]-A[i-1] == A[i-1]-A[i-2])?1+dp[i-1]:0);
        }
        
        return accumulate(dp.begin(),dp.begin()+A.size(),0);
        
    }
};
