class Solution {
public:
    int possibleStringCount(string word) {
     int count=1;
     string str="";
     for(int i=0;i<word.size();i++){
        if(str.size()>0 && word[i]==str.back()){
            count++;
        }
        else{
            str.push_back(word[i]);
        }
     } 
     return count;  
    }
};