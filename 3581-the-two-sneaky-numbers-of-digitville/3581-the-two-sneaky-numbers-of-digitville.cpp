class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {

    int i = 0, n = nums.size();

    int point = n-2;

    while(i<n-2){

        while(nums[i]!=i && nums[nums[i]]!=nums[i]){
            swap(nums[i],nums[nums[i]]);
        }
        if(nums[i]!=i) {swap(nums[point++],nums[i]);}
        else i++;

        // i++;
    }

    return {nums[n-2],nums[n-1]};
        
    }
};