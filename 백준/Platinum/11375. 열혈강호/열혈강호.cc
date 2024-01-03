
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int Max = 2002;
const int INF = 1000000000;

int N, M, Source, Sink;

vector<int> graph[Max];
int c[Max][Max] = { 0, };
int f[Max][Max] = { 0, };
int level[Max];
int work[Max];


bool bfsLevel()
{
	fill(level, level + Max, -1);
	level[Source] = 0;

	queue<int> q;
	q.push(Source);

	while (!q.empty())
	{
		int Curr = q.front();
		q.pop();

		for (auto& Next : graph[Curr])
		{
			if (level[Next] == -1 && c[Curr][Next] - f[Curr][Next] > 0)
			{
				level[Next] = level[Curr] + 1;
				q.push(Next);
			}
		}
	}
	return (level[Sink] != -1);
}

int dfsFlow(int Curr, int flow)
{
	if (Curr == Sink) return flow;

	for (int& i = work[Curr]; i < graph[Curr].size(); i++)
	{
		int Next = graph[Curr][i];

		if (level[Next] == level[Curr] + 1 && c[Curr][Next] - f[Curr][Next] > 0)
		{
			int minFlow = dfsFlow(Next, min(c[Curr][Next] - f[Curr][Next], flow));

			if (minFlow > 0)
			{
				f[Curr][Next] += minFlow;
				f[Next][Curr] -= minFlow;
				return minFlow;
			}
		}
	}
	return 0;
}

int dinicFlow(int total = 0)
{
	while (bfsLevel())
	{
		fill(work, work + Max, 0);

		while (1)
		{
			int flow = dfsFlow(Source, INF);
			if (flow == 0) break;
			total += flow;
		}
	}
	return total;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Source = 0;
	Sink = Max - 1;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		graph[Source].push_back(i);
		graph[i].push_back(Source);
		c[Source][i] = 1;
	}

	for (int i = 1; i <= M; i++)
	{
		graph[i + 1000].push_back(Sink);
		graph[Sink].push_back(i + 1000);
		c[i + 1000][Sink] = 1;
	}

	int cnt, v;
	for (int i = 1; i <= N; i++)
	{
		cin >> cnt;

		for (int j = 0; j < cnt; j++)
		{
			cin >> v;
			graph[i].push_back(v + 1000);
			graph[v + 1000].push_back(i);
			c[i][v + 1000] = 1;
		}
	}

	cout << dinicFlow() << '\n';

	return 0;
}