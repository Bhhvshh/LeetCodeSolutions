class FindSumPairs {
public:
   vector<int> n1,n2;
   unordered_map<int,int> umap;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;

        for(auto x:n2){
            umap[x]++;
        }
        
    }
    
    void add(int index, int val) {
        umap[n2[index]]--;
        umap[(n2[index]+=val)]++;
    }
    
    int count(int tot) {
        int ans = 0;

        for(int i = 0;i<n1.size();i++){
            ans+=umap[tot - n1[i]];

        }

        return ans;
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */