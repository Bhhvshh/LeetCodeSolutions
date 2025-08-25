class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &a,const string &b){
            return a.size()<b.size();
        });
        for(auto x:words) cout<< x<<" ";


        int ans = 1;

        int n = words.size();

        vector<int> dp(n,1);

        for(int i = 0;i<n;i++){
            int max_ = 0;
            for(int j = i -1;j>=0;j--){
                if(pre(words[i],words[j])){
                    // cout << "here";
                    max_ = max(max_,dp[j]);

                }
            }
            // cout << max_ <<endl;
            dp[i]+=max_;
            ans = max(ans,dp[i]);
        }


        return ans;

        
    }

    bool pre(string &a,string &b){
        if(a.size()-1!=b.size()) return false;
        int count = 0;
        int i = 0, j = 0;

        for(;i<b.size() && j<a.size();i++,j++){
            if(a[j]!=b[i]){
                count++;
                i--;
            }
        }

         return count==1 || (count==0 && j==a.size()-1);
    }
};