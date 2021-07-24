/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty())
        {
            vector<int> temp;
            for(int i=q.size(); i>0; i--)
            {
                TreeNode* cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                if(cur->left!=nullptr) {
                    q.push(cur->left);
                }
                if(cur->right!=nullptr) {
                    q.push(cur->right);
                }
            }
            if(cnt%2==1){
                reverse(begin(temp),end(temp));
            }
            ans.push_back(temp);
            cnt++;
        }
        return ans;
    }
};
// @lc code=end

