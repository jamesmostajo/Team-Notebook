#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
int main(){
    ordered_set s;
    // s.insert()
    // s.order_of_key(v) : index of v OR index when v is inserted
    // s.find_by_order(i) : returns value at index i 
    return 0;
}
