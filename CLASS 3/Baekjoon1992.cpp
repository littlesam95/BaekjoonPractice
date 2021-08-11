#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int N;
int arr[64][64];

// ���� ����(Divide and Conquer)�� ������ �н��ϱ� ���Ͽ� https://yabmoons.tistory.com/450 ������.
void dfs(int y, int x, int size) {
	if (size == 1) { // ������ ������ ũ�Ⱑ 1�̸�, �� �� 1���θ� �̷���� �ִٸ� �״�� ���
		cout << arr[y][x];
		return;
	}

	bool zero_flag = true; // ������� �� ������ ���� 0���� �̷���� �ִٸ� true, �׷��� �ʴٸ� false
	bool one_flag = true; // ������� �� ������ ���� 1�� �̷���� �ִٸ� true, �׷��� �ʴٸ� false
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (arr[i][j] == 0) { // 0�� ���Դٸ� ���� 1�� �̷���� ���� �ʴٴ� �Ҹ��̹Ƿ� one_flag�� false�� �ٲ��ش�.
				one_flag = false;
			}
			if (arr[i][j] == 1) { // 1�� ���Դٸ� ���� 0���� �̷���� ���� �ʴٴ� �Ҹ��̹Ƿ� zero_flag�� false�� �ٲ��ش�.
				zero_flag = false;
			}
		}
	}

	if (zero_flag) { // ���� 0���� �̷���� �ִ� ��� 0�� ���.
		cout << 0;
		return;
	}
	if (one_flag) { // ���� 1�� �̷���� �ִ� ��� 1�� ���.
		cout << 1;
		return;
	}

	cout << "("; // ��ȣ�� ���ٴ� ���� ������ 4�����ؼ� Ž���� ����� ��ȣ �ȿ� ����ϰڴٴ� ���̴�.
	dfs(y, x, size / 2); // �������� ���� (y, x), (y, x + (size / 2)), (y + (size / 2), x), (y + (size / 2), x + (size / 2))�� ��´�.
	// ���̴� 2��еǹǷ� size ���� 2�� ������.
	dfs(y, x + (size / 2), size / 2);
	dfs(y + (size / 2), x, size / 2);
	dfs(y + (size / 2), x + (size / 2), size / 2);
	cout << ")"; // Ž���� ����Ǿ��ٸ� ��ȣ�� �ݴ´�.
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) { // ������ ���� ���ڿ��� �޾� arr[][] �迭�� ����
		string S;
		cin >> S;
		for (int j = 0; j < N; j++) {
			arr[i][j] = S[j] - '0';
		}
	}
	dfs(0, 0, N); // ���� ������ ���� ��� �Լ� ���

	getchar();
	getchar();
	return 0;
}