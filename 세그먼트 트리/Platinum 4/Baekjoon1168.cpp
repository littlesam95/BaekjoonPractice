#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

// ���� �ð��� 0.15���̹Ƿ� O(N^2)�� �ð����⵵�� ������ ������ erase �Լ��� �̿��� Ǯ�̴� �ð� �ʰ��� �ɸ���.
// ���� O(nlogn)�� �ð����⵵�� ������ ���׸�Ʈ Ʈ���� �̿��Ͽ��� �Ѵ�.
using namespace std;
int N, K;
int tree[400005];
int del_idx = 1;
vector<int> answer;

int dfs(int S, int E, int node) { // ���׸�Ʈ Ʈ�� �ʱ�ȭ
	if (S == E) {
		return tree[node] = 1; // ��� ������带 1�� �ʱ�ȭ�Ѵ�.
	}
	int mid = (S + E) / 2;
	return tree[node] = dfs(S, mid, node * 2) + dfs(mid + 1, E, node * 2 + 1); // �ڽ� ������ ���� �θ� ��忡 �����ش�.
}

int update(int S, int E, int node, int idx) {
	tree[node]--; // ���� �Ϸ� �� ��ȣ -1 ����
	if (S == E) {
		return 0; // idx�� �ش��ϴ� ���� ��带 0���� �ٲ���
	}
	int mid = (S + E) / 2;
	if (idx <= mid) {
		return update(S, mid, node * 2, idx);
	}
	else {
		return update(mid + 1, E, node * 2 + 1, idx);
	}
}

int find_idx(int S, int E, int node, int idx) {
	if (S == E) {
		return S; // ���� ����� �� �ε��� ��ȯ
	}
	int mid = (S + E) / 2;
	if (idx <= tree[node * 2]) {
		return find_idx(S, mid, node * 2, idx); // �����Ϸ��� ��ȣ�� ���� �ڽ� ����� ������ ������ ���� ����Ʈ�� Ž��
	}
	else {
		return find_idx(mid + 1, E, node * 2 + 1, idx - tree[node * 2]);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	dfs(1, N, 1);
	for (int i = 0; i < N; i++) {
		int size = N - i; // ���� ��� ��
		del_idx += (K - 1); // ������ ����� �ε���(��� ���� ��� �پ��Ƿ� K-1�� �����ش�.)
		if (!(del_idx % size)) { // �ε����� ��� ���� ����������� �ε��� = ��� ��
			del_idx = size;
		}
		else if (del_idx > size) { // �ε����� ��� ������ Ŀ���� ��ⷯ ����
			del_idx %= size;
		}
		answer.push_back(find_idx(1, N, 1, del_idx)); // ����� �����ϰ� ������ ����� �ε����� ��ȯ
		update(1, N, 1, find_idx(1, N, 1, del_idx)); // ���׸�Ʈ Ʈ�� �ֽ�ȭ
	}
	cout << "<";
	for (int i = 0; i < answer.size(); i++) {
		if (i < answer.size() - 1) {
			cout << answer[i] << ", ";
		}
		else {
			cout << answer[i] << ">";
		}
	}
	cout << "\n";

	getchar();
	getchar();
	return 0;
}

// ���׸�Ʈ Ʈ���� �����ϴ� ���� ����� https://cocoon1787.tistory.com/433 ������.