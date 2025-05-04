class Solution {
public:
int bruteforce(vector<int>& height){
    int maxwater=-1;
    int currentwater=0;
    for(int i=0;i<height.size();i++){
        for(int j=i+1;j<height.size();j++){
           int mini=min(height[i],height[j]);
                currentwater=mini*(j-i);
            
            maxwater=max(currentwater,maxwater);
        }
    }
    return maxwater;
}
int twopointer(vector<int>& height){
    int mini;
    int start=0;
    int end=height.size()-1;
    int maxwater=-1;
    int currentwater=0;
    while(start<end){
        mini=min(height[start],height[end]);
        currentwater=mini*(end-start);           
        maxwater=max(currentwater,maxwater);
    
    if(height[start]==mini){
       start++;
    }
    else{
        end--;
    }
    }
return maxwater;
}
    int maxArea(vector<int>& height) {
        return twopointer(height);
    }
};