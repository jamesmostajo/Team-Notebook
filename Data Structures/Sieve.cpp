MXN = 100000;
bool prime[MXN + 1];
void sieve()
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= MXN; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= MXN; i += p)
                prime[i] = false;
        }
    }
}
