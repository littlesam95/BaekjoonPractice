#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false); // cout, cin ÃÖÀûÈ­

	int N;
	do {
		cin >> N;
	} while ((N < 0) || (N > 100000));

	for (int i = 1; i <= N; i++) {
		cout << i << "\n";
	}

	getchar();
	getchar();
	return 0;
}