class Solution {
public:
int counts(string s,int i,int j){
    int count=0;
    while(i>=0 && i<s.size() &&  s[i]==s[j]){
     count++;
     i--;
     j++;
    }
    return count;
}
    int countSubstrings(string s) {
        int totalcount=0;
        for(int i=0;i<s.size();i++){
            // int i=center;
            // int j=center;
            int odd=counts(s,i,i);
        //    i=center;
        //      j=center   +1;
            int even=counts(s,i,i+1);
              totalcount=totalcount+odd+even;
        }

         return totalcount;
    }
};