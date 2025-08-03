class Solution
{
    public:
        bool can(int &mid, vector<int> &o, string &s, int &k)
        {
            vector<int> v;
            int n = s.size();
            for (int i = 0; i < mid; i++)
            {
                v.push_back(o[i]);
            }
            sort(v.begin(), v.end());

            long long count = 0;
            int last = -1;
            for (int i = 0; i < mid; i++)
            {
                count += (long long)(v[i] - last) *(n - v[i]);
                last = v[i];
               	// cout<<last <<"loop"<<count<<endl;
            }
           	// cout << mid << " "<< (count) << endl;

            return count >= k;
        }

    int minTime(string s, vector<int> &order, int k)
    {
        int n = order.size();
        if (k > (long long)(n + 1) *n / 2) return -1;

        int result = -1;
        int l = 1, r = n;

        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);

            if (can(mid, order, s, k))
            {
                result = mid - 1;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return result;
    }
};