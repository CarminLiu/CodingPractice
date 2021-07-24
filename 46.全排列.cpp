/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<bool> visited(n, false);
        vector<int> temp;
        dfs(nums, n, temp, visited);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int n, vector<int> temp, vector<bool>& visited) {
        if(temp.size() == n) {
            ans.push_back(temp);
            return ;
        }
        for(int i=0; i<n; i++) {
            if(visited[i])
                continue;
            visited[i] = true;
            temp.push_back(nums[i]);
            dfs(nums, n, temp, visited);
            visited[i] = false;
            temp.pop_back();
        }
    }
};
// @lc code=end

