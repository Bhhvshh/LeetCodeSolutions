class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //brute force way
  unordered_map<int ,int> umap;

  for(int i = 0;i<nums.size();i++){
    int com = target - nums[i];
    if(umap.count(com)) return {i,umap[com]};
    umap[nums[i]]=i;
  }

  return {};
    }
};