struct linked_list{
    ll sz;
    vector<ll> data;
    vector<ll> left;
    vector<ll> right;
 
    void construct(vector<ll> arr){
        this->sz = (arr.size());
        data.resize(sz);
        for (ll i=0; i<sz; i++){
            data[i] = arr[i];
        }
 
        left.resize(sz);
        right.resize(sz);
 
        left[0] = -1;
        right[0] = 1;
        left[sz-1] = sz-2;
        right[sz-1] = -1;
 
        for (ll i=1; i<(sz-1); i++){
            left[i] = i-1; right[i] = i+1;
        }
    }
 
    void modify(ll indx, ll val){
        data[indx] = val;
    }
 
    void remove(ll indx){
        if (right[indx] != -1) left[right[indx]] = left[indx];
        if (left[indx] != -1) right[left[indx]] = right[indx];
    }
 
    ll get(ll indx){
        return data[indx];
    }
 
    bool left_is_blank(ll indx){
        return left[indx] == -1;
    }
 
    bool right_is_blank(ll indx){
        return right[indx] == -1;
    }
 
    ll get_left_indx(ll indx){
        return left[indx];
    }
 
    ll get_right_indx(ll indx){
        return right[indx];
    }
};
