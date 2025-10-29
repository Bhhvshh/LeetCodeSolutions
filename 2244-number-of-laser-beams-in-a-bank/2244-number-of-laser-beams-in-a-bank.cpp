class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count = 0, ans = 0;

        for(auto &x:bank){
            int curr = 0;
            for(auto y:x) if(y=='1') curr++;


            if(curr){
                ans+= count*curr;
                count = curr;
            }
        }


        return ans;
        
    }
};