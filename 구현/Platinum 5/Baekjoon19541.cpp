#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100005
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
vector<int> Meeting[MAX];
int visited[MAX]; // �־��� ���� ������ ������
int initial[MAX]; // �ʱ� ������ �ĺ�
int infected[MAX]; // ���� ������
bool answer = true;

int main() {
	FIRST
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int K;
		cin >> K;
		for (int j = 0; j < K; j++) {
			int A;
			cin >> A;
			Meeting[i].push_back(A);
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> visited[i];
		infected[i] = visited[i]; // ���� �������� ������ ����
		initial[i] = visited[i]; // �ʱ� ������ �ĺ��� ����
	}
	// ������ �������� �Ž��� �ö󰣴�.
	for (int i = (M - 1); i >= 0; i--) {
		bool Flag = true;
		for (int j = 0; j < Meeting[i].size(); j++) {
			int A = Meeting[i][j];
			if (visited[A] == 0) { // �ش� ���ӿ��� ���� �񰨿��ڰ� �ִ� ���
				// �ش� ������ ��� �ο����� �ʱ� �����ڰ� �� �� ����.
				Flag = false;
				break;
			}
		}
		if (!Flag) { // ���� �����ڰ� �� ���̶� �������� ������ ��� �ο����� �ʱ� �����ڰ� �ƴ�
			for (int j = 0; j < Meeting[i].size(); j++) {
				int A = Meeting[i][j];
				initial[A] = 0;
				visited[A] = 0;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		visited[i] = initial[i]; // ���� �ĺ����� �ʱⰨ���ڶ�� �����Ѵ�.
	}
	// ������ �ð� ������� �Ž��� �ö󰣴�.
	for (int i = 0; i < M; i++) {
		bool Flag = false;
		for (int j = 0; j < Meeting[i].size(); j++) {
			int A = Meeting[i][j];
			if (visited[A] == 1) { // �ش� ���ӿ��� �ʱ� ������ �ĺ��� �ִ� ���
				Flag = true;
				break;
			}
		}
		if (Flag) { // �ʱ� ������ �ĺ��� �� ���̶� �����Ѵٸ� ������ ��� ����� �����ȴ�(�� ����)
			for (int j = 0; j < Meeting[i].size(); j++) {
				int A = Meeting[i][j];
				visited[A] = 1;
			}
		}
	}
	// Ȯ���� ���� ������ ���� �������� ������ ��ġ���� �ʴ´ٸ� NO ���
	for (int i = 1; i <= N; i++) {
		if (infected[i] != visited[i]) {
			answer = false;
			break;
		}
	}
	
	if (answer) {
		cout << "YES" << "\n";
		for (int i = 1; i <= N; i++) {
			cout << initial[i] << " ";
		}
	}
	else {
		cout << "NO" << "\n";
	}

	getchar();
	getchar();
	return 0;
}