class Solution {
    public int numberOfSets(int n, int k) {
        long MOD = 1_000_000_007;
        int N = n + k - 1;
        int R = 2 * k;

        if(R > N) return 0;

        long num = 1, den = 1;
        for(int i = 1; i <= R; i++){
            num = (num * (N - i + 1)) % MOD;
            den = (den * i) % MOD;
        }
        return (int) (num * modInverse(den, MOD) % MOD);
    }
    private long modInverse(long a, long m){
        return power(a, m - 2, m);
    }
    private long power(long base, long exp, long mod){
        long res = 1;
        base %= mod;
        while(exp > 0){
            if(exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
}