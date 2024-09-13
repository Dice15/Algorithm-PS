#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll mod = 998244353; // 119 * 2^23 + 1
const ll root = 3;        // 원시 근

ll mod_pow(ll a, ll b, ll m) {
    ll result = 1;
    while (b > 0) {
        if (b & 1) result = result * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return result;
}

void ntt(vector<ll>& a, bool invert) {
    int n = a.size();

    // 비트 반전 정렬
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;

        if (i < j) swap(a[i], a[j]);
    }

    // NTT 계산
    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = invert ? mod_pow(root, mod - 1 - (mod - 1) / len, mod) : mod_pow(root, (mod - 1) / len, mod);
        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; ++j) {
                ll u = a[i + j];
                ll v = a[i + j + len / 2] * w % mod;
                a[i + j] = (u + v) % mod;
                a[i + j + len / 2] = (u - v + mod) % mod;
                w = w * wlen % mod;
            }
        }
    }

    // 역변환 시 스케일링
    if (invert) {
        ll inv_n = mod_pow(n, mod - 2, mod);
        for (ll& x : a) x = x * inv_n % mod;
    }
}

vector<ll> multiply(vector<ll>& a, vector<ll>& b) {
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < n; ++i) fa[i] = fa[i] * fb[i] % mod;
    ntt(fa, true);

    return fa;
}

int main() {
    string A_str, B_str;
    cin >> A_str >> B_str;

    vector<ll> A, B;
    for (int i = A_str.size() - 1; i >= 0; --i) A.push_back(A_str[i] - '0');
    for (int i = B_str.size() - 1; i >= 0; --i) B.push_back(B_str[i] - '0');

    vector<ll> result = multiply(A, B);

    for (int i = 0; i < result.size(); ++i) {
        if (result[i] >= 10) {
            if (i + 1 == result.size()) result.push_back(0);
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    int i = result.size() - 1;
    while (i > 0 && result[i] == 0) --i;
    for (; i >= 0; --i) cout << result[i];
    cout << endl;

    return 0;
}
