class Solution {
public:
string likestring(string s){

    string ret = "";
    s = tolower(s);

    for(auto x:s){
        if(x=='a' || x == 'e' || x == 'i'|| x == 'o' || x == 'u') ret += "*";
        else ret+=x; 
    }
    return ret;
}
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        unordered_map<string,string> umap;
        for(auto x:wordlist){
            umap[x] = x;
            if(umap.find((tolower(x)+"#"))==umap.end()) umap[(tolower(x)+"#")] = x;
            if(umap.find(likestring(x))==umap.end()) umap[likestring(x)] = x;
            // cout << umap[likestring(x)] <<endl;
        }
        vector<string> ans;

        for(auto x:queries){
            if(umap.find(x)!=umap.end()) ans.push_back(x);
            else if(umap.find((tolower(x)+"#"))!=umap.end()) ans.push_back(umap[(tolower(x)+"#")]);
            else if( umap.find(likestring(x))!=umap.end()) ans.push_back(umap[likestring(x)]);
            else ans.push_back("");
        }


        return ans;
    }

    string tolower(string &s){
         std::string myString = s;

    // Use std::transform to apply ::tolower to each character
    std::transform(myString.begin(), myString.end(), myString.begin(), ::tolower);
    return myString;


    }
    

    // bool 
};