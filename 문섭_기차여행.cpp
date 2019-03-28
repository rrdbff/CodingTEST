
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
Station S[1000000];
int q,w;
bool visit[1000000];
int d[1000000];
int u[1000000];
int bestnum;
int bestden;
double bestcalc;

void ﻿abbreviate(int numerator, int denominator) {
	int min = denominator;
	for (int i = min; i > 1; i--) {
		// 이중조건문, 둘다 만족시 나누기 수행
		(numerator%i == 0) ? (denominator%i) ? numerator /= i, denominator /= i : 0 : 0;
	}
	cout << numerator << "/" << denominator << "\n";
}

void BFS(int start)
{
	fill(visit, visit + N, false);
	fill(d,d+N,1);
	queue<int> q;
	q.push(start);
	visit[start] = true;

	u[start] = S[start].a;
	d[start] = 1;
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		if (S[temp].con.size() == 0)
			continue;
		for (int i = 0;i < (int)S[temp].con.size();i++)
		{
			if (visit[S[temp].con[i]] == false)
			{
				visit[S[temp].con[i]] = true;
				q.push(S[temp].con[i]);
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
	cin >> T;
	for (int k = 0;k < T;k++) {
		cin >> N;
		for (int i = 1;i < N;i++)
		{
			cin >> q >> w;
			S[q-1].con.push_back(w-1);
			S[w-1].con.push_back(q-1);
		}
		for (int i = 0;i < N;i++)
		{
			cin >> q;
			S[i].a = q;
		}
		bestnum = S[0].a;
		bestden = 1;
		bestcalc = bestnum / bestden;
		for (int i = 0;i < N;i++)
		{
			BFS(i);
		}
		cout << "#" << k + 1 << " ";
		﻿abbreviate(bestnum, bestden);
	}
	return 0;

}
