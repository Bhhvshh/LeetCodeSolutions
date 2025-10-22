class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        
        vector<int> fr(26,0);
        vector<int> tarneed(26,0);

        for(auto x:s) fr[x-'a']++;
        for(auto x:target) tarneed[x-'a']++;


       // right to left to find latest index where lexicographically strictly greater string possible
        for(int i = n-1;i>=0;i--){

            tarneed[target[i]-'a']--;// keep needed freq from 0 to i-1 of target
          
           //try to make strictly greater on this index
            for(char j = target[i]+1;j<='z';j++){
                fr[j-'a']--;

                bool flag = true;
                for(int i = 0;i<26;i++) 
                if(fr[i]<tarneed[i]){
                    flag = false;
                    break;
                }

                if(flag) return builder(fr,tarneed,j,i,target);
                

               fr[j-'a']++;



            }


        }

        return "";
        
    }

    string builder(vector<int> &fr,vector<int> &tarneed,char curr,int id,string &tar){
        //up to id tar and ans is same, to make lex smallest 
        string ans = tar.substr(0,id);

        ans+=curr;  //index where it becomes greater

        for(int i = 0;i<26;i++) fr[i]-=tarneed[i];


       // use all remaining characters (use smaller first)
        int i = 0;
        while(i<26){
            if(fr[i]){
                ans+= ('a'+i);
                fr[i]--;
            }
            else i++;
        }


        return ans;
    }
};