class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";

        for(int i = 0;i<num.size()-2;i++){
            string tmp(1,num[i]);
            for(int j = i+1;j<i+3;j++){
                if(num[j]!=tmp.back()) break;
                tmp+=num[j];
            }
            if(tmp.size()==3 && tmp>ans) ans = tmp;

        }

        return ans;
        
    }
};