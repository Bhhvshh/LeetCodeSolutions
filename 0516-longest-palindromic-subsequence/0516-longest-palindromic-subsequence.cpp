class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> memo(n,vector<int>(n,-1));

        return helper(s,0,n-1,memo);
        
    }

    int helper(string &s,int l,int r,vector<vector<int>> &memo){
        if(l>r) return 0;
        if(l==r) return 1;
        if(memo[l][r]!=-1) return memo[l][r];
        if(s[l]==s[r]){
            return memo[l][r] =  max(2+helper(s,l+1,r-1,memo),max(helper(s,l+1,r,memo),helper(s,l,r-1,memo)));
        }
        return memo[l][r] = max(helper(s,l+1,r,memo),helper(s,l,r-1,memo));
    }
};