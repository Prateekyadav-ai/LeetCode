class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>v;
        for(int i=0;i<n;i++){
            int k=start+2*i;
            v.push_back(k);
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
          ans^=v[i];
        }
        return ans;
    }
};