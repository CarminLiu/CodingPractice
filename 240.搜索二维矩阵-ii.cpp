/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if(m==0 || n==0 ) return false;
        int row = m-1, col = 0;
        while(row>=0 && col <n)
        {
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col]>target) row--;
            else col++;
        }
        return false;
    }
};
// @lc code=end

