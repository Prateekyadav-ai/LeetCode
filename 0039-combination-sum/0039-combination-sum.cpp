class Solution {
public:
void solve(vector<int>& arr, int target,vector<vector<int>>&ans,vector<int>&curr,int index){
    if(target==0){
        ans.push_back(curr);
          return;
    }
    
    if (target < 0) {
            return;
        }
    for(int i=index;i<arr.size();i++){
        curr.push_back(arr[i]);
         solve(arr,target-arr[i],ans,curr,i);
         curr.pop_back();
    }
}
    // if(arr[index]<=target){
    //     curr.push_back(arr[index]);
    //     solve(arr,target-arr[index],ans,curr,index);
    //     curr.pop_back();
    // }
    //   solve(arr,target,ans,curr,index+1);

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(candidates,target,ans,curr,0);
        return ans;
    }
};