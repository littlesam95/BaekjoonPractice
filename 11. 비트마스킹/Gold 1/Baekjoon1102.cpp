#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int N, P;
int arr[20][20];
int dp[20][1 << 20] = { 0, };
string str;
int state = 1 << 20;

void init() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < (1 << 20); j++) {
			dp[i][j] = -1;
		}
	}
}

int count_bits(int n) { // ��Ʈ ���� ���� �Լ�
	int count = 0;
	while (n) {
		count += (n & 1); // �� �� ��Ʈ�� 1�� ��� count�� ������Ų��.
		n >>= 1; // ��Ʈ�� ���������� �� ĭ �̵���Ų��.
	};

	return count;
}

int dfs(int idx, int now_state) {
	if (count_bits(now_state) - 1 >= P) { // now_state �� �����ҵ��� ���� ���¸� �ľ��Ѵ�.
		// ��Ʈ ���� P + 1�� �̻��̶�� ���峪�� ���� �����Ұ� P�� �̻��̶�� ���̹Ƿ�, �� �̻� �����Ҹ� �ǵ帮�� �ʾƵ� �ȴ�.
		return 0;
	}

	if (dp[idx][now_state] != -1) {
		return dp[idx][now_state];
	}

	dp[idx][now_state] = INT_MAX;
	for (int i = 0; i < N; i++) {
		if (!(now_state & (1 << i))) { // i��° �����Ұ� ���峵�ٸ�
			int next_state = now_state | (1 << i); // i��° �����Ҹ� ��ģ��.
			for (int j = 0; j < N; j++) {
				if ((next_state & (1 << j))) { // i��° �����Ҹ� ������ ���� ���¸� �ľ��Ͽ� j��° �����Ұ� ���峪�� �ʾҴٸ�
					dp[idx][now_state] = min(dp[idx][now_state], arr[idx][i] + dfs(j, next_state)); // idx��°, �� 83��° �ٿ��� i��° �����Ҹ� ���������� �ϴ� �����Ҹ� ������ �� ��� �� ��밪�� �ֽ�ȭ�Ѵ�.
					// ���⼭ ���ؾ� �� ���� i��° �����Ҹ� ������ ���� ����, �� next_state���� �ٽ� j��° �����Ҹ� ���������� �ؼ� �����Ҹ� ���ľ� �ϴ����� �ľ��ϱ� ���� ����Լ��� ������ return��(���) + idx��° �����Ҹ� �̿��Ͽ� i��° �����Ҹ� ��ĥ �� ��� ����� ���� ���� ���Ͽ� �� ���� ������ �ֽ�ȭ�Ѵ�.
				}
			}
		}
	}

	return dp[idx][now_state]; // idx��° �����Ҹ� ���������� �ϴ�, �����Ҹ� ��ġ�� �� ��� �ּ��� ����� return�Ѵ�.
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) { // ������ ��� �Է�
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> str;
	for (int i = 0; i < str.size(); i++) { // ������ ���� �Է�, Y�� ��� i + 1��° ��Ʈ�� 1�� ����, N�� ��� 0.
		if (str[i] == 'Y') {
			state |= (1 << i);
		}
	}
	cin >> P;
	if (!P) {
		cout << 0 << "\n"; // P�� 0, �� ���峪�� ���� �����Ұ� �ּ� 0�� �̻��̶�� �ϸ� �����Ҹ� �ǵ帱 �ʿ䰡 ���� ������ ����� ���� �ʴ´�.
	}
	else { // P�� 1 �̻��� ���
		init();
		int result = INT_MAX;
		for (int i = 0; i < N; i++) {
			if (str[i] == 'Y') {
				result = min(result, dfs(i, state)); // ���� �ִ� �����Ҹ� ã�� ���峭 �����Ҹ� ��ġ�� ���¸� �ֽ�ȭ�Ѵ�.
				// ���¸� �ֽ�ȭ�� ���� ����Լ��� �̿��Ѵ�.
			}
		}

		if (result == INT_MAX) { // result�� �������� �ִ��� ��� �����Ҹ� ��ġ�� ���� �Ұ����ϴٴ� ���̴�. ���� -1�� ����Ѵ�.
			cout << -1 << "\n";
		}
		else {
			cout << result << "\n";
		}
	}

	getchar();
	getchar();
	return 0;
}

// https://jaimemin.tistory.com/689 ������.