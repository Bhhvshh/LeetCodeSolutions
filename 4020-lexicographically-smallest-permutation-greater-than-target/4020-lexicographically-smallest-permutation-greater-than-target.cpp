class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        vector<int> fr(26,0);
        for(auto x:s) fr[x-'a']++;
        vector<int> tarneed(26,0);
        int n = s.size();

        for(auto x:target) tarneed[x-'a']++;

        for(int i = n-1;i>=0;i--){
            tarneed[target[i]-'a']--;

            for(char j = target[i]+1;j<='z';j++){
                fr[j-'a']--;
                bool flag = true;
                for(int i = 0;i<26;i++) if(fr[i]<tarneed[i]){
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
        string ans = tar.substr(0,id);
        ans+=curr;
        for(int i = 0;i<26;i++) fr[i]-=tarneed[i];

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