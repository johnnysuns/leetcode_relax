// Given inorder and postorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
//
// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
//
// Return the following binary tree:
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//


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
public:
    unordered_map<int,int> inorder_index;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,int ina, int inb,int posta, int postb) {
        if(ina>inb)return NULL;
        if(ina == inb)return new TreeNode(inorder[ina]);
        TreeNode* root = new TreeNode(postorder[postb]);
        int root_index=inorder_index[root->val];
        int left_n=root_index-ina;
        int right_n=inb-root_index;
        root->left=buildTree(inorder, postorder,ina, root_index-1, posta, posta+left_n-1);
        root->right=buildTree(inorder, postorder,root_index+1,inb, postb-right_n, postb-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            inorder_index[inorder[i]]=i;
        }
        return buildTree(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
        
    }
};
