#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 20
#define INF 2e9

using namespace std;
int N;
int arr[MAX][MAX];
int tmp_arr[MAX][MAX];
int query[5];
bool visited[MAX][MAX];
int answer = 0;

void move_left() {
	for (int Y = 0; Y < N; Y++) {
		for (int X = 0; X < N - 1; X++) {
			bool flag = false;
			if (tmp_arr[Y][X] == 0) {
				int K = X + 1;
				while (K <= N - 1) {
					if (tmp_arr[Y][K] != 0) {
						flag = true;
						break;
					}
					K++;
				};
				if (flag) {
					tmp_arr[Y][X] = tmp_arr[Y][K];
					tmp_arr[Y][K] = 0;
				}
			}
		}
	}
	for (int Y = 0; Y < N; Y++) {
		for (int X = 0; X < N - 1; X++) {
			if (tmp_arr[Y][X] == tmp_arr[Y][X + 1]) {
				tmp_arr[Y][X] += tmp_arr[Y][X + 1];
				tmp_arr[Y][X + 1] = 0;
			}
		}
	}
	for (int Y = 0; Y < N; Y++) {
		for (int X = 0; X < N - 1; X++) {
			bool flag = false;
			if (tmp_arr[Y][X] == 0) {
				int K = X + 1;
				while (K <= N - 1) {
					if (tmp_arr[Y][K] != 0) {
						flag = true;
						break;
					}
					K++;
				};
				if (flag) {
					tmp_arr[Y][X] = tmp_arr[Y][K];
					tmp_arr[Y][K] = 0;
				}
			}
		}
	}
}

void move_up() {
	for (int Y = 0; Y < N - 1; Y++) {
		for (int X = 0; X < N; X++) {
			bool flag = false;
			if (tmp_arr[Y][X] == 0) {
				int K = Y + 1;
				while (K <= N - 1) {
					if (tmp_arr[K][X] != 0) {
						flag = true;
						break;
					}
					K++;
				};
				if (flag) {
					tmp_arr[Y][X] = tmp_arr[K][X];
					tmp_arr[K][X] = 0;
				}
			}
		}
	}
	for (int Y = 0; Y < N - 1; Y++) {
		for (int X = 0; X < N; X++) {
			if (tmp_arr[Y][X] == tmp_arr[Y + 1][X]) {
				tmp_arr[Y][X] += tmp_arr[Y + 1][X];
				tmp_arr[Y + 1][X] = 0;
			}
		}
	}
	for (int Y = 0; Y < N - 1; Y++) {
		for (int X = 0; X < N; X++) {
			bool flag = false;
			if (tmp_arr[Y][X] == 0) {
				int K = Y + 1;
				while (K <= N - 1) {
					if (tmp_arr[K][X] != 0) {
						flag = true;
						break;
					}
					K++;
				};
				if (flag) {
					tmp_arr[Y][X] = tmp_arr[K][X];
					tmp_arr[K][X] = 0;
				}
			}
		}
	}
}

void move_right() {
	for (int Y = 0; Y < N; Y++) {
		for (int X = N - 1; X > 0; X--) {
			bool flag = false;
			if (tmp_arr[Y][X] == 0) {
				int K = X - 1;
				while (K >= 0) {
					if (tmp_arr[Y][K] != 0) {
						flag = true;
						break;
					}
					K--;
				};
				if (flag) {
					tmp_arr[Y][X] = tmp_arr[Y][K];
					tmp_arr[Y][K] = 0;
				}
			}
		}
	}
	for (int Y = 0; Y < N; Y++) {
		for (int X = N - 1; X > 0; X--) {
			if (tmp_arr[Y][X] == tmp_arr[Y][X - 1]) {
				tmp_arr[Y][X] += tmp_arr[Y][X - 1];
				tmp_arr[Y][X - 1] = 0;
			}
		}
	}
	for (int Y = 0; Y < N; Y++) {
		for (int X = N - 1; X > 0; X--) {
			bool flag = false;
			if (tmp_arr[Y][X] == 0) {
				int K = X - 1;
				while (K >= 0) {
					if (tmp_arr[Y][K] != 0) {
						flag = true;
						break;
					}
					K--;
				};
				if (flag) {
					tmp_arr[Y][X] = tmp_arr[Y][K];
					tmp_arr[Y][K] = 0;
				}
			}
		}
	}
}

void move_down() {
	for (int Y = N - 1; Y > 0; Y--) {
		for (int X = 0; X < N; X++) {
			bool flag = false;
			if (tmp_arr[Y][X] == 0) {
				int K = Y - 1;
				while (K >= 0) {
					if (tmp_arr[K][X] != 0) {
						flag = true;
						break;
					}
					K--;
				};
				if (flag) {
					tmp_arr[Y][X] = tmp_arr[K][X];
					tmp_arr[K][X] = 0;
				}
			}
		}
	}
	for (int Y = N - 1; Y > 0; Y--) {
		for (int X = 0; X < N; X++) {
			if (tmp_arr[Y][X] == tmp_arr[Y - 1][X]) {
				tmp_arr[Y][X] += tmp_arr[Y - 1][X];
				tmp_arr[Y - 1][X] = 0;
			}
		}
	}
	for (int Y = N - 1; Y > 0; Y--) {
		for (int X = 0; X < N; X++) {
			bool flag = false;
			if (tmp_arr[Y][X] == 0) {
				int K = Y - 1;
				while (K >= 0) {
					if (tmp_arr[K][X] != 0) {
						flag = true;
						break;
					}
					K--;
				};
				if (flag) {
					tmp_arr[Y][X] = tmp_arr[K][X];
					tmp_arr[K][X] = 0;
				}
			}
		}
	}
}

void solution() {
	for (int i = 0; i < 5; i++) {
		switch (query[i]) {
		case 0 :
			move_left();
			break;
		case 1 :
			move_up();
			break;
		case 2 :
			move_right();
			break;
		case 3 :
			move_down();
			break;
		default :
			break;
		}
	}
	int big = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			big = max(big, tmp_arr[i][j]);
		}
	}
	answer = max(answer, big);
}

void DFS(int depth) {
	if (depth == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				tmp_arr[i][j] = arr[i][j];
			}
		}
		solution();
		return;
	}

	for (int i = 0; i < 4; i++) {
		query[depth] = i;
		DFS(depth + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	DFS(0);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}