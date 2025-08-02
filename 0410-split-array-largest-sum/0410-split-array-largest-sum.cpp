class Solution {
public:

bool can(int &m,vector<int> &nums,int &k){
    int count = 0,curr = 0;
    for(auto x:nums){
        if(x>m) return false;
        curr+=x;
        if(curr>m){
            curr=x;
            count++;
        }
    }

    return count<k;



}
    int splitArray(vector<int>& nums, int k) {

        int sum = 0;
        for(auto x:nums) sum+=x;

        int l = 0, r = sum;
        int result = -1;

        while(l<=r){
            int mid = l + ((r-l)>>1);

            if(can(mid,nums,k)){
                result = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        } 


        return result;
        
    }
};