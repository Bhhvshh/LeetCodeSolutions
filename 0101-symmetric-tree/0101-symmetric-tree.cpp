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

bool isSym(TreeNode* l,TreeNode* r){
    if(l==nullptr || r==nullptr) return l==r;
    if(l->val!=r->val) return false;

    return isSym(l->left,r->right)&& isSym(l->right,r->left);
}
    bool isSymmetric(TreeNode* root) {

        return root==nullptr ||(isSym(root->left,root->right));

        
    }
};