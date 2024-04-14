class Solution {
public:
    long long flowerGame(int n, int m) {
        long long even1 = n/2, odd1 = n - even1, even2 = m/2, odd2 = m - even2;
        return even1 * odd2 + odd1 * even2;
    }
};