class Solution {
public:
bool solve(vector<vector<char>>& nums, string word,int row,int col,int i){
    if(i==word.size()){
        return true;
    }
    if(row<0||row>=nums.size()||col<0||col>=nums[0].size()||nums[row][col]=='%'){
        return false;
    }
    if(nums[row][col]!=word[i]){
        return false;
    }
    char temp=nums[row][col];
    nums[row][col]='%';
    bool found=solve(nums,word,row-1,col,i+1)||
               solve(nums,word,row+1,col,i+1)||
               solve(nums,word,row,col-1,i+1)||
               solve(nums,word,row,col+1,i+1);
               nums[row][col]=temp;
               return found;
}
    bool exist(vector<vector<char>>& nums, string word) {
       for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[0].size();j++){
            if(solve(nums,word,i,j,0)){
                return true;
            }
        }
       } 
       return false;
    }
};