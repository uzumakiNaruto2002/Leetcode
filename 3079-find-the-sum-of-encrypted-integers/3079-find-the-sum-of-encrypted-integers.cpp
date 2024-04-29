class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 0; i < n; i++){
            int maxi = 0;
            string s = to_string(nums[i]);
            for(int j = 0; j < s.size(); j++){
                int x = s[j] - '0';
                maxi = max(x, maxi);
                cout<<maxi<<' ';
            }
            int t = 0;
            for(int j = 0; j < s.size(); j++){
                t = t * 10 + maxi;
            }
            sum = sum + t;
        }
        return sum;
    }
};