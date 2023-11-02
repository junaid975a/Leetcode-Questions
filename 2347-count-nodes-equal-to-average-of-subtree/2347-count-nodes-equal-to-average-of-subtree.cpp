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
    pair<int,int> solve(TreeNode* root, int &ans) {
        if(root==nullptr)
            return {0,0};
        
        if(!root->left && !root->right){
            ans++;
            return {root->val, 1};
        }

        pair<int,int>left = solve(root->left, ans);
        pair<int,int>right = solve(root->right, ans);
        int sum = left.first + right.first + root->val;
        int n = left.second + right.second + 1;
        if(sum/n == root->val) ans++;
        return make_pair(sum,n);
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};