class Solution {
public:
    int longestBalanced(string s) {
        int  n =s.size();
        int ans = 0;

        for(int i = 0;i<n;i++){
            vector<int> fr(26,0);
            for(int j = i;j<n;j++){
                fr[s[j]-'a']++;
                bool flag = true;
                int last = -1;
               for(int k = 0;k<26;k++){
                   if(last==-1 && fr[k]) last=fr[k];
                   else if(last!=-1 && fr[k] && fr[k]!=last) {
                       flag = false;
                       break;
                   }
               }

                if(flag) {
                    // cout<<"her";
                          ans = max(j-i+1,ans);}
                
                
            }
        }


        return ans;
        
    }
};