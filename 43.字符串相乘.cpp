/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
     string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        int lensum = len1 + len2;
        vector<int> numMul(lensum, 0);
        for(int i=len1-1; i>=0; i--) {
            for(int j=len2-1; j>=0; j--) {
                int m = (num1[i]-'0') * (num2[j]-'0');
                int pos1 = i + j, pos2 = j + i + 1;
                int sum = m + numMul[pos2];
                numMul[pos1] += sum/10;
                numMul[pos2] = sum%10;
            }
        }
        string ans="";
        int firstz = 0;
        while(firstz<lensum && numMul[firstz]==0){
            firstz++;
        }
        for(int i=firstz; i<lensum; i++) {
            char c = numMul[i]+'0';
            ans +=  c;
        }
        return ans.length() == 0 ? "0" : ans;

    }
};
// @lc code=end

