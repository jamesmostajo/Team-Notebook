struct Matrix {
	ll *a;
    int nr, nc;
	Matrix(int nr, int nc) {
        this->nr = nr;
        this->nc = nc;
		a = new ll[nr][nc];
        for (int i = 0; i < nr; i++) {
			for (int j = 0; j < nc; j++) {
				a[i][j] = 0;
			}
		}
	}
	Matrix operator *(Matrix other) {
		Matrix product = Matrix();
		for (int i = 0; i < nr; i++) {
			for (int j = 0; j < nc; j++) {
				for (int k = 0; k < other[0].size(); k++) {
					product.a[i][k] += a[i][j] * other.a[j][k];
					product.a[i][k] %= MOD;
				}
			}
		}
		return product;
	}
};

Matrix expo_power(Matrix a, ll n) {
	Matrix res = Matrix();
	res.a[0][0] = res.a[1][1] = 1;
	while(n) {
		if(n % 2) {
			res = res * a;
		}
		n /= 2;
		a = a * a;
	}
	return res;
}
