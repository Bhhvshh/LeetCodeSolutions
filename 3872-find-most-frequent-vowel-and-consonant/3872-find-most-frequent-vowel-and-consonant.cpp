class Solution {
public:
    int maxFreqSum(string s) {
        int v = 0, c = 0;
        vector<int> fr(26,0);
        for(auto &x:s)fr[x-'a']++;


        for(char i = 'a';i<='z';i++){
            if(i =='a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' ){
                v = max(v,fr[i-'a']);

            }
            else{
                c = max(c,fr[i-'a']);
            }
        }


        return c+v;


    }
};