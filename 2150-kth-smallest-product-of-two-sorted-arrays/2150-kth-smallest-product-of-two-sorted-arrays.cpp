using int64 = long long;
class Solution {
public:

static inline int64 floor_div(int64 a, int64 b) {
    int64 q = a / b, r = a % b;
    return (r != 0 && ((r < 0) ^ (b < 0))) ? q - 1 : q;
}
static inline int64 ceil_div(int64 a, int64 b) {
    int64 q = a / b, r = a % b;
    return (r != 0 && !((r < 0) ^ (b < 0))) ? q + 1 : q;
}

// --- main ------------------------------------------------------------------
int64 countProductsLE(const vector<int>& A, const vector<int>& B, int64 target)
{
    /* bucketise B ---------------------------------------------------------- */
    vector<int64> negB, posB;
    int64 zeroB = 0;
    for (int64 v : B) {
        if (v < 0)      negB.push_back(v);
        else if (v == 0) ++zeroB;
        else            posB.push_back(v);
    }
    sort(negB.begin(), negB.end());   // ascending: …, -5, -2, -1
    sort(posB.begin(), posB.end());   // ascending:  1, 2, 5, …

    const int64 N_neg = static_cast<int64>(negB.size());
    const int64 N_pos = static_cast<int64>(posB.size());

    int64 total = 0;

    /* iterate over A ------------------------------------------------------- */
    for (int64 x : A)
    {
        if (x == 0) {                           // 0·b ≤ target ?
            if (target >= 0) total += B.size(); // 0 ≤ target ⇒ every b works
            continue;
        }

        /* 0‑bucket of B (if x ≠ 0) */
        if (target >= 0) total += zeroB;        // x·0 = 0 ≤ target

        if (x > 0) {
            /* ---- x is positive ------------------------------------------ */
            int64 bound = floor_div(target, x);          // largest b with x·b ≤ target

            /* b > 0 : need b ≤ bound */
            total += upper_bound(posB.begin(), posB.end(), bound) - posB.begin();

            /* b < 0 : same inequality b ≤ bound (bound may be negative) */
            total += upper_bound(negB.begin(), negB.end(), bound) - negB.begin();
        }
        else { // x < 0
            /* ---- x is negative ------------------------------------------ */
            int64 bound = ceil_div(target, x);           // smallest b with x·b ≤ target

            /* b > 0 : need b ≥ bound */
            total += posB.end() - lower_bound(posB.begin(), posB.end(), bound);

            /* b < 0 : need b ≥ bound (note bound may be negative or positive) */
            total += negB.end() - lower_bound(negB.begin(), negB.end(), bound);
        }
    }
    return total;
}

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n = nums1.size(), m = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long l = min({1LL * nums1[0] * nums2[0],
                           1LL * nums1[0] * nums2[m - 1],
                           1LL * nums1[n - 1] * nums2[0],
                           1LL * nums1[n - 1] * nums2[m - 1]});
        long long r = max({1LL * nums1[0] * nums2[0],
                           1LL * nums1[0] * nums2[m - 1],
                           1LL * nums1[n - 1] * nums2[0],
                           1LL * nums1[n - 1] * nums2[m - 1]});

        long long result = -1;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (countProductsLE(nums1, nums2, mid) >= k) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};
