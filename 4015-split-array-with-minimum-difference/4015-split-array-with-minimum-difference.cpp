class Solution {
public:
    long long splitArray(vector<int>& nums) {

        vector<bool>left(nums.size(),false);
        vector<bool>right(nums.size(),false);
        left[0] = true;
        // bool flag = true;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]) break;
            left[i]=true;
            // cout << left[i]<< " ";
            
        }
cout<<endl;
        right[nums.size()-1] = true;
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i]<=nums[i+1]) break;
            right[i] = true;
            // cout << right[i]<<" ";
        }

        long long total = 0;
        for(auto x:nums) total+=x;
        long long curr = 0;
        long long ans = -1;
        for(int i = 0;i<nums.size()-1;i++){
            curr+=nums[i];
            // cout << left[i]<< " "<<right[i+1]<<endl;
            if(left[i]and right[i+1] and (ans==-1 || ans> abs(curr - (total-curr))))
              ans  =  abs(total - 2*curr);
            
        }


      return ans;
        
        
        
    }
};