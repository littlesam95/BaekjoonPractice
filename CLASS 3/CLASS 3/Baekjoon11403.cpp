#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int arr[101][101];

// 플로이드-와샬 알고리즘
void floydWarshall() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ((arr[i][k] == 1) && (arr[k][j] == 1)) {
					arr[i][j] = 1;
				}
			}
		}
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

	floydWarshall();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	getchar();
	getchar();
	return 0;
}