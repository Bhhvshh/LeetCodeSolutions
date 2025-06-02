class Solution {
public:
    int singleNumber(vector<int>& nums) {
       vector<int> count(32);

       for(auto x:nums)
        for(int i = 0;i<32;i++)
           count[i]+= (x & 1<<i)? 1:0;
       
       bitset<32> ans;
       for(int i =0;i<32;i++)
        ans[i] = count[i]%3;
     

       return ans.to_ulong();
        
    }
};