#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int N;
int a, b, c;
vector<pair<int, int> > vec[10010];
bool visited[10010];
int answer = 0;
int end_point = 0;

void init() {
	for (int i = 0; i < 10010; i++) {
		visited[i] = false;
	}
}

void dfs(int S, int len) {
	if (visited[S]) {
		return;
	}
	visited[S] = true;
	if (answer < len) {
		answer = len;
		end_point = S;
	}

	for (int i = 0; i < vec[S].size(); i++) {
		dfs(vec[S][i].first, vec[S][i].second + len);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
		vec[b].push_back(make_pair(a, c)); // �θ� �ڽ� ��尣�� ������ ����ġ�� pair�� �����Ѵ�.
	}
	dfs(1, 0); // root ������ Ž���ؼ� ���� �� ���̸� ���� ��带 �������� �Ѵ�.
	answer = 0;
	init(); // ���̸� ������ answer ������ �湮������ ǥ���ϴ� �迭 visited�� 0���� �ʱ�ȭ
	dfs(end_point, 0); // �����߾��� �������� �ٽ� Ž���ؼ� Ʈ���� ������ ã�´�.
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}