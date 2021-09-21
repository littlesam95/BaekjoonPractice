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
struct Info {
	int Y, X;
	bool state;
};

struct Info2 {
	int Y, X;
};

int N, M;
int arr[MAX][MAX];
vector<Info2> HOUSE;
vector<Info> CHICKEN;
vector<Info2> SELECT;
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,1,0,-1 };
int answer = INF;

int BFS(int Y, int X) {
	int res = INF;
	for (int i = 0; i < SELECT.size(); i++) {
		int CY = SELECT[i].Y;
		int CX = SELECT[i].X;
		int dist = abs(CY - Y) + abs(CX - X);
		res = min(res, dist);
	}
	return res;
}

void Chicken_dist() {
	int City_chicken_dist = 0;
	for (int i = 0; i < HOUSE.size(); i++) {
		int Y = HOUSE[i].Y;
		int X = HOUSE[i].X;
		City_chicken_dist += BFS(Y, X);
	}
	answer = min(answer, City_chicken_dist);
}

void DFS(int depth, int IDX) {
	if (depth == M) {
		Chicken_dist();
		return;
	}
	for (int i = IDX; i < CHICKEN.size(); i++) {
		int Y = CHICKEN[i].Y;
		int X = CHICKEN[i].X;
		if (!CHICKEN[i].state) {
			CHICKEN[i].state = true;
			SELECT.push_back({ Y,X });
			DFS(depth + 1, i);
			SELECT.pop_back();
			CHICKEN[i].state = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				HOUSE.push_back({ i,j });
			}
			else if (arr[i][j] == 2) {
				CHICKEN.push_back({ i,j,false });
			}
		}
	}
	DFS(0, 0);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}