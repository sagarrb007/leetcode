/*
 *Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
 *
 */



#include <cmath>
class Solution {
public:
    
    int permute(int n, int r) {
        
        if(r==0) return 1;
        else return n*permute(n-1,r-1);
        
    }
    
    int countNumbersWithUniqueDigits(int n) {
        int sum = 1;
        if(n < 1) return sum;
        
        if(n>10) n = 10;
        int i = 0;
        while(n > i) {
            sum += 9 *permute(9,i++);
        }
        
        return sum;
    }
    };
