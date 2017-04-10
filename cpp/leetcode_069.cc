class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        long long high = x / 2 + 1, low = 0, mid;
        long long multi;
        while (low + 1<high) {
            mid = low + (high - low) / 2;
            multi = mid*mid;
            if (multi == x) return mid;
            if (multi < x) low = mid;
            else high = mid;
        }
        if (multi < x) return mid;
        return low;
    }
};