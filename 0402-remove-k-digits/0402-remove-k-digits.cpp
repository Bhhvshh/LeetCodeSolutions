class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int id = 0;
        deque<int> q;
        int count = 0;
        vector<int> v;
        int last = num.size();
        
        for(int i = 0;i<num.size();i++){
            while(q.size() && num[q.back()]>num[i]) q.pop_back();

            q.push_back(i);
            count++;

            if(count==k+1){
                k-=(q.front()- ((v.empty()) ? 0: v.back()+1));
                v.push_back(q.front());
                count = i-q.front();
                last = q.front();
                q.pop_front();

            }

        }

        for(auto x:v)if(ans.size() || num[x]!='0') ans+=num[x];

        for(int i = last+1;i<num.size();i++)
         if((ans.size() || num[i]!='0') && !(k--))
           ans+=num[i];




        return ans.size() ? ans: "0";
        
    }

};