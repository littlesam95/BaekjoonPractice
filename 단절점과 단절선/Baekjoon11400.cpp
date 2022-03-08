#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100001
#define LL long long
#define INF 1e9

using namespace std;
int V, E;
vector<int> Edge[MAX];
int visited[MAX];
vector<pair<int, int> > answer;

int DFS(int Parent, int Start, int Order) {
	int res = Order;
	visited[Start] = Order; // DFS Ž�� ���� ����

	for (int i = 0; i < Edge[Start].size(); i++) {
		int Next = Edge[Start][i]; // ���� ����
		if (Parent == Next) {
			continue;
		}
		if (visited[Next] == 0) { // ���� ������ ���� Ž������ ���� ������ ��
			int Next_Order = DFS(Start, Next, Order + 1); // ���� ������ �湮 ��ȣ�� ã��
			if (Next_Order > visited[Start]) {
				/*
					���� ��������, ���� �湮���� ���� ������ �湮 ������ ���� ������ �������� �ڶ��
					���� Edge�� �������� �ȴ�.(visited[Next] > visited[Start])
				*/
				answer.push_back(make_pair(min(Start, Next), max(Start, Next)));
			}
			res = min(res, Next_Order);
		}
		else {
			res = min(res, visited[Next]);
			continue;
		}
	}

	return res;
}

void Input() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int A, B;
		cin >> A >> B;
		Edge[A].push_back(B);
		Edge[B].push_back(A);
	}
}

void Settings() {
	for (int i = 1; i <= V; i++) {
		sort(Edge[i].begin(), Edge[i].end());
	}
	for (int i = 1; i <= V; i++) {
		if (visited[i] == 0) {
			DFS(0, i, 1);
		}
	}
}

void Find_Answer() {
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		int S = answer[i].first;
		int E = answer[i].second;
		cout << S << " " << E << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}