class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<pair<int,int>> vp;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]==key){
                if(vp.empty() || vp.back().second<i-k){
                    int tmp = (i-k>0) ? i-k:0;
                    int tmp1 = (i+k<nums.size()) ? i+k:nums.size() - 1;
                    vp.push_back({tmp,tmp1});
                }
                else {
                    int tmp1 = (i+k<nums.size()) ? i+k:nums.size() - 1;

                    vp.back().second = tmp1;
                }
            }
        }

        vector<int> ans;


        for(auto x:vp){
            for(int i = x.first;i<=x.second;i++)
              ans.push_back(i);
        }

    


        return ans;


        
    }
};