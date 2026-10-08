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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans(2);
        ans[0]=k;
        dfs(root,ans);
        return ans[1];
    }
    void dfs(TreeNode* root,vector<int>& ans){
        if(!root) return ;
        dfs(root->left,ans);
        if(ans[0]==0) return;

        ans[0]--;
        if(ans[0]==0){
            ans[1]=root->val;
            return;
        }
     
        dfs(root->right,ans);        
    }
};
