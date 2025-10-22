class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int,int> m;
        for(auto x:nums) m[x]++;

vector<long long> opt = {-k,0,k};


        vector<pair<long long,int>> vp;

        for(auto x:m){
            if(vp.size()) vp.push_back({x.first,vp.back().second+x.second});
            else vp.push_back(x);
        }

        int ans = 0;

        int min_ = vp[0].first;
        int max_ = vp[vp.size() - 1].first;


        for(int i = 0;i<vp.size();i++){
            for(auto x:opt){
                long long c = vp[i].first+x;

            auto it1 = lower_bound(vp.begin(),vp.end(),make_pair(c-k,-1));
            auto it2 = upper_bound(vp.begin(),vp.end(),make_pair(c+k,INT_MAX));
            it2--;
            int left = (it1 ==vp.begin()) ? 0: vp[(it1-vp.begin()-1)].second;
            int right = vp[it2-vp.begin()].second;
            int curr = m[c];

            ans = max(ans,min(curr+numOperations,right-left));
            }
        }


        return ans;
    }
};