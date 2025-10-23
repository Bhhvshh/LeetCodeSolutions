class Solution {
public:
    bool hasSameDigits(string s) {
        // int last = s[0] - '0';
        string ans = repeat(s);
        // cout << ans;

        return ans[0]==ans[1];

      
        
        
    }

   string repeat(string s){
       if(s.size()<=2) return s;

       string st = "";
       for(int i = 0;i<s.size()-1;i++){
           st += ((s[i]-'0')+(s[i+1]-'0'))%10  + '0';
       }

       return repeat(st);
    //    return s;
   }
};