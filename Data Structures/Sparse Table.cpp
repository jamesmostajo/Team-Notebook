struct sparse_table {
    int n, J; // size, max jump
    vector<vector<int>> lookup;
    function<int(int, int)> op;
    sparse_table(vector<int>& a, function<int(int, int)> op) {
        n = a.size();
        J = (int)log2(n);
        this->op = op;
        lookup.assign(n, vector<int>(J+1));
        for (int i = 0; i < n; i++) lookup[i][0] = a[i];

        for (int j = 1, p2 = 1; j <= J; j++, p2 <<= 1) {
            for (int i = 0; i < n; i++) {
                lookup[i][j] = op(lookup[i][j-1], lookup[min(n-1, i+p2)][j-1]);
            }
        }
    }

    int query_RMQ(int l, int r) {
        assert(0 <= l && l < n && 0 <= r && r < n);
        int sz = (int)log2(r-l+1);
        return op(lookup[l][sz], lookup[r - ((1 << sz) - 1)][sz]);
    }
};
