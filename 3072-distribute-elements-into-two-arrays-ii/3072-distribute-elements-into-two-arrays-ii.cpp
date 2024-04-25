
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>


// int greaterCount(map<double,int> m, double val){
//     int n = m.size();
//     auto it = m.upper_bound(val);
//     int k = distance(it, m.end());
//     return k;
// }

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        map<double, int> m1, m2;
        unordered_map<int,int> m3, m4;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        ordered_set order1, order2;
        order1.insert(nums[0]);
        order2.insert(nums[1]);
        for(int i = 2; i < n; i++){
            int a = order1.order_of_key(nums[i]), b = order2.order_of_key(nums[i]);
            if(a > b){
                order1.insert(nums[i]);
                arr1.push_back(nums[i]);
            }
            else if(a < b){
                order2.insert(nums[i]);
                arr2.push_back(nums[i]);
            }
            else{
                if(arr1.size() > arr2.size()){
                    order2.insert(nums[i]);
                    arr2.push_back(nums[i]);
                }
                else if(arr1.size() < arr2.size()){
                    order1.insert(nums[i]);
                    arr1.push_back(nums[i]);
                }
                else{
                    order1.insert(nums[i]);
                    arr1.push_back(nums[i]);
                }
            }
        }
        for(auto i: arr2)arr1.push_back(i);
        return arr1;
    }
};