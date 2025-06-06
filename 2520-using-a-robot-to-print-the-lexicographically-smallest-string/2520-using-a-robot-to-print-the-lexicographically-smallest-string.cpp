class Solution {
public:
    string robotWithString(string s) {
        
        vector<int> fr(26);
        for(auto x:s) fr[x-'a']++;

        string t  = "", ans = "";

        for(int i = 0;i<s.size();i++){
            int min_ = INT_MAX;

             for(int j =0;j<26;j++)
                if(fr[j]){
                    min_ = j;
                    break;
                }
            
             while(!t.empty() && t.back()<= ('a'+min_)){
                 ans.push_back(t.back());
                 t.pop_back();

             }

             if(s[i]== ('a'+min_)) ans.push_back(s[i]);
             else t.push_back(s[i]);

             fr[s[i]-'a']--;
        }

        while(!t.empty()){
            ans.push_back(t.back());
            t.pop_back();
        }


        return ans;
    }
};