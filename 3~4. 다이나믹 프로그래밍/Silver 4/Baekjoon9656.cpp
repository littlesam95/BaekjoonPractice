#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	if ((N % 2) == 1) {
		cout << "CY" << "\n";
	}
	else if ((N % 2) == 0) {
		cout << "SK" << "\n";
	}

	getchar();
	getchar();
	return 0;
}

// 실버4 맞나?