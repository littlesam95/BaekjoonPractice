#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
vector<vector<int> > vec;
bool visit[101] = { false, };
int computer = 0;
int res = 0;

void dfs(int x) {
	res++;
	visit[x] = true;

	int size = vec[x].size();
	for (int i = 0; i < size; i++) {
		if (!visit[vec[x][i]]) { // node�� ����� edge �� Ž������ ���� edge Ž��
			dfs(vec[x][i]);
		}
	}
	return;
}

int main() {
	int N, start, end;
	cin >> computer >> N; // ��ǻ���� ��, ����� ��ǻ�� �� �Է�
	vec.resize(computer + 1);
	for (int i = 0; i < N; i++) {
		cin >> start >> end; // ����� ��ǻ���� ��ȣ �� �Է�
		vec[start].push_back(end); // i��° ���Ϳ� j push
		vec[end].push_back(start); // j��° ���Ϳ� i push
	}

	dfs(1);

	cout << res - 1;

	getchar();
	getchar();
	return 0;
}