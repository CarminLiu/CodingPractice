/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0)
            return 0;
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2){
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        } );
        vector<int> dp(n,1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++) {
                if(envelopes[i][1]>envelopes[j][1]){
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

