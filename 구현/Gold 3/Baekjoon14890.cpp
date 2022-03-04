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
#define MAX 105
#define LL long long
#define INF 1e9

using namespace std;
int N, L;
int MAP1[MAX][MAX];
int MAP2[MAX][MAX];

bool Make_Road_Able(int MAP[][MAX], int Y, int X) {
	int Height = MAP[Y][X]; // ���̰� 1 ������ ���� ��
	for (int i = X; i < (X + L); i++) { // L���� ���� ���� ���̴� ���� ���ƾ� ��.
		if (MAP[Y][i] != Height) {
			return false; // �ϳ��� �ٸ��ٸ� ���θ� ���� �� ����.
		}
	}
	return true;
}

int Make_Road(int MAP[][MAX]) {
	int res = 0;
	for (int i = 0; i < N; i++) {
		bool Can_Make_Road = true;
		int Chain_Road = 1; // ������� ����� ���� ����
		for (int j = 0; j < (N - 1); j++) {
			if (MAP[i][j] == MAP[i][j + 1]) { // ���� ���� ���� ���� ���̰� ���� ���
				Chain_Road++; // �ٷ� ������� �ش�.
			}
			else if (MAP[i][j] == (MAP[i][j + 1] + 1)) { // ���� ���� ���̰� �� ���� ���
				if (Make_Road_Able(MAP, i, j + 1)) {
					j += (L - 1); // ���� L���� ���� Ȯ�������� �ǳʶڴ�.
					Chain_Road = 0;
				}
				else {
					Can_Make_Road = false;
					break;
				}
			}
			else if (MAP[i][j] == (MAP[i][j + 1] - 1)) { // ���� ���� ���̰� �� ���� ���
				if (Chain_Road >= L) { // ������� ����� ���� ���̰� L �̻��̾�� ���θ� ���� �� �ִ�.
					Chain_Road = 1; // ���θ� ���Ҵٸ� �ٽ� MAP[i][j+1]���� ���̸� Ȯ���ϸ�, ����� ���� ���̴� �ٽ� 1�� �ȴ�.
				}
				else {
					Can_Make_Road = false;
					break;
				}
			}
			else if (abs(MAP[i][j] - MAP[i][j + 1]) >= 2) { // ���� ���� ���� ���� ���� ���̰� 2 �̻��� ���
				Can_Make_Road = false; // ���� ���̰� 2 �̻��� ��� ���θ� ���� �� ����.
				break;
			}
		}
		if (Can_Make_Road) {
			res++;
		}
	}
	return res;
}

int main() {
	FIRST
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP1[i][j]; // �� �������� Ȯ���ϱ� ���� �迭 MAP1
			MAP2[j][i] = MAP1[i][j]; // �� �������� Ȯ���ϱ� ���� �迭 MAP2
		}
	}

	cout << Make_Road(MAP1) + Make_Road(MAP2) << "\n";

	getchar();
	getchar();
	return 0;
}