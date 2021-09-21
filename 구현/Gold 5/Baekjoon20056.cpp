#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 51
#define INF 2e9

using namespace std;
struct Fireball {
	int R, C, M, S, D;
};

int N, F, K;
vector<Fireball> arr[MAX][MAX];
vector<Fireball> fireball;
int moveY[8] = { -1,-1,0,1,1,1,0,-1 };
int moveX[8] = { 0,1,1,1,0,-1,-1,-1 };
int newDir[4] = { 0,2,4,6 };
int newNotDir[4] = { 1,3,5,7 };
int answer = 0;

void Fireball_Move() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j].clear();
		}
	}
	for (int i = 0; i < fireball.size(); i++) {
		int Y = fireball[i].R;
		int X = fireball[i].C;
		int Mass = fireball[i].M;
		int Speed = fireball[i].S;
		int Dir = fireball[i].D;
		int nextY = Y + moveY[Dir] * (Speed % N);
		int nextX = X + moveX[Dir] * (Speed % N);
		if (nextY > N) {
			nextY -= N;
		}
		if (nextX > N) {
			nextX -= N;
		}
		if (nextY < 1) {
			nextY += N;
		}
		if (nextX < 1) {
			nextX += N;
		}
		arr[nextY][nextX].push_back({ nextY,nextX,Mass,Speed,Dir });
		fireball[i].R = nextY;
		fireball[i].C = nextX;
	}
}

void Fireball_Sum() {
	vector<Fireball> tmp_fireball;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j].size() == 0) { // 격자가 비어있는 경우
				continue;
			}
			if (arr[i][j].size() == 1) { // 격자에 파이어볼이 하나만 존재하는 경우
				tmp_fireball.push_back(arr[i][j][0]);
				continue;
			}
			// 격자에 파이어볼이 2개 이상 존재하는 경우
			int Mass_Sum = 0;
			int Speed_Sum = 0;
			int size = arr[i][j].size();
			bool isEven = true;
			bool isOdd = true;
			for (int k = 0; k < arr[i][j].size(); k++) {
				Mass_Sum += arr[i][j][k].M;
				Speed_Sum += arr[i][j][k].S;
				if (arr[i][j][k].D % 2 == 0) {
					isOdd = false;
				}
				else if (arr[i][j][k].D % 2 == 1) {
					isEven = false;
				}
			}
			int newMass = Mass_Sum / 5;
			int newSpeed = Speed_Sum / size;
			if (newMass == 0) {
				continue;
			}
			if (isEven || isOdd) {
				for (int k = 0; k < 4; k++) {
					tmp_fireball.push_back({ i,j,newMass,newSpeed,newDir[k] });
				}
			}
			else {
				for (int k = 0; k < 4; k++) {
					tmp_fireball.push_back({ i,j,newMass,newSpeed,newNotDir[k] });
				}
			}
		}
	}
	fireball = tmp_fireball;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> F >> K;
	for (int i = 0; i < F; i++) {
		int R, C, M, S, D;
		cin >> R >> C >> M >> S >> D;
		fireball.push_back({ R,C,M,S,D });
		arr[R][C].push_back({ R,C,M,S,D });
	}
	for (int i = 0; i < K; i++) {
		Fireball_Move();
		Fireball_Sum();
	}
	for (int i = 0; i < fireball.size(); i++) {
		answer += fireball[i].M;
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}