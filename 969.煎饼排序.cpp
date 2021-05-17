/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */

// @lc code=start
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        for(int i=n; i>0; i--){
            if(arr[i-1] == i) continue;
            sorti(arr, i);
        }
        return ans;
    }
private:
    vector<int> ans;
    void sorti(vector<int>& arr, int i) {
        int pos=0;
        while(pos<i){
            if(arr[pos] == i) break;
            pos++; 
        }
        if(pos == 0)    {
            reverse(arr.begin(), arr.begin()+i);
            ans.push_back(i);
        }
        else{
            reverse(arr.begin(), arr.begin()+pos+1);
            ans.push_back(pos+1);
            reverse(arr.begin(), arr.begin()+i );
            ans.push_back(i);
        }
    }
};
// @lc code=end

