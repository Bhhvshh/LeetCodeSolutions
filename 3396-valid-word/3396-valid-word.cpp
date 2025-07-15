class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;
        int vowels = 0, consonant = 0;

        for(auto x:word){
            if(x>=48 && x<=57) continue;
            else if(x>=65 && x<=90){
                if(x=='A' || x =='E' || x == 'I' || x == 'O' || x == 'U') vowels++;
                else consonant++;

            }
            else if(x>=97 && x<=122){
                if(x=='a' || x =='e' || x == 'i' || x == 'o' || x == 'u') vowels++;
                else consonant++;

            }


            else return false;
        }

        return (vowels>0) && (consonant > 0);
        
    }
};