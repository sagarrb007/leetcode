/*

*Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
*
*Your algorithm's runtime complexity must be in the order of O(log n).
*
*If the target is not found in the array, return [-1, -1].
*Runtime : 4ms 
*Percentile : 100 %
*/


class Solution {
public:
    
    int bSHelp(vector<int> &arr, int target, int start, int end, int left, int right) {
        
        while(start < end) {
            
            int mid = (start+end)/2;
            
            if(arr[mid] == target) {
                
                if(arr[mid+(left+right)]!= target) return mid;
                
                if(!right)if(arr[mid+left] == target) end = mid-1;
                if(!left) if(arr[mid+right] == target) start = mid+1;
            }
            
            else if(arr[mid] < target) start = mid+1;
            
            else end = mid-1;
        }
        
        return start;
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size()-1;
        vector<int> ret;
        int mid;
        
        if(!nums.size()) return vector<int>{-1,-1};
        
        while(start < end) {
           
            mid = (start+end)/2;
            
            if(nums[mid] == target) {
                if(nums[mid-1] == target)ret.push_back(bSHelp(nums, target,start, mid-1, -1, 0));
                else ret.push_back(mid);
                
                if(nums[mid+1] == target){
                    ret.push_back(bSHelp(nums, target,mid+1, end, 0, 1));
                    
                }
                else ret.push_back(mid);
                
                return ret;
            }
             else if(nums[mid] < target) start = mid+1;
            
            else end = mid-1;
        }
        
        if(nums[end] != target) {
            ret.push_back(-1); ret.push_back(-1);
        }
        
        else if(nums[mid+1] == target){
            ret.push_back(mid+1);
            ret.push_back(mid+1);
        }
        else if (nums[mid-1]==target) {
            ret.push_back(mid-1);
            ret.push_back(mid-1);
        }
        
        else if(start == mid && nums[start] == target) {
            ret.push_back(mid);
            ret.push_back(mid);
        }
        
        
        return ret;
        
    }
};
