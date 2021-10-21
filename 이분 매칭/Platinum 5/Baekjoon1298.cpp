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
#define MAX 101
#define INF 1e9+7

using namespace std;
int N, M;
int WANT[MAX];
bool visited[MAX];
vector<int> Graph[MAX];
int answer = 0;

// �̺� ��Ī(Bipartite Matching)
bool DFS(int X) {
	for (int i = 0; i < Graph[X].size(); i++) {
		int Next = Graph[X][i];
		if (visited[Next]) {
			continue;
		}
		visited[Next] = true;
		if ((WANT[Next] == 0) || DFS(WANT[Next])) { // ���� ��Ʈ��(Next)�� ��Ī�� ������ ���ٸ� ��Ʈ�ϰ� ���� ���(X)�� ��Ī��Ű�� true�� return�Ѵ�.
			// �Ǵ� ���� ��Ʈ�ϰ� ��Ī�� ������ �ִٸ�, �� ������ ���ϴ� ��Ʈ���� Ž��(DFS ���)
			WANT[Next] = X;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) { // A�� ����� B��° ��Ʈ���� �ڽ��� ��Ʈ���̶�� �����Ѵ�.
		int A, B;
		cin >> A >> B;
		Graph[A].push_back(B);
	}
	memset(WANT, 0, sizeof WANT);
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof visited);
		if (DFS(i)) { // 1��° ������� N��° �������, ���ϴ� ��Ʈ���� Ž���Ѵ�. ���� ��Ʈ�ϰ� ��Ī�� ������ ����̶�� answer�� �����Ѵ�.
			// DFS�� ������ �ذ��ϱ� ������, �־��� ��� �ð� ���⵵�� O(N * M)�� �ȴ�.
			answer++;
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}