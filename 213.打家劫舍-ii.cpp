/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int dpi_2 = nums[0];
        int dpi_1 =max(nums[0], nums[1]);
        int dpi1 = dpi_1;
        for(int i=2; i<n-1; i++) {
            dpi1 = max(dpi_2+nums[i], dpi_1);
            dpi_2 = dpi_1;
            dpi_1 = dpi1;
        }
        dpi_2 = nums[1];
        dpi_1 = max(nums[2], nums[1]);
        int dpi2 = dpi_1;
        for(int i = 3; i<n; i++){
            dpi2 = max(dpi_2+nums[i], dpi_1);
            dpi_2 = dpi_1;
            dpi_1 = dpi2;
        }
        return max(dpi1, dpi2);
    }
};
// @lc code=end

