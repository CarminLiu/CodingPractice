/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<char> record;
        int len1 = s1.length(), len2 = s2.length();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));
        for(int i=1; i<=len2; i++)
            dp[0][i] = i;
        for(int i=1; i<=len1; i++)
            dp[i][0] = i;
        int i=1;
        int j=1;
        for(; i<=len1; i++){
            for(; j<=len2; j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
            }
        }
        
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1])
                record.push_back(s1[i-1]);
            int itemp = 0, jtemp=0;
            if(dp[i-1][j] <= dp[i][j-1] ){
                itemp = i-1;
                jtemp = j;
            }
            else {
                itemp = i;
                jtemp = j-1;
            }

            if(dp[i-1][j-1] <= dp[itemp][jtemp]){
                itemp = i-1;
                jtemp = j-1;
            }

            i = itemp;
            j = jtemp;

        }

        int sum0=0;
        for(int k=0; k<record.size(); k++){
            sum0 += record[k]; 
        }
        int sum1=0, sum2=0;
        for(int k=0; k<len1; k++)
            sum1+=s1[k];
        for(int k=0; k<len2; k++)
            sum2+=s2[k];

        return sum1 + sum2 - 2*sum0;
    }
};
// @lc code=end

