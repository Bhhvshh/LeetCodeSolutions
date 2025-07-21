class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int count = 1;
        for(auto x:s){
            if(ans.empty() || ans.back()!=x)count=1;
            else count++;
            
            if(count<3) ans.push_back(x);
        }


        return ans;
        
    }
};