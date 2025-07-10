class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), ans = 0;

        for(int i = 0;i<n;i++){
            vector<int> fr(26);
            for(int j = i;j<n;j++){
                fr[s[j]-'a']++;
                int min_ = INT_MAX, max_ = 1;
                for(auto x:fr) if(x){ min_ = min(x,min_); max_ = max(max_,x);}

                ans+= (max_ - min_);

            }
        }


        return ans;
        
    }
};