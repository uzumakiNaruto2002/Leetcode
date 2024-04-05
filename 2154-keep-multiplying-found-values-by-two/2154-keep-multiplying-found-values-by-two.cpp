class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        while(1){
            if(binary_search(nums.begin(), nums.end(), original)){
                original = original * 2;
            }
            else{
                return original;
            }
        }
        return 1;
    }
};