#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
#define LL long long
#define MAX 2510
#define INF 1e12

using namespace std;
int N;
pair<LL, LL> P[MAX];
LL WORK[MAX * 4], MATCH[MAX * 4];
bool visited[MAX * 4];
vector<LL> Graph[MAX * 4];
vector<LL> vec;

bool DFS(int E) {
	visited[E] = true;
	for (int i = 0; i < Graph[E].size(); i++) {
		int Next = Graph[E][i];
		if (!visited[Next]) {
			visited[Next] = true;
			if ((WORK[Next] == -1) || DFS(WORK[Next])) {
				WORK[Next] = E;
				MATCH[E] = Next;
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) { // ������ (A, B)�� �Է��ϰ�, ���ϱ�, ����, ���ϱ� ������ �� ����� vec vector�� push�Ѵ�.
		LL A, B;
		cin >> A >> B;
		P[i] = make_pair(A, B);
		vec.push_back(A + B);
		vec.push_back(A - B);
		vec.push_back(A * B);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end()); // ��� ������� ���� vec vector�� �����ϰ� �ߺ��� ���� �����Ѵ�.
	for (int i = 1; i <= N; i++) { // ���� �ִ� 10^12���� ���� �� �����Ƿ�, ������ �ʹ� Ŀ����. ���� ���� ���� vec�� ���� ù��° ���ҿ��� ���ش�.
		// �׸��� i��° �����ְ� ������� ���� �����Ѵ�.
		int ADD_Number = lower_bound(vec.begin(), vec.end(), P[i].first + P[i].second) - vec.begin() + MAX;
		Graph[i].push_back(ADD_Number);
		Graph[ADD_Number].push_back(i);
		int SUB_Number = lower_bound(vec.begin(), vec.end(), P[i].first - P[i].second) - vec.begin() + MAX;
		Graph[i].push_back(SUB_Number);
		Graph[SUB_Number].push_back(i);
		int MUL_Number = lower_bound(vec.begin(), vec.end(), P[i].first * P[i].second) - vec.begin() + MAX;
		Graph[i].push_back(MUL_Number);
		Graph[MUL_Number].push_back(i);
	}
	// �����ְ� ������� ���� ��Ī���ش�.
	int Matching = 0;
	memset(WORK, - 1, sizeof WORK);
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof visited);
		if (DFS(i)) {
			Matching++;
		}
	}
	if (Matching != N) { // �����ֵ��� ���� �ٸ� ���� ����� ���� �� ���� ���
		cout << "Impossible" << "\n";
	}
	else { // ��� �����ֵ��� ���� �ٸ� ���� ����� ���� ���
		for (int i = 1; i <= N; i++) {
			LL Value = vec[MATCH[i] - MAX];
			if (P[i].first + P[i].second == Value) {
				cout << P[i].first << " + " << P[i].second << " = " << Value << "\n";
			}
			else if (P[i].first - P[i].second == Value) {
				cout << P[i].first << " - " << P[i].second << " = " << Value << "\n";
			}
			else if (P[i].first * P[i].second == Value) {
				cout << P[i].first << " * " << P[i].second << " = " << Value << "\n";
			}
		}
	}

	getchar();
	getchar();
	return 0;
}