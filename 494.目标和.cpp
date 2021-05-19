/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int n : nums) sum += n;
        if (sum < target || (sum + target) % 2 == 1) {
            return 0;
        }
        return subsets(nums, (sum + target) / 2);
    }
private:
    int subsets(vector<int>& nums, int s) {
        int n = nums.size(); 
        vector<int> dp(s+1, 0);
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=s; j>=0; j--){
                if(j >= nums[i-1]) {
                    dp[j] = dp[j] + dp[j-nums[i-1]]; 
                }
                else {
                    dp[j] = dp[j];
                }
            }
        }
        return dp[s];
    }
};
// @lc code=end

