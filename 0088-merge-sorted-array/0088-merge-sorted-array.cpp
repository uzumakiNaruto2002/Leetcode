class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        if(n == 0){
            nums1 = nums2;
            return;
        }
        for(int i = n; i < m + n; i++){
            nums1[i] = nums2[i - n];
        }
        int i = n - 1, j = n;
        while(i >= 0 && j < m + n){
            if(nums1[i] <= nums1[j]){
                break;
            }
            else{
                swap(nums1[i], nums1[j]);
                i--;
                j++;
            }
        }
        sort(nums1.begin(), nums1.begin() + n);
        sort(nums1.begin() + n, nums1.end());
    }
};