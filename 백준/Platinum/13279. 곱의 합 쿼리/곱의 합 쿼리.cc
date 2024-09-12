
/*************************************************
*   Fast Fourier Transform (Cooley-Tukey Algorithm)
*   Time Complexity : o(NlogN)
*
*   Author : J.H Moon <jqkt15@naver.com>
*   Date : July 13, 2021
**************************************************/


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <complex>
#include <cmath>
#include <random>
using namespace std;

typedef complex<double> cpx;
typedef long long ll;

class Discrete_Fourier_Transform
{
public:
	vector<cpx> FFT(vector<cpx> a)
	{
		int N = (int)a.size();
		vector<cpx> A(N);

		// replace
		for (int i = 0; i < N; i++)
		{
			int div_sz = N, idx = i, re_idx = 0;

			while (div_sz >>= 1)          
			{
				if (idx & 1) re_idx += div_sz;   
				idx >>= 1;
			}

			A[re_idx + idx] = a[i];
		}


		// fft
		for (int sz = 2; sz <= N; sz <<= 1)
		{
			int sub_sz = sz / 2;

			for (int j = 0; j < N; j += sz)
			{
				double angle = -2.0 * acos(-1) / sz;
				cpx z = cpx(1, 0), w = cpx(cos(angle), sin(angle));

				for (int k = 0; k < sub_sz; k++)
				{
					cpx even = A[j + k], odd = A[j + k + sub_sz];
					z = cpx(cos(angle * k), sin(angle * k));

					A[j + k] = (even + (z * odd));
					A[j + k + sub_sz] = even - (z * odd);


				/*	cpx even = A[j + k], odd = A[j + k + sub_sz];
					A[j + k] = (even + (z * odd));
					A[j + k + sub_sz] = even - (z * odd);
					z *= w;*/
				}
			}	
		}

		return A;
	}


	vector<cpx> IFFT(vector<cpx>& A)
	{
		reverse(++A.begin(), A.end());
		vector<cpx> a = FFT(A);

		int N = (int)a.size();
		for (int i = 0; i < N; i++) a[i] /= cpx(N, 0);

		return a;
	}
};



// Solve //////////////////////////////////////////////////////////////////
vector<ll> Polynomial_Multiply(vector<ll>& p1, vector<ll>& p2)
{
	
	Discrete_Fourier_Transform dft;
	int N = 1 << ((int)ceil(log2((int)max(p1.size(), p2.size()))) + 1);

	vector<cpx> a(N), b(N), A, B;
	for (int i = 0; i < p1.size(); i++) a[i] = p1[i];
	for (int i = 0; i < p2.size(); i++) b[i] = p2[i];
	A = dft.FFT(a); B = dft.FFT(b);
	
	vector<cpx> c, C(N);
	for (int j = 0; j < N; j++) C[j] = A[j] * B[j];
	c = dft.IFFT(C);

	vector<ll> res(N);
	for (int j = 0; j < N; j++) res[j] = ((ll)round(c[j].real())) % (ll)100003;

	return res;
}


vector<ll> Divide_And_Conquer(int l, int r, vector<ll>& arr)
{
	if (l == r) return { arr[l] , 1 };

	int mid = (l + r) / 2;
	vector<ll> L = Divide_And_Conquer(l, mid, arr);
	vector<ll> R = Divide_And_Conquer(mid + 1, r, arr);

	return Polynomial_Multiply(L, R);
}



// BF Test Code ///////////////////////////////////////////////////////////////////////////
void Recursion(int index, ll mul, int cnt, vector<ll>& arr, vector<ll> &res)
{
	res[cnt] = (res[cnt] + mul) % (ll)100003;

	for (int i = index + 1; i < (int)arr.size(); i++)
		Recursion(i, (mul * arr[i]) % (ll)100003, cnt + 1, arr, res);	
}

vector<ll> Brute_Force(vector<ll> &arr)
{
	vector<ll> res((int)arr.size() + 1, 0);
	Recursion(-1, 1, 0, arr, res);
	return res;
}


bool Test()
{
	bool is_false = 0;

	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> N_dis(10, 20);
	uniform_int_distribution<int> A_dis(1, 100000);

	int N, Q, K;
	N = N_dis(gen);

	vector<ll> arr(N);
	for (int i = 0; i < N; i++) arr[i] = A_dis(gen);

	cout << N << '\n';
	for (int i = 0; i < N; i++) cout << arr[i] << ' '; cout << '\n';

	vector<ll> fft_res = Divide_And_Conquer(0, N - 1, arr);
	vector<ll> btf_res = Brute_Force(arr);

	uniform_int_distribution<int> Q_dis(N, N);
	uniform_int_distribution<int> K_dis(1, N);
	Q = Q_dis(gen);
	while (Q--)
	{
		K = K_dis(gen);
		cout << "K : " << K << " -> ";

		ll fft = fft_res[N - K];
		ll btf = btf_res[K];

		if (fft != btf) return false;

		cout << "<result : " << (fft == btf ? "True>" : "False>") << " FFT : " << fft << " vs " << "BTF : " << btf << '\n';
	}

	return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	/*for (int i = 0; i < 5000; i++)
	{
		if (!Test())
		{
			cout << "False!!!!!!!!!!!!!!!!!!!!!!!\n";
			break;
		}
	}*/

	int N, Q, K;
	cin >> N;

	vector<ll> arr(N);
	for (int i = 0; i < N; i++) cin >> arr[i];

	vector<ll> res = Divide_And_Conquer(0, N - 1, arr);

	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> K;
		cout << res[N - K] << '\n';
	}

	return 0;
}
