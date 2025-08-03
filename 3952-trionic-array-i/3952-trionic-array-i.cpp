class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int l = 0;
        int n = nums.size();
        while(l<n-1 && nums[l]<nums[l+1])l++;
        if(l==0) return false;
        int r = l;
        while(r<n-1 && nums[r]>nums[r+1]) r++;

        if(r==l || r ==n-1) return false;
       // cout << r << l <<endl;
        bool flag = true;
        // cout << "here"<<endl;
        

        for(int i = r;i<n-1;i++) if(nums[i+1]<=nums[i]){flag = false; break;}
        return flag;
    }
};