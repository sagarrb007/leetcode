/*
 * Longest Increasing Subsequence
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return len;
        vector<int> before;
        before.push_back(nums[0]);
        for(int i = 1; i < len; i++){
            if(before.back() < nums[i]){
                before.push_back(nums[i]);
            }
            else{
                int tmp = lower_bound(before.begin(), before.end(), nums[i]) - before.begin();
                before[tmp] = nums[i];
            }
        }
        return before.size();
    }
};
