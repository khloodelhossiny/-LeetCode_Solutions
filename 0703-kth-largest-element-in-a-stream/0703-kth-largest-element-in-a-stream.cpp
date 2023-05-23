#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

class KthLargest {
public:
     ordered_set st;
    int n;
    KthLargest(int k, vector<int>& nums) {
       for(auto i: nums){
           st.insert(i);
       }
        n = k;
       
    }
    
    int add(int val) {
        st.insert(val);
         int res = *(st.find_by_order(n - 1));
        return res;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */