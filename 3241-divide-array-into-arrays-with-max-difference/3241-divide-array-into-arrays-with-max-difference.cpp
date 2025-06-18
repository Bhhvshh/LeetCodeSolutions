class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0;i<n;i+=3){
            vector<int> tmp;
            for(int j = i;j<i+3;j++){
                if(nums[j]-nums[i]<=k){
                    tmp.push_back(nums[j]);
                }
                else return {};

            }
            ans.push_back(tmp);
        }

        return ans;
        
    }
};