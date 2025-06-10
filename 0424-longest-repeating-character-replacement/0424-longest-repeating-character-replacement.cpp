class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 1;
        vector<int> fr(26,0);
        fr[s[0]-'A']++;
        int l = 0;
        int max_ = 1;

        for(int i = 1;i<n;i++){

            max_ = max(max_,++fr[s[i]-'A']);

            while((i-l+1-max_)>k){
                fr[s[l++]-'A']--;
                for(auto x:fr)
                 max_ = max(max_,x);

            }
            ans= max(ans,i-l+1);

        }

        return ans;
        
    }
};