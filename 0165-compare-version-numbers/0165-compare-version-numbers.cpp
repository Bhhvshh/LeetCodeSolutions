class Solution {
public:
    int compareVersion(string version1, string version2) {
        int var1 = 0 , var2 = 0;

        vector<int> n,m;
        for(auto x:version1){
            if(x=='.'){
                n.push_back(var1);
                var1 = 0;
            }
            else var1 = var1*10 + (x-'0');
        }
       n.push_back(var1);
        for(auto x:version2){
            if(x=='.'){
                m.push_back(var2);
                var2 = 0;
            }
            else var2 = var2*10 + (x-'0');
        }
        m.push_back(var2);

        for(int i  = 0;i<max(n.size(),m.size());i++){
           int a = (i<n.size()) ? n[i] : 0;
           int b = (i<m.size()) ? m[i] : 0;
            if(a<b) return -1;
            else if(a>b) return 1;
        }
        // cout << n.size()<<m.size()<<endl;

        // if (n.size()==m.size()) return 0;
        return 0;

        
        
    }
};