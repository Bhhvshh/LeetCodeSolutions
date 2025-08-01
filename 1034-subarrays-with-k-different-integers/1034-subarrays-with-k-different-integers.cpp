class Solution {
public:
int countAtMostK(vector<int> &arr, int k) {
        // code here
        
        unordered_map<int,int> umap;
        int count = 0, ans = 0;
        
        for(int i = 0, l = 0;i<arr.size();i++){
          count+=(umap[arr[i]]++==0);
          while(count>k)  count-= (umap[arr[l++]]--==1);
          ans+= (i-l+1);
        }
        
        
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return countAtMostK(nums,k) - countAtMostK(nums,k-1);
        
    }
};