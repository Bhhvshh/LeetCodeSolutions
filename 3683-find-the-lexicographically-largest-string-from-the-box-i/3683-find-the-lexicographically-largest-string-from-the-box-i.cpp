class Solution {
public:
    string answerString(string word, int numFriends) {

        string copy = word;

        sort(copy.rbegin(),copy.rend());

       
        
        vector<string> ans;
        int n = word.size();
        if(numFriends<=1) return word;


        for(int i =0;i<n ;i++){
            if(word[i]==copy[0]){
                string str;
                if(i>=numFriends-1) str = word.substr(i);
                else str = word.substr(i,min(n-numFriends+1,n-i));
                ans.push_back(str);
            }
        }

        sort(ans.rbegin(),ans.rend());

        return ans[0];

        
    }
};