#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 101

using namespace std;
int N;
int Y[MAX];
int X[MAX];
int From = 0;
int Value;

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Y[i];
	}
	X[0] = Y[0];  // 0번째 X는 0번째 Y가 고정이다.
	for (int i = 1; i < N; i++) {
		Value = X[From];
		From = (Value + From) % N;
		while (X[From] != 0) {
			From = (From + 1) % N;
		};
		X[From] = Y[i];
	}
	cout << N << "\n";
	for (int i = 0; i < N; i++) {
		cout << X[i] << " ";
	}
	cout << "\n";

	getchar();
	getchar();
	return 0;
}