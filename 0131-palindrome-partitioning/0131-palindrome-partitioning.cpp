class Solution {
public:
// bool pal(string &s){
//     for(int l = 0, r= s.size() - 1;l<r;l++,r--){
//         if(s[l]!=s[r]) return false;

//     }
     

//     return true;

// }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        vector<vector<bool>> dp(s.size(),vector<bool> (s.size()));
        for(int i = 0;i<s.size();i++){
            for(int j = 0;j<=i;j++){
                if(i==j) dp[j][i] = 1;
                else if(s[i]!=s[j]) dp[j][i] = false;
                else dp[j][i] =(i==j+1) ? true: dp[j+1][i-1];

            }
        }
        backtrack(0,ans,curr,s,dp);

        return ans;
        
    }


    void backtrack(int id,vector<vector<string>> &ans,vector<string> &curr,string &s,vector<vector<bool>> &dp){
        if(id==s.size()){
            ans.push_back(curr);
        }
        
        for(int i = id;i<s.size();i++){
            
            if(dp[id][i]){
                curr.push_back(s.substr(id,i-id+1));
                backtrack(i+1,ans,curr,s,dp);
                curr.pop_back();
            }
        }

    }
};