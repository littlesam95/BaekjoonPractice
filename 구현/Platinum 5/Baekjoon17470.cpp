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
	최악의 경우의 수를 생각했을 때, 100X100 크기의 배열을 200만번 연산한다면
	시간 복잡도가 매우 커지게 된다. 따라서, 배열을 전체를 돌리는 것이 아닌,
	배열을 4등분했을 때 나오는 4개의 배열의 각각의 4개의 꼭짓점만 돌려준다.
	즉 핵심은 배열 4개로 나누고 배열별로 회전시키겠다는 것이다.
*/

void init() { // 배열 4개의 각각의 꼭짓점을 저장
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

void First_Operation() { // 배열들의 각각의 모서리 부분만 상하반전
	Copy_MAP();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			MAP[3 - i][j] = Tmp[i][j];
		}
	}
}

void Second_Operation() { // 배열들의 각각의 모서리 부분만 좌우반전
	Copy_MAP();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			MAP[j][3 - i] = Tmp[j][i];
		}
	}
}

void Third_Operation() { // 배열들의 각각의 모서리 부분만 오른쪽으로 90도 회전
	Copy_MAP();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			MAP[j][3 - i] = Tmp[i][j];
		}
	}
	swap(N, M);
}

void Fourth_Operation() { // 배열들의 각각의 모서리 부분만 왼쪽으로 90도 회전
	Copy_MAP();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			MAP[3 - j][i] = Tmp[i][j];
		}
	}
	swap(N, M);
}

void Fifth_Operation() { // 4개의 배열 자체를 오른쪽으로 90도 회전
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

void Sixth_Operation() { // 4개의 배열 자체를 왼쪽으로 90도 회전
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
	하지만 행의 길이나 열의 길이가 2라면, 배열을 4등분했을 때
	4개의 배열 각각의 모서리는 4개가 아니라 2개가 될 것이다.
	게다가, 2X2 배열이라면 모서리는 1개가 된다.
	따라서, 코드가 제대로 동작하지 않을 것이다.
	그래서 본인은 이러한 경우라면 그냥 배열 자체를 돌려주기로 했다.
	어차피 배열의 크기가 작기 때문에 시간 초과가 발생하지 않는다.
*/

void Copy_A() { // 배열 자체를 복사
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Tmp_A[i][j] = A[i][j];
		}
	}
}

void First_Rotation() { // 배열 전체를 상하반전
	Copy_A();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[(N - 1) - i][j] = Tmp_A[i][j];
		}
	}
}

void Second_Rotation() { // 배열 전체를 좌우반전
	Copy_A();
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			A[j][(M - 1) - i] = Tmp_A[j][i];
		}
	}
}

void Third_Rotation() { // 배열 전체를 오른쪽으로 90도 회전
	Copy_A();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[j][(N - 1) - i] = Tmp_A[i][j];
		}
	}
	swap(N, M);
}

void Fourth_Rotation() { // 배열 전체를 왼쪽으로 90도 회전
	Copy_A();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[(M - 1) - j][i] = Tmp_A[i][j];
		}
	}
	swap(N, M);
}

void Fifth_Rotation() { // 나눈 4개의 배열 자체를 오른쪽으로 90도 회전
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

void Sixth_Rotation() { // 나눈 4개의 배열 자체를 왼쪽으로 90도 회전
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
	배열들의 모서리만 회전시켰기 때문에 이제부터는 출력을 잘 해줘야 한다.
	4등분한 배열 각각을 따져봤을 때,
	첫 번째 꼭짓점의 X, Y좌표, 두 번째 꼭짓점의 X, Y좌표, 세 번째 꼭짓점의 X, Y좌표의 대소비교를 하여
	출력을 진행한다.
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
	if ((N >= 4) && (M >= 4)) { // 행과 열의 길이가 모두 4 이상일 때
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
	else { // 행 또는 열의 길이가 2, 혹은 둘 다 2일 때
		// 배열의 크기가 작기 때문에 그냥 배열 자체를 돌려줘도 시간 초과가 발생하지 않는다.
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