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
    void inorder(TreeNode* root, map<int,int>&mp, int &mx) {
        if(root==NULL) return ;
        inorder(root->left, mp, mx);
        mp[root->val]++;
        mx = max(mx,mp[root->val]);
        inorder(root->right, mp, mx);
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int>mp;
        int mx = 0;
        inorder(root,mp,mx);
        vector<int>ans;
        for(auto &m:mp) {
            if(m.second==mx) ans.push_back(m.first);
        }
        return ans;
    }
};