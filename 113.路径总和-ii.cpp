/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        recur(root, targetSum);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> path;
    void recur(TreeNode* root, int targetSum) {
        if(root==NULL)
            return;
        path.push_back(root->val);
        targetSum -= root->val;
        if(targetSum==0 && root->left==NULL && root->right==NULL)
            ans.push_back(path);
        recur(root->left, targetSum);
        recur(root->right, targetSum);
        path.pop_back();
    }
};
// @lc code=end

