/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(len2+1, vector<int>(len1+1, 0));

        for(int i=1; i<=len1; i++)
            dp[0][i] = i;
        for(int i=1; i<=len2; i++)
            dp[i][0]=i;

        for(int j=1; j<=len2; j++){
            for(int i=1; i<=len1; i++){
                if(word1[i-1] == word2[j-1]) {
                    dp[j][i] = dp[j-1][i-1];
                }
                else {
                    int minTmp = min(dp[j-1][i-1], dp[j-1][i]);
                    minTmp = min(minTmp, dp[j][i-1]);
                    dp[j][i] = minTmp + 1;
                }
            }
        }
        return dp[len2][len1];

    }
    
};
// @lc code=end

