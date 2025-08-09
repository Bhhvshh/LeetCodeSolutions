class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> index;
        for(int i = 0;i<nums.size();i++) index[nums[i]] = true;

        unordered_map<int,int> sequence;

        int ans = 0;

        for(int i = 0;i<nums.size();i++){
            // if(sequence[nums[i]]) continue;
            ans = max(ans,helper(sequence,index,nums[i]));

        }

        return ans;
        
    }

    int helper(unordered_map<int,int> &seq,unordered_map<int,bool> &id, int num){
        if(id.find(num)==id.end()) return 0;
        if(seq[num]) return seq[num];
        return seq[num] = 1 + helper(seq,id,num+1);


    }
};