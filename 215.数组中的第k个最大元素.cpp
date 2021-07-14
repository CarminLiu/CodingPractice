/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        int left=1, right=n-1;
        int pivot = 0;
        while(left<=right){
            while(left<=right){
                while(nums[left]>nums[pivot] && left<)
                    left++;
                while(nums[right]<nums[pivot] && right>0)
                    right--;
                swap(nums[left], nums[right]);
            }
            if(left == k)
                return nums[pivot];
            swap(nums[left],nums[pivot]);
            if(left>k){
                right = left-1;
                left = pivot+1;
            }
            else{
                right = n-1;
                left = left+1;
            }
        }
        return nums[left];
    }
};
// @lc code=end

