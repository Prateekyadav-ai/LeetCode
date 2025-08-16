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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(!root)return ans ;
        q.push(root);
        while(!q.empty()){
            vector<int>curr;
            int size=q.size();
            for(int i=0;i<size;i++){
            TreeNode* front=q.front();
            q.pop();
            curr.push_back(front->val);
            
            if(front->left!=nullptr){
                q.push(front->left);
            }
             if(front->right!=nullptr){
                q.push(front->right);
            }
            }
            ans.push_back(curr);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};