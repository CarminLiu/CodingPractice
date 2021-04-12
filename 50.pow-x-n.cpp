/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        double res=1;
        long int b=n;
        if(b<0){
            b = -b;
            x = 1/x;
        }
        while (b>0)
        {
            if((b&1)==1)
                res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
        
    }
};
// @lc code=end

