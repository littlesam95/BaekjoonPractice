#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int k;
int arr[13];
int res[13];

void dfs(int start, int depth) {
	if (depth == 6) { // �� ���� 6���� �Ǹ�
		for (int i = 0; i < 6; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return; // ����ϰ� �������´�.
	}

	for (int i = start; i < k; i++) { // ��Ʈ��ŷ
		res[depth] = arr[i];
		dfs(i + 1, depth + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> k;
		if (k == 0) {
			break;
		}
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		dfs(0, 0);
		cout << "\n";
	};

	getchar();
	getchar();
	return 0;
}