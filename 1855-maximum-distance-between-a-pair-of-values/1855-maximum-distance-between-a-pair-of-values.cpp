class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

      
        int ans = 0;
        for(int i = 0; i < nums2.size(); i++){
            auto it = std::lower_bound(nums1.begin(), nums1.end(), 
                           nums2[i], 
                           std::greater<int>());
            if(it != nums1.end())
              ans = max(ans, i - (int)(it - nums1.begin()));

        }

        return ans;
        
    }
};