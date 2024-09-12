/*#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

class SegmentTree {
public:
	int _TreeSize, _Depth, _LeafBegin;
	vector<ll> _SegArray;

	SegmentTree(int Size = 0) { Assign(Size); }

	void Assign(int Size = 0) {
		_Depth = ceil(log2(Size)) + 1;
		_LeafBegin = 1 << (_Depth - 1);
		_TreeSize = 1 << _Depth;
		_SegArray.assign(_TreeSize, 0);
	}

	ll& operator[](int idx) { return _SegArray[_LeafBegin + idx]; }

	void Init() {
		for (int i = _LeafBegin - 1; i > 0; i--)
			_SegArray[i] = _SegArray[i * 2] + _SegArray[i * 2 + 1];
	}

	void Update(int idx, int val) {
		idx += _LeafBegin;
		_SegArray[idx] = val;
		idx /= 2;
		while (idx > 0) {
			_SegArray[idx] = _SegArray[idx * 2] + _SegArray[idx * 2 + 1];
			idx /= 2;
		}
	}

	ll Query(int obtL, int obtR) { return QuerySub(obtL, obtR, 1, 0, _LeafBegin - 1); }
	ll QuerySub(int obtL, int obtR, int idx, int curL, int curR) {	
		if (obtR < curL || curR < obtL) return 0;
		if (obtL <= curL && curR <= obtR) return _SegArray[idx];
		int mid = (curL + curR) / 2;
		return QuerySub(obtL, obtR, idx * 2, curL, mid) + QuerySub(obtL, obtR, idx * 2 + 1, mid + 1, curR);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll N, M, K, a, b, c;

	cin >> N >> M >> K;

	SegmentTree st(N);
	for (int i = 0; i < N; i++) cin >> st[i];
	st.Init();

	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			st.Update(--b, c);
		}
		else if (a == 2) {
			cout << st.Query(--b, --c) << '\n';
		}
	}

	return 0;
}*/



#include <bits/stdc++.h>
using namespace std;
using ll = long long;


template <typename datatype>
class SegmentTree
{
public:
	datatype mDefaultVal;

	int mRoot;                    // 트리 루트
	int mDepth;                   // 트리 깊이
	int mLeafBegin;               // 리프노드 시작 위치 (leaf idx is 0-base)
	int mSize;                    // 트리 크기
	vector<datatype> mSegTable;   // 트리의 값을 저장하는 테이블


public:
	SegmentTree() {}
	SegmentTree(datatype defVal, int segSize) { Assign(defVal, segSize); }

	datatype& operator [](int leafNum) { return mSegTable[mLeafBegin + leafNum]; }

	void Insert(int leafNum, datatype val) { mSegTable[mLeafBegin + leafNum] = val; }

	void Assign(datatype defVal, int segSize) {
		mDefaultVal = defVal;
		mRoot = 1;
		mDepth = ceil(log2(segSize)) + 1;
		mLeafBegin = 1 << (mDepth - 1);
		mSize = 1 << mDepth;
		mSegTable.assign(mSize, mDefaultVal);
	}


public:
	// 연산 함수
	datatype Operation(datatype fst, datatype snd) {
		return fst + snd;
	}

	// 모든 리프에 대해 업데이트
	void UpdateAll() {
		for (int idx = mLeafBegin - 1; idx > 0; idx--) {
			mSegTable[idx] = Operation(mSegTable[idx << 1], mSegTable[(idx << 1) + 1]);
		}
	}

	// 특정 리프에 대해 업데이트
	void Update(int leafNum, datatype val) {
		int idx = mLeafBegin + leafNum;
		mSegTable[idx] = val;
		while (idx > mRoot) {
			idx >>= 1;
			mSegTable[idx] = Operation(mSegTable[idx << 1], mSegTable[(idx << 1) + 1]);
		}
	}

	// 쿼리 수행 (param is left <= right)
	datatype ProcessQuery(int left, int right) {
		if (left > right) swap(left, right);
		return SearchRange(left, right, mRoot, 0, mLeafBegin - 1);
	}
	datatype SearchRange(int L, int R, int idx, int curL, int curR) {
		if (R < curL || curR < L) return mDefaultVal;
		if (L <= curL && curR <= R) return mSegTable[idx];
		int mid = (curL + curR) >> 1;
		return Operation(SearchRange(L, R, idx << 1, curL, mid), SearchRange(L, R, (idx << 1) + 1, mid + 1, curR));
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll N, M, K, a, b, c;

	cin >> N >> M >> K;

	SegmentTree<ll> st(0, N);
	for (int i = 0; i < N; i++) cin >> st[i];
	st.UpdateAll();

	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			st.Update(--b, c);
		}
		else if (a == 2) {
			cout << st.ProcessQuery(--b, --c) << '\n';
		}
	}

	return 0;
}