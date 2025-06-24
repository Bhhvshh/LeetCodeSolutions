class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
       
        vector<int> ans;
        int n = nums.size();


        for(int i = 0;i<n;i++)
            if(nums[i]==key){
                if(ans.empty() || ans.back()<i-k)
                   for(int j = max(0,i-k);j<=min(i+k,n-1);j++) ans.push_back(j);
                else 
                   for(int j = ans.back()+1;j<=min(i+k,n-1);j++) ans.push_back(j); 
                
            }
        



        return ans;


        
    }
};