class Fancy {
public:
    const long MOD = 1000000007;

    vector<long> vals;
    long a = 1;   // multiplier
    long b = 0;   // addition

    long modPow(long x, long n) {
        long res = 1;
        x %= MOD;
        while (n > 0) {
            if (n & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            n >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long x = (val - b + MOD) % MOD;
        x = (x * modPow(a, MOD - 2)) % MOD; // inverse of a
        vals.push_back(x);
    }

    void addAll(int inc) {
        b = (b + inc) % MOD;
    }

    void multAll(int m) {
        a = (a * m) % MOD;
        b = (b * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= vals.size()) return -1;
        return (a * vals[idx] + b) % MOD;
    }
};