//bryan
template <typename T>
struct segtree {
    int n;
    vector<T> vals;
    vector<T> d_add;
    vector<T> d_set;
    segtree(vector<T> &ar) {
        n = ar.size();
        vals.resize(4*n);
        d_add.assign(4*n, 0);
        d_set.assign(4*n, 0);
        build(ar, 1, 0, n-1);
    }
    
    void build(vector<T> &ar, int p, int i, int j) {
        if (i == j) {
            vals[p] = ar[i];
        }
        else {
            int k = (i + j) / 2;
            build(ar, p<<1, i, k);
            build(ar, p<<1|1, k+1, j);
            pull(p);
        }
    }
    
    void pull(int p) {
        vals[p] = vals[p<<1] + vals[p<<1|1];
    }

    void push_add(int p, int i, int j) {
        if (d_add[p]) { 
            vals[p] += (j - i + 1) * d_add[p];
            if (i != j) {
                d_add[p<<1] += d_add[p];
                d_add[p<<1|1] += d_add[p];
            }
            d_add[p] = 0;
        }
    }

    // i, j starts at 0, n-1
    void update_add(int _i, int _j, T v, int p, int i, int j) {
        push_add(p, i, j);
        // query overlaps or equates i, j
        if (_i <= i && j <= _j) {
            d_add[p] += v;
            push_add(p, i, j);
        }
        // no overlap
        else if (_j < i || j < _i) {}
        else {
            int k = (i + j) / 2;
            update_add(_i, _j, v, p<<1, i, k);
            update_add(_i, _j, v, p<<1|1, k+1, j);
            pull(p);
        }
    }

    void push_set(int p, int i, int j) {
        if (d_set[p]) { 
            vals[p] = (j - i + 1) * d_set[p];
            if (i != j) {
                d_set[p<<1] = d_set[p];
                d_set[p<<1|1] = d_set[p];
            }
            d_set[p] = 0;
        }
    }

    // i, j starts at 0, n-1
    void update_set(int _i, int _j, T v, int p, int i, int j) {
        push_set(p, i, j);
        // query overlaps or equates i, j
        if (_i <= i && j <= _j) {
            d_set[p] = v;
            push_set(p, i, j);
        }
        // no overlap
        else if (_j < i || j < _i) {}
        else {
            int k = (i + j) / 2;
            update_set(_i, _j, v, p<<1, i, k);
            update_set(_i, _j, v, p<<1|1, k+1, j);
            pull(p);
        }
    }

    T query_add(int _i, int _j, int p, int i, int j) {
        push_add(p, i, j);
        if (_i <= i && j <= _j)
            return vals[p];
        else if (_j < i || j < _i)
            return 0;
        else {
            int k = (i + j) / 2;
            return  query_add(_i, _j, p<<1, i, k) +
                    query_add(_i, _j, p<<1|1, k+1, j);
        }
    }
    T query_set(int _i, int _j, int p, int i, int j) {
        push_set(p, i, j);
        if (_i <= i && j <= _j)
            return vals[p];
        else if (_j < i || j < _i)
            return 0;
        else {
            int k = (i + j) / 2;
            return  query_set(_i, _j, p<<1, i, k) +
                    query_set(_i, _j, p<<1|1, k+1, j);
        }
    }

    void update_add(int _i, int _j, T v) {
        update_add(_i, _j, v, 1, 0, n-1);
    }

    void update_set(int _i, int _j, T v) {
        update_set(_i, _j, v, 1, 0, n-1);
    }

    T query_add(int _i, int _j) {
        return query_add(_i, _j, 1, 0, n-1);
    }
    T query_set(int _i, int _j) {
        return query_set(_i, _j, 1, 0, n-1);
    }
};
