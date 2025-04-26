class Solution {
public:
    int maxPower(string s) {
        int count=0;
        int maxcount=0;
        int i=0;
        int j=0;
        while(j<s.length()){
            if(s[i]==s[j]){
                count++;
                 j++;
                maxcount=max(count,maxcount);
            }
            else{
                count=0;
                i=j;
            }
        }
        return maxcount;
    }
};