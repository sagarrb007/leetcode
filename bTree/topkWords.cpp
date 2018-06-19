/*
 * https://leetcode.com/problems/top-k-frequent-words/description/
 * Given a non-empty list of words, return the k most frequent elements. Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
*/

class Solution {
public:


    vector<string> topKFrequent(vector<string>& words, int k) {
        
        if(!words.size()) return vector<string>();
        
    auto compare = [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) { 
            return a.second < b.second || ((a.second == b.second) && (a.first.compare(b.first) > 0)) ; 
        };
        
        std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(compare)> pq(compare);
        unordered_map<string, int> map;
        vector<string> ret;
        int max = k;
        
        for(auto i:words) map[i]++;
        
        for(const auto &i:map) {
            
            pq.push(i);
        }
        
        while(pq.size() && k) {
            //if(pq.top().first < max) return ret;
            k--;
            ret.push_back(pq.top().first);
                          pq.pop();
        }
        
        
        return ret;
    }
};
