/*
 * Given a string, sort it in decreasing order based on the frequency of characters. 
 * LC 451
*/

class Solution {
public:
    string frequencySort(string s) {
        
        if(!s.size()) return "";
        
        string ret = "";
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> map;
        
        for(auto i:s) map[i]++;
        
        for(auto it = map.begin();it!=map.end();++it) {
            pq.push(make_pair(it->second, it->first));
        }
        
        while(pq.size()) {
            ret += string(pq.top().first, pq.top().second);
            pq.pop();
        }
        
        return ret;
    }
};
