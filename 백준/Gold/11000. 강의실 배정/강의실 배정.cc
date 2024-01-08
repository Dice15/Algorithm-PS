
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>&a, const pair<int, int>& b)
{
	if (a.second < b.second) return true;
	else if (a.second == b.second) return a.first < b.first;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int,int>> conf(N, pair<int, int>());
	priority_queue<int, vector<int>, greater<int>> prevEnd;

	for (int i = 0; i < N; i++)
		cin >> conf[i].first >> conf[i].second;
	sort(conf.begin(), conf.end());

	prevEnd.push(0);
	for (auto &info : conf)
	{
		int prev = prevEnd.top();

		if (prev <= info.first)
			prevEnd.pop();

		prevEnd.push(info.second);

	}

	cout << prevEnd.size() << '\n';

	return 0;
}