#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

// Merge Sort�� �̿��ϳ� ���׸�Ʈ Ʈ���� �̿��Ͽ� Ǯ ���� �ִµ� �� ���� ���۸���.
using namespace std;
int N;
vector<pair<int, int> > vec; // ��, ��ġ�� �̷������ pair�� ���Ϳ� ����
int tree[2222222];
long long answer = 0;

long long find_sum(int S, int E, int node, int left, int right) {
	if ((left > E) || (right < S)) {
		return 0;
	}
	if ((left <= S) && (E <= right)) {
		return tree[node];
	}
	int mid = (S + E) / 2;
	return find_sum(S, mid, node * 2, left, right) + find_sum(mid + 1, E, node * 2 + 1, left, right);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		vec.push_back(make_pair(a, i));
	}
	sort(vec.begin(), vec.end());
	int base = 1;
	while (base < N) {
		base *= 2;
	};
	for (auto w : vec) {
		int i = w.second;
		answer += find_sum(1, base, 1, i + 1, base); // ���׸�Ʈ Ʈ���� ��Ʈ ��忡�� ���� ������ ����
		for (int j = base - 1 + i; j; j /= 2) { // Ʈ���� �����鼭 �ڽź��� ū ���� ī�������ָ� ����� ���� �ֽ�ȭ��Ų��.
			tree[j]++;
		}
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}