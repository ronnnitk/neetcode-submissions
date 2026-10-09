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
    int pind=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i =0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return dfs(preorder,0,inorder.size()-1,mp);
    }
    TreeNode* dfs(vector<int>& preorder,int l,int r,unordered_map<int,int>& mp){
        if(l>r) return nullptr;
        int root_val=preorder[pind++];
        TreeNode* root =new TreeNode(root_val);
        int mid=mp[root_val];
        root->left=dfs(preorder,l,mid-1,mp);
        root->right=dfs(preorder,mid+1,r,mp);
        return root;
    }
};
