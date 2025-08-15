class Solution {
public: 
    void solve(TreeNode* root, int target,vector<vector<int>>&ans,vector<int>path,int sum){
        if(root==nullptr){
            return ;
        }
        sum=sum+root->val;
        path.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(sum==target){
            ans.push_back(path);
            }
           return ;
        }


        solve(root->left, target,ans,path,sum);
        solve(root->right, target,ans,path,sum);

    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<vector<int>>ans;
        vector<int>path;
       solve(root,targetSum,ans,path,sum);
       return ans;
    }
};