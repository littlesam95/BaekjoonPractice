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
	for (int i = 1; i <= N; i++) { // 순서쌍 (A, B)를 입력하고, 더하기, 빼기, 곱하기 연산을 한 결과를 vec vector에 push한다.
		LL A, B;
		cin >> A >> B;
		P[i] = make_pair(A, B);
		vec.push_back(A + B);
		vec.push_back(A - B);
		vec.push_back(A * B);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end()); // 모든 결과값을 담은 vec vector를 정렬하고 중복된 값은 제거한다.
	for (int i = 1; i <= N; i++) { // 값은 최대 10^12까지 나올 수 있으므로, 범위가 너무 커진다. 따라서 현재 값을 vec의 가장 첫번째 원소에서 빼준다.
		// 그리고 i번째 순서쌍과 결과값을 서로 연결한다.
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
	// 순서쌍과 결과값을 서로 매칭해준다.
	int Matching = 0;
	memset(WORK, - 1, sizeof WORK);
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof visited);
		if (DFS(i)) {
			Matching++;
		}
	}
	if (Matching != N) { // 순서쌍들이 서로 다른 연산 결과를 가질 수 없는 경우
		cout << "Impossible" << "\n";
	}
	else { // 모든 순서쌍들이 서로 다른 연산 결과를 가진 경우
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