class Solution {
public:
  bool satisfy(vector<int> &fr){
    for(auto x:fr) if(x>0) return false;

    return true;
  }
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        if(t.empty()) return "";

        vector<int> fr(128,0);
        for(auto x:t) fr[x]++;
        string ans = "";

        for(int i = 0, l = 0;i<s.size();i++){
            fr[s[i]]--;

            while(satisfy(fr)){
                fr[s[l++]]++;
            }

            if(l>0){
                if(ans== "" || (i-l+2 < ans.size())) ans = s.substr(l-1,i-l+2);
            }

        }


        return ans;
        
    }
};