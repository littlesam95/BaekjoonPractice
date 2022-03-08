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
#define MAX 10001
#define LL long long
#define INF 1e9

using namespace std;
int V, E;
vector<int> Edge[MAX];
int visited[MAX];
bool answer[MAX];

int DFS(int Parent, int Start, int Order, bool isRoot) {
	int res = Order;
	visited[Start] = Order; // DFS Ž�� ���� ����
	int Child = 0; // �ڽ� ��� ��

	for (int i = 0; i < Edge[Start].size(); i++) {
		int Next = Edge[Start][i]; // ���� ����
		if (Parent == Next) {
			continue;
		}
		if (visited[Next] == 0) { // ���� ������ ���� Ž������ ���� ������ ��
			int Next_Order = DFS(Start, Next, Order + 1, false); // ���� ������ �湮 ��ȣ�� ã��
			Child++;
			if (!isRoot && (Next_Order >= visited[Start])) {
				/*
					���� ������ Root�� �ƴϰ�, ���� �������� ���� �湮 ��ȣ�� ���� �������� 
					�ڽ� �������� �� �� ���ٸ� ���� ������ �������̴�. (visited[Next] >= visited[Start])
				*/
				answer[Start] = true;
			}
			res = min(res, Next_Order);
		}
		else { 
			/*
				���� ������ �̹� DFS���� Ž���� �����̶��(visited[Next] == true)
				���� ������ �湮 ������ Ž���� ������ �湮 ���� �� �ּڰ��� ������.
				�̷��� �ؼ� ���� �������� �ڽ� �������� ���� ������ ��ġ�� �ʰ�
				���� �������� ���� �湮 ��ȣ�� ���� �������� �� �� ���� ��츦 ã�� �� �ִ�.
			*/
			res = min(res, visited[Next]);
		}
	}

	if (isRoot && (Child >= 2)) { // �׷��� ���� ������ Root��, �ڽ� ������ 2�� �̻� �����ٸ�
		answer[Start] = true; // ���� ������ �������̴�.
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
			DFS(0, i, 1, true);
		}
	}
}

void Find_Answer() {
	int res = 0;
	for (int i = 1; i <= V; i++) {
		if (answer[i]) {
			res++;
		}
	}
	cout << res << "\n";
	for (int i = 1; i <= V; i++) {
		if (answer[i]) {
			cout << i << " ";
		}
	}
	cout << "\n";
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