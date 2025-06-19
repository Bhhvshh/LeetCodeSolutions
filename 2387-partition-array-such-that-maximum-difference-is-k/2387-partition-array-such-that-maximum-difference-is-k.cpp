class Solution {
public:
 void countSort(vector<int> &nums){
    int maxElement = *max_element(nums.begin(),nums.end());
    vector<int> fr(maxElement+1);

    for(auto x:nums)
     fr[x]++;

    for(int i = 1;i<=maxElement;i++)
      fr[i]+=fr[i-1];

    vector<int> output(nums.size());

    for(int i = nums.size()-1;i>=0;i--){
        output[--fr[nums[i]]]
        =nums[i];
        
    }

    nums= output;


 }
    int partitionArray(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        countSort(nums);
        int start = nums[0];
        int result = 1;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]-start>k){
                result++;
                start =  nums[i];
            }

        }


        return result;
        
    }
};