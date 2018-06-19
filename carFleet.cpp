/**
LC 853
https://leetcode.com/problems/car-fleet/description/
**/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<double>> fleets;
        int N = position.size();
        int res = 0;
        double cur = 0;
        
        for (int i = 0; i < N; ++i)
            fleets.push_back({(double)position[i], (double)(target - position[i]) / speed[i]});
        sort(fleets.begin(), cars.end());
        
        for (int i = N - 1; i >= 0 ; --i)
            if (fleets[i][1] > cur)
                cur = fleets[i][1], res++;
        return res;
        
    }
};
