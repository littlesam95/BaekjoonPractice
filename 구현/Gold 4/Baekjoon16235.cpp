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
#define MAX 11
#define INF 2e9

using namespace std;
struct TREE_INFO {
	int Y, X, Age;
	bool state;
};

int N, M, K;
vector<int> MAP[MAX][MAX];
int Energy[MAX][MAX];
int A[MAX][MAX];
int moveY[8] = { -1,-1,0,1,1,1,0,-1 };
int moveX[8] = { 0,1,1,1,0,-1,-1,-1 };

bool comp(TREE_INFO A, TREE_INFO B) {
	return (A.Age < B.Age);
}

void Spring_Summer_Activation() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j].size() == 0) {
				continue;
			}
			sort(MAP[i][j].begin(), MAP[i][j].end());
			vector<int> tmp_tree_vec;
			int Dead_Tree = 0;
			for (int k = 0; k < MAP[i][j].size(); k++) {
				int Tree_Age = MAP[i][j][k];
				if (Energy[i][j] >= Tree_Age) {
					Energy[i][j] -= Tree_Age;
					tmp_tree_vec.push_back(Tree_Age + 1);
				}
				else {
					Dead_Tree += (Tree_Age / 2);
				}
			}
			MAP[i][j].clear();
			for (int k = 0; k < tmp_tree_vec.size(); k++) {
				MAP[i][j].push_back(tmp_tree_vec[k]);
			}
			Energy[i][j] += Dead_Tree;
		}
	}
}

void Autumn_Activation() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j].size() == 0) {
				continue;
			}
			for (int k = 0; k < MAP[i][j].size(); k++) {
				int Tree_Age = MAP[i][j][k];
				if (Tree_Age % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int nextY = i + moveY[k];
						int nextX = j + moveX[k];
						if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= N)) {
							MAP[nextY][nextX].push_back(1);
						}
					}
				}
			}
		}
	}
}

void Winter_Activation() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Energy[i][j] += A[i][j];
		}
	}
}

long long Find_Tree() {
	long long res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			long long size = MAP[i][j].size();
			res += size;
		}
	}
	return res;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			Energy[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int Y, X, Z;
		cin >> Y >> X >> Z;
		MAP[Y][X].push_back(Z);
	}
	while (K--) {
		Spring_Summer_Activation();
		Autumn_Activation();
		Winter_Activation();
	};
	cout << Find_Tree() << "\n";

	getchar();
	getchar();
	return 0;
}