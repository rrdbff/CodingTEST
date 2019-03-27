#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
int T, N;
struct Station {
	vector<int> con;
	int a;
};
Station S[10000000];
int q,w;
bool visit[1000000];
int d[1000000];
int u[1000000];
int bestnum;
int bestden;
int bestcalc;
void BFS() {
	fill(visit, visit + N, false);
	fill(d, d + N, 1);
	queue<int> q;
	q.push(0);
	visit[0] = true;
	while (!q.empty)
	{
		int temp = q.front();
		q.pop();
		bestnum = S[temp].a;
		bestden = 1;
		bestcalc = bestnum / bestden;
		u[temp] = S[temp].a;
		d[temp] = 1;
		for (int i = 0;i < S[temp].con.size();i++)
		{
			if (visit[S[temp].con[i]] == false)
			{
				visit[S[temp].con[i]] = true;
			}
			else
				continue;

			int connect = S[temp].con[i];
			d[connect] = d[temp] + 1;
			u[connect] = u[temp] * S[connect].a;

			double calc = (double)u[connect] / (double)d[connect];
			if (calc < bestcalc)
			{
				bestnum = u[connect];
				bestden = d[connect];
				bestcalc = calc;
			}
		}
	}
}
int main()
{
	cin >> T >> N;
	for (int i = 1;i < N;i++)
	{
		cin >> q >> w;
		S[q].con.push_back(w);
		S[w].con.push_back(q);
	}
	for (int i = 0;i < N;i++)
	{
		cin >> q;
		S[i].a = q;
	}

	return 0;

}
