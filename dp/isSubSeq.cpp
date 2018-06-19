/*
 * https://leetcode.com/problems/is-subsequence/description/
 *
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int si=0;
        if(!s.length()) return true;
        for(int i=0;i<t.length();i++) {
            
            if(s[si] == t[i]) {
                if(si==s.length()-1) return true;
                si++;
                } 
            
        }
        
        return false;

        
    }
};
