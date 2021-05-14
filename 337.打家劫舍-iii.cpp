/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> ans = dp(root);
        return max(ans[0], ans[1]);
    }
private:
    vector<int> dp(TreeNode* root) {
        if(root == NULL) return vector<int>{0, 0};
        vector<int> left = dp(root->left);
        vector<int> right = dp(root->right);
        int torob = root->val + left[0] + right[0];
        int nottorob = max(left[0], left[1]) + max(right[0], right[1]);
        return vector<int>{nottorob, torob}; 
    }
};
// @lc code=end

