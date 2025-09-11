class Solution {
public:
    string sortVowels(string s) {
        string tmp = "";

        for(auto x:s){
            if(x=='a' || x == 'A' || x =='e'|| x == 'E' || x == 'i' || x=='I' || x == 'o' || x == 'O' || x == 'u' || x == 'U')
            tmp.push_back(x);

        }

        sort(tmp.begin(),tmp.end());

        int i = 0;

        for(auto &x:s){
         if(x=='a' || x == 'A' || x =='e'|| x == 'E' || x == 'i' || x=='I' || x == 'o' || x == 'O' || x == 'u' || x == 'U')
            x = tmp[i++];

        }
         return s;
    }

   
};