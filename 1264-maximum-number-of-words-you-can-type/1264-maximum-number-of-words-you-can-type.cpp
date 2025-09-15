class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,bool>umap;
        for(auto x:brokenLetters) umap[x] = true;

        int ans = 0;

        bool flag = true;
        for(auto x:text){
            if(x==' '){
                ans+=flag;
                flag = true;
            }
            else if(umap[x]) flag = false;
        }

        ans+=flag;

        return ans;


        
    }
};