#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	int*H = new int[T];
	int*W = new int[T];
	int*N = new int[T];
	for (int i = 0; i < T; i++) {
		cin >> H[i] >> W[i] >> N[i];
		if ((H[i] < 1) || (H[i] > 99) || (W[i] < 1) || (W[i] > 99) || (N[i] < 1) || (N[i] > H[i] * W[i])) {
			break;
		}
	}

	int X, Y;
	for (int i = 0; i < T; i++) {
		X = 1;
		while (N[i] > H[i]) {
			N[i] = N[i] - H[i];
			X++;
		};
		Y = N[i];
		cout << (Y * 100) + X << endl;
	}
	
	getchar();
	getchar();
	return 0;
}