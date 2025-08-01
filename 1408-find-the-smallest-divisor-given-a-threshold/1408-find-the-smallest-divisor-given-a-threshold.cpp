class Solution {
public:
   bool can(int &mid,vector<int> &n,int &t){
    int count = 0;
    for(auto x:n) count+= (x/mid + (x%mid!=0));

    return count<=t; 
   }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int l = 1, r = *max_element(nums.begin(),nums.end());
        int result = r;

        while(l<=r){
            int mid = l + ((r-l)>>1);
            cout << mid << endl;

            if(can(mid,nums,threshold)){
                result = mid;
                r = mid -1;
            }
            else l = mid + 1;

        }


        return result;
    }
};