#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> small_primes;

const int MXN = 1e6;
bool prime[MXN + 1];

void sieve(){
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= MXN; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= MXN; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= MXN; p++){
        if (prime[p]) small_primes.push_back(p);
    }
}

ll modPow(ll x, ll y, ll mod) {
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res % mod;
}
 
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
 
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

ll mod_inverse(ll a, ll p) {
    ll x, y;
    ll d = extended_gcd(a, p, x, y);
    if (d != 1)
        return -1;
    return (x % p + p) % p;
}

bool miller_rabin(ll n, int iters = 3) {
    if (n < 2) return false;
    for (int p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31})
        if (n % p == 0) return n == p;
    
    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    
    for (int i = 0; i < iters; i++) {
        ll a = rand() % (n - 2) + 2;
        ll x = modPow(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool cont = false;
        for (int r = 0; r < s - 1; r++) {
            x = modPow(x, 2, n);
            if (x == n - 1) {
                cont = true;
                break;
            }
        }
        if (!cont)
            return false;
    }
    return true;
}

ll pollards_rho(ll n) {
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;
    if (n % 5 == 0) return 5;
    
    while (true) {
        ll c = rand() % (n - 1) + 5;
        auto f = [n, c](ll x) {
            return (modPow(x, 2, n) + c) % n;
        };
        ll x = 2, y = 2, d = 1;
        while (d == 1) {
            x = f(x);
            y = f(f(y));
            d = gcd(abs(x - y), n);
        }
        if (d != n)
            return d;
    }
}

void factorize_big(map<ll, int>& factors, ll n){
    if (n == 1) return;
    if (miller_rabin(n)) {
        factors[n]++;
        return;
    }
    ll d = pollards_rho(n);
    factorize_big(factors, d);
    factorize_big(factors, n / d);
}

void factorize(map<ll, int>& factors, ll n){
    for (auto p : small_primes){
        if (p*p > n) break;
        while (n%p==0){
            factors[p]++;
            n /= p;
        }
    }
    
    if (n > 1) factorize_big(factors, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    sieve();

    return 0;
}
