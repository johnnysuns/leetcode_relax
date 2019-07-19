// We are given a binary tree (with root node root), a target node, and an integer value K.
//
// Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
//
// Output: [7,4,1]
//
// Explanation: 
// The nodes that are a distance 2 from the target node (with value 5)
// have values 7, 4, and 1.
//
//
//
// Note that the inputs "root" and "target" are actually TreeNodes.
// The descriptions of the inputs above are just serializations of these objects.
//
//
//  
//
// Note:
//
//
// 	The given tree is non-empty.
// 	Each node in the tree has unique values 0 <= node.val <= 500.
// 	The target node is a node in the tree.
// 	0 <= K <= 1000.
//
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
    const int INF=10000;
public:
    void reach_in_k(TreeNode* root, int K,vector<int> &res){
        if(K<0 || root==NULL) return;
        if (K==0){
            res.push_back(root->val);
            return;
        }else{
            reach_in_k(root->left, K-1,res);
            reach_in_k(root->right, K-1,res);
        }
        return;
    }
    
    //find target and return the distance to it
    int find_target(TreeNode* root, TreeNode* target, int K, vector<int> &res){
        if(root==NULL) return INF;
        int left_res=0;
        int right_res=0;
        if(root!=target){
            left_res=1+find_target(root->left, target, K, res);
            right_res=1+find_target(root->right, target, K, res); 
            cout<<"root"<<root->val<<" left res"<<left_res<<" right res"<<right_res<<endl;
            
            if(left_res<INF){
                reach_in_k(root->right, K-left_res-1,res);
            }
            else if(right_res<INF){
                reach_in_k(root->left, K-right_res-1,res);
            }
        }else{
            reach_in_k(root->left, K-1,res);
            reach_in_k(root->right, K-1,res);
        }
        int dis=min(left_res,right_res);
        if(dis==K) res.push_back(root->val);
        return dis;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        find_target(root, target, K, res);
        return res;
    }
    
    //TODO： method2 build a graph then do dijkstra/BFS search
};
