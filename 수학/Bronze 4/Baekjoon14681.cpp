#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int x, y;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> x >> y;
	if ((x > 0) && (y > 0)) {
		cout << 1 << "\n";
	}
	else if ((x < 0) && (y > 0)) {
		cout << 2 << "\n";
	}
	else if ((x < 0) && (y < 0)) {
		cout << 3 << "\n";
	}
	else if ((x > 0) && (y < 0)) {
		cout << 4 << "\n";
	}
	getchar();
	getchar();
	return 0;
}