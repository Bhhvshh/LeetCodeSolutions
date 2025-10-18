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
    bool isValidBST(TreeNode* root) {

        return helper(root, LLONG_MIN, LLONG_MAX);
        
    }


    bool helper(TreeNode* root,long long l,long long r){
        if(!root) return true;
        if(( root->val<=l) || ( root->val>=r)) return false;
        return helper(root->left,l,root->val) and helper(root->right,root->val,r);
    }
};