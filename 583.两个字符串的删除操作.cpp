/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));
        for(int i=1; i<=len2; i++)
            dp[0][i] = i;
        for(int i=1; i<=len1; i++)
            dp[i][0] = i;
        
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end

