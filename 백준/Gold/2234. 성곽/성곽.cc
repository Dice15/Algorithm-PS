#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> field, groupNum, roomSize;
vector<pair<int, int>> moves = { {0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int isBlock(int val, int dir) {
	return val & (1 << dir);
}

void dfs1(int group, int x, int y, int& cnt) {
	if (groupNum[x][y] > 0) return;
	groupNum[x][y] = group;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nextX = x + moves[i].first, nextY = y + moves[i].second;
		if (!(0 <= nextX && nextX < n && 0 <= nextY && nextY < m)) continue;
		if (isBlock(field[x][y], i)) continue;
		dfs1(group, nextX, nextY, cnt);
	}
}

void dfs2(int group, int x, int y, int cnt) {
	if (roomSize[x][y] > 0) return;
	roomSize[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nextX = x + moves[i].first, nextY = y + moves[i].second;
		if (!(0 <= nextX && nextX < n && 0 <= nextY && nextY < m)) continue;
		if (isBlock(field[x][y], i)) continue;
		dfs2(group, nextX, nextY, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	field.assign(n, vector<int>(m, 0));
	groupNum.assign(n, vector<int>(m, 0));
	roomSize.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> field[i][j];

	int group = 1, maxRoom = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (groupNum[i][j] > 0) continue;
			int size = 0;
			dfs1(group, i, j, size);
			dfs2(group++, i, j, size);
			maxRoom = max(maxRoom, size);
		}
	}


	int maxMerge = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			for (int i = 0; i < 4; i++) {
				int nextX = x + moves[i].first, nextY = y + moves[i].second;
				if (!(0 <= nextX && nextX < n && 0 <= nextY && nextY < m)) continue;
				if (!isBlock(field[x][y], i)) continue;
				if (groupNum[x][y] == groupNum[nextX][nextY]) continue;
				maxMerge = max(maxMerge, roomSize[x][y] + roomSize[nextX][nextY]);
			}
		}
	}

	cout << group - 1 << '\n';
	cout << maxRoom << '\n';
	cout << maxMerge << '\n';

	return 0;
}