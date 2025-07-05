class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> fr(501);
        for(auto x:arr) fr[x]++;

        for(int i = 500;i>0;i--)
          if(i==fr[i]) return i;

        return -1;
    }
};