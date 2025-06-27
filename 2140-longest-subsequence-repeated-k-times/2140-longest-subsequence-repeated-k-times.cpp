class Solution {
public:
 bool ksubseq(string &s,string &curr,int &k){
    int count = 0;
    int p1 = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i]==curr[p1]) p1++;
        if(p1==curr.size()){
            p1 = 0;
            count++;
        }

    }

    return count>=k;
 }
    string longestSubsequenceRepeatedK(string s, int k) {
        int size = s.size()/k;

        string ans = "";
        backtrack(size,s,"",k,ans);

        return ans;
        
    }

    void backtrack(int size,string &s,string curr,int &k,string &ans){
        if(ksubseq(s,curr,k)){
            if(curr.size()>=ans.size()) ans = curr;
        }
        else return;

        if(!size) return;



        for(char c = 'a';c<='z';c++){
           
            curr.push_back(c);
            backtrack(size-1,s,curr,k,ans);
            curr.pop_back();
        }
    }
};  