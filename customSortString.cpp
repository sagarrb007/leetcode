/**

LC 791 https://leetcode.com/problems/custom-sort-string/description/ 

S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

**/
class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> tmap(26,0);
        vector<int> smap(26,0);
        string ret = "";
        
        for(auto i:S) smap[i-'a']=1;
        for(auto i:T) tmap[i-'a']++;
        
        for(auto i:S) {
            ret += string(tmap[i-'a'],i);
            tmap[i-'a'] = 0;
        }
        
        for(auto i:T) {
            if (tmap[i-'a']) {
                ret += string(tmap[i-'a'],i);
                tmap[i-'a'] = 0;
            }
        }
        
        return ret;
    }
};
