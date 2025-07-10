class Solution {
public:
bool pal(string &s){
    for(int l = 0, r= s.size() - 1;l<r;l++,r--){
        if(s[l]!=s[r]) return false;

    }
     

    return true;

}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(0,ans,curr,s);

        return ans;
        
    }


    void backtrack(int id,vector<vector<string>> &ans,vector<string> &curr,string &s){
        if(id==s.size()){
            ans.push_back(curr);
        }
        string tmp ="";
        for(int i = id;i<s.size();i++){
            tmp+=s[i];
            if(pal(tmp)){
                curr.push_back(tmp);
                backtrack(i+1,ans,curr,s);
                curr.pop_back();
            }
        }

    }
};