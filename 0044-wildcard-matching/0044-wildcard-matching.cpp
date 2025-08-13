class Solution {
public:
    bool isMatch(string s, string p) {

        vector<vector<int>> memo(s.size()+1,vector<int>(p.size()+1,-1));


        return helper(s,p,0,0,memo);
        
    }

    bool helper(string &s, string &p,int i,int j,vector<vector<int>> &memo){
        if(i==s.size() || j ==p.size()){if( i==s.size() &&j==p.size()) return true;
        if(i==s.size()){
            for(int k = j;k<p.size();k++) if(p[k]!='*') return false;
            return true;
        }
        }
        if(memo[i][j]!=-1) return memo[i][j]; 

        bool res;
        
        if(s[i]==p[j] || p[j]=='?') res = helper(s,p,i+1,j+1,memo);
        else if (p[j]=='*'){
            res = false;
            for(int k = i;k<=s.size();k++) res|=(memo[k][j+1] = helper(s,p,k,j+1,memo));
        }
        else res = false;

        return memo[i][j] = res;

    }
};