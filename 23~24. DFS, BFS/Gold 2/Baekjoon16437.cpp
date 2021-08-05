#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct Info {
	char animal;
	long long size;
};

int N;
vector<Info> vec(123457);
vector<int> line[123457];
bool visited[123457];

long long dfs(int x) {
	long long sheep = 0;
	visited[x] = true;
	for (int i = 0; i < line[x].size(); i++) {
		if (!visited[line[x][i]]) {
			sheep += dfs(line[x][i]);
		}
	}
	if (vec[x].animal == 'S') {
		sheep += vec[x].size;
	}
	else if (vec[x].animal == 'W') {
		sheep -= vec[x].size;
		if (sheep < 0) {
			return 0;
		}
	}

	return sheep;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 2; i <= N; i++) {
		char S;
		int n1, n2;
		cin >> S >> n1 >> n2;
		vec[i].animal = S;
		vec[i].size = n1;
		line[i].push_back(n2);
		line[n2].push_back(i);
	}
	cout << dfs(1) << "\n";

	getchar();
	getchar();
	return 0;
}