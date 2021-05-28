#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N, r, c;
int res = 0;

// �ǹ����� �³�?
void calc(int x, int y, int n) {
	if ((x == r) && (y == c)) {
		cout << res << "\n";
		return;
	}

	if ((r < (x + n)) && (r >= x) && (c < (y + n)) && (c >= y)) {
		calc(x, y, (n / 2));
		calc(x, (y + n / 2), (n / 2));
		calc((x + n / 2), y, (n / 2));
		calc((x + n / 2), (y + n / 2), (n / 2));
	}
	else { // (r, c)�� ���� ��и��� �ƴϸ� �׳� ��и��� ũ�⸸ŭ ������ Ž���� ������ �Ѵ�.
		res += (n * n);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> r >> c;

	calc(0, 0, (1 << N));

	getchar();
	getchar();
	return 0;
}