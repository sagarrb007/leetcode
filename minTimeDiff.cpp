// Problem: Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        vector<int> ret;
        int half = 720;
        int full = 1440;
 
        for(auto i:timePoints) {
            int temp = (i[0]-'0')*10*60 +(i[1]-'0')*60 + (i[3]-'0')*10+(i[4]-'0');
            
            ret.push_back(half-temp>0?temp:temp-full);
        }
        
        sort(ret.begin(),ret.end());
        
        int min = INT_MAX;
        int temp;
        
        for(int i =1; i < ret.size();i++) {
           temp = abs(ret[i]-ret[i-1]);
            if(temp > half) {
                temp = full - abs(ret[i]-ret[i-1]);
            }
            
            min = ::min(min,temp);
        }
        
        temp = abs(ret.front()-ret.back());
        if (temp > half) {
           temp = full - abs(ret.front()-ret.back());
        }
        
        min = ::min(min,temp);
        
        return min;
        
    }
};
