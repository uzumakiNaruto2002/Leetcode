class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size(), count = 1, score = nums[0] + nums[1];
        for(int i = 2; i < n; i+=2){
            int a = nums[i];
            if(i + 1 < n){
                int b = nums[i + 1];
                if(a + b == score)count++;
                else break;
            }
        }
        return count;
    }
};