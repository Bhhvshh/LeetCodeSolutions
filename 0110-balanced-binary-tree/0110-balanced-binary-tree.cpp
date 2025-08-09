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
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        helper(root,ans);

        return ans;

        
    }

    int helper(TreeNode* r, bool &ans){
        if(!r) return -1;
        int l = 1 + helper(r->left,ans);
        int ri = 1 + helper(r->right,ans);

        if(abs(l-ri)>1) ans = false;
        return max(l,ri);
    }
};