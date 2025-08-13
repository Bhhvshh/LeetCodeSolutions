class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.size(),vector<int>(t.size(),-1));

        return helper(s,t,0,0,memo);



        
    }

    int helper(string &s,string &t,int i,int j,vector<vector<int>> &memo){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(memo[i][j]!=-1)return memo[i][j];
        
        int tmp = helper(s,t,i+1,j,memo);
        if(s[i]==t[j]) tmp+=helper(s,t,i+1,j+1,memo);

        return memo[i][j] = tmp;

    }
};