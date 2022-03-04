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
#define MAX 10005
#define LL long long
#define INF 1e9

using namespace std;
int N;
vector<int> Ball;
int answer = INF;

int RBY_Pang(int Down, int Up, int Left) {
	int Successive_Down = 1; // �Ʒ��� ���ӵ� ���� ����
	int Successive_Up = 1; // ���� ���ӵ� ���� ����
	int next_Down = Down; // �Ʒ��� �ε���
	int next_Up = Up; // ���� �ε���
	while ((next_Up + 1 < N) && (Ball[next_Up] == Ball[next_Up + 1])) {
		// ������ ����� �����鼭, ���� ���ӵ� ���� ���� �ľ�
		next_Up++;
		Successive_Up++;
	};
	while ((next_Down - 1 >= 0) && (Ball[next_Down] == Ball[next_Down - 1])) {
		// ������ ����� �����鼭, �Ʒ��� ���ӵ� ���� ���� �ľ�
		next_Down--;
		Successive_Down++;
	};
	int Max_Successive;
	if (Ball[Down] == Ball[Up]) { // Down��° ���� Up��° ���� ���ٸ� ���ӵ� ���� ������ ���� ������ ���Ѵ�.
		if (Down == Up) {
			Max_Successive = Successive_Up + Successive_Down - 1;
		}
		else {
			Max_Successive = Successive_Up + Successive_Down;
		}
	}
	else { // �ٸ��ٸ� �Ʒ��� ���ӵ� ���� ���� Ȥ�� ���� ���ӵ� ���� ���� �� �� �� ū ���� �ִ�� ���ӵ� ���� ������ �ȴ�.
		Max_Successive = max(Successive_Down, Successive_Up);
	}
	if (Max_Successive >= 4) { // �ִ�� ���ӵ� ���� ������ 4�� �̻��̸�
		if (Left - Max_Successive < 4) { // �ִ�� ���ӵ� ���� ������ ���� �ִ� ���� �������� ����µ� 3 ���϶�� �� �̻� ������ ���� ����.
			return (Left - Max_Successive);
		}
		// �ִ�� ���ӵ� ���� ������ ���� �ִ� ���� �������� ����µ� ���� 4�� �̻� ���� �ִٸ�
		if (next_Down == 0) { // ���� ���� �Ʒ��ʿ� �� Ȯ���� ���� ���� ���
			next_Down = next_Up;
		}
		else {
			next_Down--;
		}
		if (next_Up == N - 1) { // ���� ���� ���ʿ� �� Ȯ���� ���� ���� ���
			next_Up = next_Down;
		}
		else {
			next_Up++;
		}
		return RBY_Pang(next_Down, next_Up, Left - Max_Successive); // ���� 4�� �̻� ���� �ִٸ� ��͸� ����Ͽ� ��� ������ ���� �ִ��� Ȯ��
	}
	else { // �ƴ϶�� �� �̻� ������ ���� ���ٴ� ���̹Ƿ�, ���� �ִ� ���� ������ return
		return Left;
	}
}

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < N; i++) {
		int X;
		cin >> X;
		Ball.push_back(X);
	}
	for (int i = 0; i < N; i++) {
		int CurB = Ball[i]; // i��° �� ���� ����
		int M = INF;
		for (int j = 1; j <= 3; j++) { // i��° ���� ���� ������ ������ �ٸ� ������ �ٲ㰡�鼭 Ȯ��
			if (CurB == j) {
				continue;
			}
			Ball[i] = j;
			M = min(M, RBY_Pang(i, i, N));
		}
		answer = min(answer, M);
		Ball[i] = CurB;
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}