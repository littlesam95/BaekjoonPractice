#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 21

using namespace std;
int N;
pair<int, int> Space[MAX * MAX];
vector<int> Like_Student[MAX * MAX];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int MAP[MAX][MAX];
int visited[MAX][MAX];

void init() {
	for (int i = 1; i <= (N * N); i++) {
		Space[i] = make_pair(-1, -1);
	}
}

void init2() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}

bool comp(pair<int, int> A, pair<int, int> B) {
	if (A.first == B.first) {
		return (A.second < B.second);
	}
	return (A.first < B.first);
}

void Arrange(int Student) {
	// 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
	vector<pair<int, int> > vec;
	int Most_Space = 0;
	init2();
	for (int i = 0; i < Like_Student[Student].size(); i++) {
		int Like_Member = Like_Student[Student][i];
		int CurY = Space[Like_Member].first;
		int CurX = Space[Like_Member].second;
		if ((CurY != -1) && (CurX != -1)) {
			for (int j = 0; j < 4; j++) {
				int nextY = CurY + moveY[j];
				int nextX = CurX + moveX[j];
				if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < N) && (MAP[nextY][nextX] == 0)) {
					visited[nextY][nextX]++;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Most_Space = max(Most_Space, visited[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((MAP[i][j] == 0) && (Most_Space == visited[i][j])) {
				vec.push_back(make_pair(i, j));
			}
		}
	}
	if (vec.size() == 1) {
		MAP[vec[0].first][vec[0].second] = Student;
		Space[Student] = make_pair(vec[0].first, vec[0].second);
		return;
	}
	else if (vec.size() > 1) { // 2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
		// 3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
		sort(vec.begin(), vec.end(), comp);
		int Big = -1;
		pair<int, int> Sitting = make_pair(-1, -1);
		for (int i = 0; i < vec.size(); i++) {
			int Blank = 0;
			int CurY = vec[i].first;
			int CurX = vec[i].second;
			for (int j = 0; j < 4; j++) {
				int nextY = CurY + moveY[j];
				int nextX = CurX + moveX[j];
				if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < N) && (MAP[nextY][nextX] == 0)) {
					Blank++;
				}
			}
			if (Big < Blank) {
				Big = Blank;
				Sitting = make_pair(CurY, CurX);
			}
		}
		MAP[Sitting.first][Sitting.second] = Student;
		Space[Student] = make_pair(Sitting.first, Sitting.second);
		return;
	}
}

int Satisfaction() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int Cur = MAP[i][j];
			int Good = 0;
			int CurY = i;
			int CurX = j;
			for (int k = 0; k < 4; k++) {
				int nextY = CurY + moveY[k];
				int nextX = CurX + moveX[k];
				if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < N)) {
					for (int l = 0; l < Like_Student[Cur].size(); l++) {
						if (MAP[nextY][nextX] == Like_Student[Cur][l]) {
							Good++;
							break;
						}
					}
				}
			}
			if (Good == 1) {
				res += 1;
			}
			else if (Good == 2) {
				res += 10;
			}
			else if (Good == 3) {
				res += 100;
			}
			else if (Good == 4) {
				res += 1000;
			}
		}
	}

	return res;
}

int main() {
	FIRST
	cin >> N;
	init();
	for (int i = 0; i < (N * N); i++) {
		int Student, A, B, C, D;
		cin >> Student >> A >> B >> C >> D;
		Like_Student[Student].push_back(A);
		Like_Student[Student].push_back(B);
		Like_Student[Student].push_back(C);
		Like_Student[Student].push_back(D);
		Arrange(Student);
	}
	cout << Satisfaction() << "\n";

	getchar();
	getchar();
	return 0;
}