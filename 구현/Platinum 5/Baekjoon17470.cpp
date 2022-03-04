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
int N, M, R;
int ArrY[4];
int ArrX[4];
pair<int, int> MAP[4][4];
pair<int, int> Tmp[4][4];
int A[MAX][MAX];
int Tmp_A[MAX][MAX];
int answer[MAX][MAX];

/*
	�־��� ����� ���� �������� ��, 100X100 ũ���� �迭�� 200���� �����Ѵٸ�
	�ð� ���⵵�� �ſ� Ŀ���� �ȴ�. ����, �迭�� ��ü�� ������ ���� �ƴ�,
	�迭�� 4������� �� ������ 4���� �迭�� ������ 4���� �������� �����ش�.
	�� �ٽ��� �迭 4���� ������ �迭���� ȸ����Ű�ڴٴ� ���̴�.
*/

void init() { // �迭 4���� ������ �������� ����
	ArrY[0] = 0;
	ArrY[1] = (N / 2) - 1;
	ArrY[2] = (N / 2);
	ArrY[3] = N - 1;
	ArrX[0] = 0;
	ArrX[1] = (M / 2) - 1;
	ArrX[2] = (M / 2);
	ArrX[3] = M - 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			MAP[i][j].first = ArrY[i];
			MAP[i][j].second = ArrX[j];
		}
	}
}

void Copy_MAP() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Tmp[i][j] = MAP[i][j];
		}
	}
}

void First_Operation() { // �迭���� ������ �𼭸� �κи� ���Ϲ���
	Copy_MAP();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			MAP[3 - i][j] = Tmp[i][j];
		}
	}
}

void Second_Operation() { // �迭���� ������ �𼭸� �κи� �¿����
	Copy_MAP();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			MAP[j][3 - i] = Tmp[j][i];
		}
	}
}

void Third_Operation() { // �迭���� ������ �𼭸� �κи� ���������� 90�� ȸ��
	Copy_MAP();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			MAP[j][3 - i] = Tmp[i][j];
		}
	}
	swap(N, M);
}

void Fourth_Operation() { // �迭���� ������ �𼭸� �κи� �������� 90�� ȸ��
	Copy_MAP();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			MAP[3 - j][i] = Tmp[i][j];
		}
	}
	swap(N, M);
}

void Fifth_Operation() { // 4���� �迭 ��ü�� ���������� 90�� ȸ��
	pair<int, int> Tmp_MAP[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			Tmp_MAP[i][j] = MAP[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			MAP[i][j] = MAP[i + 2][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			MAP[i + 2][j] = MAP[i + 2][j + 2];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			MAP[i + 2][j + 2] = MAP[i][j + 2];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			MAP[i][j + 2] = Tmp_MAP[i][j];
		}
	}
}

void Sixth_Operation() { // 4���� �迭 ��ü�� �������� 90�� ȸ��
	pair<int, int> Tmp_MAP[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			Tmp_MAP[i][j] = MAP[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			MAP[i][j] = MAP[i][j + 2];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			MAP[i][j + 2] = MAP[i + 2][j + 2];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			MAP[i + 2][j + 2] = MAP[i + 2][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			MAP[i + 2][j] = Tmp_MAP[i][j];
		}
	}
}

/*
	������ ���� ���̳� ���� ���̰� 2���, �迭�� 4������� ��
	4���� �迭 ������ �𼭸��� 4���� �ƴ϶� 2���� �� ���̴�.
	�Դٰ�, 2X2 �迭�̶�� �𼭸��� 1���� �ȴ�.
	����, �ڵ尡 ����� �������� ���� ���̴�.
	�׷��� ������ �̷��� ����� �׳� �迭 ��ü�� �����ֱ�� �ߴ�.
	������ �迭�� ũ�Ⱑ �۱� ������ �ð� �ʰ��� �߻����� �ʴ´�.
*/

void Copy_A() { // �迭 ��ü�� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Tmp_A[i][j] = A[i][j];
		}
	}
}

void First_Rotation() { // �迭 ��ü�� ���Ϲ���
	Copy_A();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[(N - 1) - i][j] = Tmp_A[i][j];
		}
	}
}

void Second_Rotation() { // �迭 ��ü�� �¿����
	Copy_A();
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			A[j][(M - 1) - i] = Tmp_A[j][i];
		}
	}
}

void Third_Rotation() { // �迭 ��ü�� ���������� 90�� ȸ��
	Copy_A();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[j][(N - 1) - i] = Tmp_A[i][j];
		}
	}
	swap(N, M);
}

void Fourth_Rotation() { // �迭 ��ü�� �������� 90�� ȸ��
	Copy_A();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[(M - 1) - j][i] = Tmp_A[i][j];
		}
	}
	swap(N, M);
}

void Fifth_Rotation() { // ���� 4���� �迭 ��ü�� ���������� 90�� ȸ��
	for (int i = 0; i < (N / 2); i++) {
		for (int j = 0; j < (M / 2); j++) {
			Tmp_A[i][j] = A[i][j];
		}
	}
	for (int i = (N / 2); i < N; i++) {
		for (int j = 0; j < (M / 2); j++) {
			A[i - (N / 2)][j] = A[i][j];
		}
	}
	for (int i = (N / 2); i < N; i++) {
		for (int j = (M / 2); j < M; j++) {
			A[i][j - (M / 2)] = A[i][j];
		}
	}
	for (int i = 0; i < (N / 2); i++) {
		for (int j = (M / 2); j < M; j++) {
			A[i + (N / 2)][j] = A[i][j];
		}
	}
	for (int i = 0; i < (N / 2); i++) {
		for (int j = 0; j < (M / 2); j++) {
			A[i][j + (M / 2)] = Tmp_A[i][j];
		}
	}
}

void Sixth_Rotation() { // ���� 4���� �迭 ��ü�� �������� 90�� ȸ��
	for (int i = 0; i < (N / 2); i++) {
		for (int j = 0; j < (M / 2); j++) {
			Tmp_A[i][j] = A[i][j];
		}
	}
	for (int i = 0; i < (N / 2); i++) {
		for (int j = (M / 2); j < M; j++) {
			A[i][j - (M / 2)] = A[i][j];
		}
	}
	for (int i = (N / 2); i < N; i++) {
		for (int j = (M / 2); j < M; j++) {
			A[i - (N / 2)][j] = A[i][j];
		}
	}
	for (int i = (N / 2); i < N; i++) {
		for (int j = 0; j < (M / 2); j++) {
			A[i][j + (M / 2)] = A[i][j];
		}
	}
	for (int i = 0; i < (N / 2); i++) {
		for (int j = 0; j < (M / 2); j++) {
			A[i + (N / 2)][j] = Tmp_A[i][j];
		}
	}
}

/*
	�迭���� �𼭸��� ȸ�����ױ� ������ �������ʹ� ����� �� ����� �Ѵ�.
	4����� �迭 ������ �������� ��,
	ù ��° �������� X, Y��ǥ, �� ��° �������� X, Y��ǥ, �� ��° �������� X, Y��ǥ�� ��Һ񱳸� �Ͽ�
	����� �����Ѵ�.
*/
void Arr_Copy(int startY, int startX, int endY, int endX, int FirstY, int FirstX) {
	int Y = FirstY;
	int X = FirstX;
	if ((MAP[startY][startX].first < MAP[endY][startX].first) && (MAP[startY][startX].second < MAP[startY][endX].second)) {
		for (int i = MAP[startY][startX].first; i <= MAP[endY][startX].first; i++) {
			for (int j = MAP[startY][startX].second; j <= MAP[startY][endX].second; j++) {
				answer[Y][X++] = A[i][j];
			}
			Y++;
			X = FirstX;
		}
	}
	else if ((MAP[startY][startX].first < MAP[endY][startX].first) && (MAP[startY][startX].second > MAP[startY][endX].second)) {
		for (int i = MAP[startY][startX].first; i <= MAP[endY][startX].first; i++) {
			for (int j = MAP[startY][startX].second; j >= MAP[startY][endX].second; j--) {
				answer[Y][X++] = A[i][j];
			}
			Y++;
			X = FirstX;
		}
	}
	else if ((MAP[startY][startX].first > MAP[endY][startX].first) && (MAP[startY][startX].second < MAP[startY][endX].second)) {
		for (int i = MAP[startY][startX].first; i >= MAP[endY][startX].first; i--) {
			for (int j = MAP[startY][startX].second; j <= MAP[startY][endX].second; j++) {
				answer[Y][X++] = A[i][j];
			}
			Y++;
			X = FirstX;
		}
	}
	else if ((MAP[startY][startX].first > MAP[endY][startX].first) && (MAP[startY][startX].second > MAP[startY][endX].second)) {
		for (int i = MAP[startY][startX].first; i >= MAP[endY][startX].first; i--) {
			for (int j = MAP[startY][startX].second; j >= MAP[startY][endX].second; j--) {
				answer[Y][X++] = A[i][j];
			}
			Y++;
			X = FirstX;
		}
	}
	else if ((MAP[startY][startX].first < MAP[startY][endX].first) && (MAP[startY][startX].second < MAP[endY][startX].second)) {
		for (int i = MAP[startY][startX].second; i <= MAP[endY][startX].second; i++) {
			for (int j = MAP[startY][startX].first; j <= MAP[startY][endX].first; j++) {
				answer[Y][X++] = A[j][i];
			}
			Y++;
			X = FirstX;
		}
	}
	else if ((MAP[startY][startX].first < MAP[startY][endX].first) && (MAP[startY][startX].second > MAP[endY][startX].second)) {
		for (int i = MAP[startY][startX].second; i >= MAP[endY][startX].second; i--) {
			for (int j = MAP[startY][startX].first; j <= MAP[startY][endX].first; j++) {
				answer[Y][X++] = A[j][i];
			}
			Y++;
			X = FirstX;
		}
	}
	else if ((MAP[startY][startX].first > MAP[startY][endX].first) && (MAP[startY][startX].second < MAP[endY][startX].second)) {
		for (int i = MAP[startY][startX].second; i <= MAP[endY][startX].second; i++) {
			for (int j = MAP[startY][startX].first; j >= MAP[startY][endX].first; j--) {
				answer[Y][X++] = A[j][i];
			}
			Y++;
			X = FirstX;
		}
	}
	else if ((MAP[startY][startX].first > MAP[startY][endX].first) && (MAP[startY][startX].second > MAP[endY][startX].second)) {
		for (int i = MAP[startY][startX].second; i >= MAP[endY][startX].second; i--) {
			for (int j = MAP[startY][startX].first; j >= MAP[startY][endX].first; j--) {
				answer[Y][X++] = A[j][i];
			}
			Y++;
			X = FirstX;
		}
	}
}

void Print() {
	Arr_Copy(0, 0, 1, 1, 0, 0);
	Arr_Copy(0, 2, 1, 3, 0, (M / 2));
	Arr_Copy(2, 0, 3, 1, (N / 2), 0);
	Arr_Copy(2, 2, 3, 3, (N / 2), (M / 2));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	FIRST
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	if ((N >= 4) && (M >= 4)) { // ��� ���� ���̰� ��� 4 �̻��� ��
		init();
		for (int i = 0; i < R; i++) {
			int X;
			cin >> X;
			if (X == 1) {
				First_Operation();
			}
			else if (X == 2) {
				Second_Operation();
			}
			else if (X == 3) {
				Third_Operation();
			}
			else if (X == 4) {
				Fourth_Operation();
			}
			else if (X == 5) {
				Fifth_Operation();
			}
			else if (X == 6) {
				Sixth_Operation();
			}
		}
		Print();
	}
	else { // �� �Ǵ� ���� ���̰� 2, Ȥ�� �� �� 2�� ��
		// �迭�� ũ�Ⱑ �۱� ������ �׳� �迭 ��ü�� �����൵ �ð� �ʰ��� �߻����� �ʴ´�.
		for (int i = 0; i < R; i++) {
			int X;
			cin >> X;
			if (X == 1) {
				First_Rotation();
			}
			else if (X == 2) {
				Second_Rotation();
			}
			else if (X == 3) {
				Third_Rotation();
			}
			else if (X == 4) {
				Fourth_Rotation();
			}
			else if (X == 5) {
				Fifth_Rotation();
			}
			else if (X == 6) {
				Sixth_Rotation();
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << A[i][j] << " ";
			}
			cout << "\n";
		}
	}

	getchar();
	getchar();
	return 0;
}