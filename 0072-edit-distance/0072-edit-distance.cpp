class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size(),vector<int>(word2.size(),-1));

        return helper(word1,word2,0,0,memo);
        
    }


    long long helper(string &s1,string &s2,int id1,int id2,vector<vector<int>> &memo){
        if(id2==s2.size()) return s1.size() - id1;
        if(id1==s1.size()) return s2.size() - id2;
        if(memo[id1][id2]!=-1) return memo[id1][id2];

        long long t1 = (s1[id1]==s2[id2]) ? helper(s1,s2,id1+1,id2+1,memo) : INT_MAX;
        long long t2 = 1 + helper(s1,s2,id1,id2+1,memo);
        long long t3 = 1 + helper(s1,s2,id1+1,id2,memo);
        long long t4 = 1 + helper(s1,s2,id1+1,id2+1,memo);


        return memo[id1][id2] = min(min(t1,t2),min(t3,t4));
    }
};