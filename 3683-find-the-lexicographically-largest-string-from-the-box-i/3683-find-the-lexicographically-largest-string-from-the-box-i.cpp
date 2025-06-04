
class Solution {
public:
    string answerString(string word, int numFriends) {

        if(numFriends<=1) return word;
        int n = word.size();
        
      
        string ans= "";

        for(int i =0;i<n ;i++)
    {
         string str = word.substr(i,min(n-numFriends+1,n-i));
               
                ans = max(str,ans);
    }

               

          
       

        return ans;

        
    }
};