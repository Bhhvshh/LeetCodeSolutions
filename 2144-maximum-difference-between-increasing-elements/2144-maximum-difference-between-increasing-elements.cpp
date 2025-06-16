class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        multiset<int> ms;
        int ans = -1;
        for(auto x:nums)
          ms.insert(x);

        for(auto x:nums){
            auto it = ms.find(x);
            ms.erase(it);
            if(ms.size() && x<*ms.rbegin()){
                ans = max(ans,*ms.rbegin()-x);

            }
        }
        return ans;
        
    }
};