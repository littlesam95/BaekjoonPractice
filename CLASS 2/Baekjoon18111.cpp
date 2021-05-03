#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M, B;
	cin >> N >> M >> B;

	int arr[502][502];
	int small = 256;
	int big = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (small > arr[i][j]) {
				small = arr[i][j];
			}
			if (big < arr[i][j]) {
				big = arr[i][j];
			}
		}
	}
	int ansT = 1000000000;
	int ansH = -1;

	for (int height = small; height <= big; height++) {
		int inven = 0;
		int remove = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int subHeight = arr[i][j] - height;
				if (subHeight < 0) {
					inven -= subHeight;
				}
				else {
					remove += subHeight;
				}
			}
		}
		if (inven <= (remove + B)) {
			int tmpT = inven + (remove * 2);
			if (ansT >= tmpT) {
				ansT = tmpT;
				ansH = height;
			}
		}
	}

	cout << ansT << " " << ansH;

	getchar();
	getchar();
	return 0;
}