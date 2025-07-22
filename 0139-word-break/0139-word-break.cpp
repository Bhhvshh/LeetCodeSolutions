class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> isPre;
        for(auto x:wordDict) isPre[x] = true;
        vector<int> memo(s.size(),-1);

        return helper(0,s,isPre,memo);

    }

    bool helper(int id,string &s,unordered_map<string,bool> &isPre,vector<int> &memo){
        if(id == s.size()) return true;
        if(memo[id]!=-1) return memo[id];

       string curr = "";
        for(int i = id;i<s.size();i++){
            curr+=s[i];
            if(isPre[curr] && helper(i+1,s,isPre,memo)) return memo[id] = true;

        }

        return memo[id] = false;
    }
};