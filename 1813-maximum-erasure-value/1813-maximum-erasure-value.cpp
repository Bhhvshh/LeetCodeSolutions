class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        

       unordered_map<int,int> umap;
       vector<int> pre;
        int sum = 0;
        int ans = 0;
        for(int i = 0, l = 0;i<nums.size();i++){
            l = max(l,umap[nums[i]]);
            sum+=nums[i];

            if(l>0) ans = max(ans,sum-pre[l-1]);
            else ans = sum;
            
            umap[nums[i]] = i+1;
      


            pre.push_back(sum);
            



        }


        return ans;
    }
};