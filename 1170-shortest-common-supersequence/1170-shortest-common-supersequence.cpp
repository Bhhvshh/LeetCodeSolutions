class Solution {
public:
    string shortestCommonSupersequence(string word1, string word2) {

        int n = word1.size() , m = word2.size();


        vector<vector<int>> dp(n+1,vector<int>(m+1));


        for(int i = 1;i<=n;i++)
         for(int j = 1;j<=m;j++){
            if(word1[i-1]==word2[j-1])
             dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

         }

         int l = n,r = m;
         string str ="";

         while(l>0 && r>0){
            if(dp[l-1][r]==dp[l][r]) l--;
            else if(dp[l][r-1]==dp[l][r])r--;
            else{ str+=word1[l-1];
            l--;
            r--;
            }
         }

         reverse(str.begin(),str.end());

         string ans = "";

         l = 0;
         r = 0;
         int id = 0;

         while(l<n && r<m){
           if(word1[l]!=str[id]){
                ans+=word1[l++];
            }
           else if(word2[r]!=str[id]){
                ans+=word2[r++];
            }
            else{
                ans+=word1[l];
                l++;
                r++;
                id++;
            }

         }

         while(l<n) ans+=word1[l++];
         while(r<m) ans+=word2[r++];

         return ans;






        
    }
};