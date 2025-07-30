class Solution {
public:
    void inc(vector<int> &c, int num){
        for(int i = 0;i<31;i++){
            if(num & (1<<i)) c[i]++;
        }
    }
    void dec(vector<int> &c, int num){
        for(int i = 0;i<31;i++){
            if(num & (1<<i)) c[i]--;
        }
    }
    bool notequal(vector<int> &c,int num){
        for(int i = 0;i<31;i++){
            if( (num & (1<<i)) && !c[i]) return true;
        }

        return false;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {

        int r = 0;
        int n = nums.size();
        vector<int> ans(n,0);
        unordered_map<int,int> umap;

        for(int i = n-1;i>=0;i--){
            r|=nums[i];

            ans[i] = r;


     
        }


        vector<int>count(32);
        vector<int> res;


        for(int i = 0, l = 0;i<nums.size();i++){
            if(l==i){
                inc(count,nums[l]);
                l++;

            }


            while(l<n && notequal(count,ans[i])){
                inc(count,nums[l]);
                l++;
            }

            res.push_back(l-i);

            dec(count,nums[i]);



        }

        return res;
        
    }
};