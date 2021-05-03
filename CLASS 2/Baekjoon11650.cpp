#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

struct Matrix {
	int x;
	int y;
};

bool order(Matrix a, Matrix b) {
	if (a.x < b.x) {
		return true;
	}
	else if (a.x == b.x) {
		return (a.y < b.y);
	}
	else {
		return false;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<Matrix> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i].x >> vec[i].y;
	}

	sort(vec.begin(), vec.end(), order);

	for (int i = 0; i < N; i++) {
		cout << vec[i].x << " " << vec[i].y << "\n";
	}

	getchar();
	getchar();
	return 0;
}