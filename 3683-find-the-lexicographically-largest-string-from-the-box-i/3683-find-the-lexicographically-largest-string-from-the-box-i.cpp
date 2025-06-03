class Solution {
public:
    string answerString(string word, int numFriends) {

        if(numFriends<=1) return word;
        int n = word.size();
        
        char  max_ = *max_element(word.begin(),word.end());

       
        
        string ans= "";


        for(int i =0;i<n ;i++){
            if(word[i]==max_){

                string str;
                if(i>=numFriends-1) str = word.substr(i);
                else str = word.substr(i,n-numFriends+1);
                ans = max(str,ans);

            }
        }

      

        return ans;

        
    }
};