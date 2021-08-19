#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <algorithm>
#define MAX 200001

using namespace std;
vector<pair<pair<long long, long long>, pair<long long, long long> > > vec;

int CCW(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C) { // CCW�� �ﰢ���� ������ ���ϴ� ���İ� ���͸� �̿��Ͽ� ���Ѵ�.
	long long op = A.first * B.second + B.first * C.second + C.first * A.second;
	op -= (A.second * B.first + B.second * C.first + C.second * A.first);
	// ������ 0���� ũ�� �ݽð����, 0�̸� �� ���� ������ ���̸� 0���� ������ �ð� ����
	if (op > 0) {
		return 1;
	}
	else if (op == 0) {
		return 0;
	}
	else {
		return -1;
	}
}

int intersect(pair<pair<long long, long long>, pair<long long, long long> > A, pair<pair<long long, long long>, pair<long long, long long> > B) {
	pair<long long, long long> a = A.first;
	pair<long long, long long> b = A.second;
	pair<long long, long long> c = B.first;
	pair<long long, long long> d = B.second;
	int ab = CCW(a, b, c) * CCW(a, b, d); // ab���п��� �ٸ� ������ �� �� c, d���� CCW�� ���
	int cd = CCW(c, d, a) * CCW(c, d, b); // cd���п��� �ٸ� ������ �� �� a, b���� CCW�� ���
	if ((ab == 0) && (cd == 0)) { // �� ��� b�� ���� c�� ��� ��ġ�� d�� ���� a�� ��� ��ġ�� �����ָ� �ȴ�.
		if (a > b) {
			swap(a, b);
		}
		if (c > d) {
			swap(c, d);
		}
		return ((c <= b) && (a <= d));
	}
	return ((ab <= 0) && (cd <= 0)); // CCW(a, b, c) * CCW(a, b, d)�� 0 �����̸�, CCW(c, d, a) * CCW(c, d, b)�� 0 ���϶�� �� ������ �����Ѵٰ� �� �� �ִ�.
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 2; i++) { // �� ������ �� �� ���� ��ǥ�� �Է¹޴´�.
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		vec.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
	}
	cout << intersect(vec[0], vec[1]) << "\n";

	getchar();
	getchar();
	return 0;
}