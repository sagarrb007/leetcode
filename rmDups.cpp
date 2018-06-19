/*
 * Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length. 
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory
 * LC 80 https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 */


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int idx = 0;
        
        for(auto i:nums) {
            
            if(idx < 2 || i > nums[idx-2]) {
                nums[idx++] = i;
            }
        }
        
        return idx;
    }
};
