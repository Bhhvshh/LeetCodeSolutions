using ll = __int128;
class Solution {
public:
  vector<string> o = {"0","1","2","3","4","5","6","7","8","9"};
  vector<string> e = {"00","11","22","33","44","55","66","77","88","99"
  };

  bool isbaseKPal(ll num,int base){

      vector<int> pal;

      while(num){
        pal.push_back((num%base));
        num/=base;
      }
      int l = 0, r= pal.size() - 1;

      while(l<r){
        if(pal[l++]!=pal[r--]) return false;
      }

      return true;

  }
    long long kMirror(int k, int n) {

        long long ans = 0;

        for(int i = 1;i<o.size() && n;i++){
            int curr  = stoi(o[i]);
            if(isbaseKPal(curr,k)) {ans+=curr; n--;}

        }

        for(int i = 1;i<e.size() && n;i++){
            int curr  = stoi(e[i]);
            if(isbaseKPal(curr,k)) {ans+=curr; n--;}

        }

        while(n){
            vector<string> newO;
            for(char c = '0';c<='9';c++){

                for(int i = 0;i<o.size() && n;i++){
                    string tmp = c+o[i]+c;
                    newO.push_back(tmp);
                    if(c=='0') continue;

                    ll curr = stoll(tmp);
                    if(isbaseKPal(curr,k)){ans+=curr; n--;}
                }


            }

            o = newO;
            vector<string> newE;

             for(char c = '0';c<='9';c++){
                for(int i = 0;i<e.size() && n;i++){
                    string tmp = c+e[i]+c;
                    newE.push_back(tmp);
                    if(c=='0') continue;
                    ll curr = stoll(tmp);
                    if(isbaseKPal(curr,k)){ans+=curr; n--;}
                }

            }
            e = newE;


        }

        return ans;


        
    }
};