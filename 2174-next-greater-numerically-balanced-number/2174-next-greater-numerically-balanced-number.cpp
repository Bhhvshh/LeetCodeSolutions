class Solution {
public:
    int nextBeautifulNumber(int n) {
        n++;
        while(true){
            int curr = n;
            vector<int> v(10,0);

            while(curr){
                v[curr%10]++;
                curr/=10;
            }

            bool flag = true;
            for(int i = 0;i<=9;i++){
                if(!(v[i]==0 || v[i]==i)){
                    flag = false;
                    break;
                }
            }

            if(flag) return n;
            n++;
        }


        return n;
        
    }
};