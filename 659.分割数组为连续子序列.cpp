/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 */

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, need;
        for(auto num: nums) freq[num]++;
        for(auto num: nums) {
            if(freq[num] == 0) continue;
            if(need.count(num) && need[num]>0){
                need[num]--;
                need[num+1]++;
                freq[num]--;
            } 
            else if(freq[num]>0 && freq[num+1]>0 && freq[num+2]>0){
                freq[num]--;
                freq[num+1]--;
                freq[num+2]--;
                need[num+3]++;
            }
            else return false;
        }
        return true;
    }
};
// @lc code=end

