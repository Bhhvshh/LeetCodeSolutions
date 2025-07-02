class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        queue<int> q;
        int ans = 0;
        int sum = 0;
        
        for(int i = 0, last = 0;i<nums.size();i++){
            if(nums[i]){
                q.push(i);
                sum++;

            }
           
           if(sum>goal){
                last = q.front() + 1;
                sum--;
                q.pop();
            }

            if(sum==goal) {if(q.size())ans+= (q.front()-last+1);
            else{ ans+=(i-last+1); }}


        }
       

       return ans;
        
    }
};