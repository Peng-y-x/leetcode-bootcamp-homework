/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* lca;
public:
    bool findNode(TreeNode* node, TreeNode* p, TreeNode* q){
        bool l = false, r = false, mid = false;
        if(!node){
            return false;
        }
        l = findNode(node->left, p, q);
        r = findNode(node->right, p, q);
        mid = node == p || node == q;
        if(mid + l + r >= 2){
            lca = node;
        }
        return mid || l || r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findNode(root, p, q);
        return lca;
    }
};
