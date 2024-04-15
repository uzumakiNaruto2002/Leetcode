class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];
        if(a + b <= c || abs(a - b) >= c || a + c <= b || abs(a - c) >= b || b + c <= a || abs(b - c) >= a)return "none";
        if(a == b && b == c)return "equilateral";
        if(a != b && b != c && a != c)return "scalene";
        return "isosceles";
    }
};