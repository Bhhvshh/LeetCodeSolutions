class Solution {
public:
    int minNumberOperations(vector<int>& target) {

        int ans = 0;
        int prev = 0;


        for(auto x:target){
            if(prev<x) ans+= x-prev;
            prev=x;
        }


        return ans;
        
    }
};