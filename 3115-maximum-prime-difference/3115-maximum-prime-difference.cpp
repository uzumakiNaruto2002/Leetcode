class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int a = -1, b = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 2 || nums[i] == 3){
                a = i;
                break;
            }
            for(int j = 2; j <= int(sqrt(nums[i])); j++){
                if(nums[i] % j == 0){
                    break;
                }
                if(j == int(sqrt(nums[i]))){
                    a = i;
                    break;
                }
            }
            if(a != -1)break;
        }
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] == 2 || nums[i] == 3){
                b = i;
                break;
            }
            for(int j = 2; j <= int(sqrt(nums[i])); j++){
                if(nums[i] % j == 0){
                    break;
                }
                if(j == int(sqrt(nums[i]))){
                    b = i;
                    break;
                }
            }
            if(b != -1)break;
        }
        cout<<a<<' '<<b;
        return b - a;
    }
};