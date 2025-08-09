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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        helper(root,ans);

        return ans;

        
    }

    int helper(TreeNode* root,int &ans){
        if(!root) return -1;

        int l = 1 + helper(root->left,ans);
        int r = 1 + helper(root->right,ans);
        ans = max(ans,l+r);

        return max(l,r);

    }
};