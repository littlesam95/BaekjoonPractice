#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
struct Info {
	long long gcd;
	long long s;
	long long t;
};

int T;
long long K, C;
vector<long long> s, t, r, q;

// Ȯ�� ��Ŭ���� ȣ���� �˰���
Info xGCD(long long a, long long b) {
	s = { 1,0 };
	t = { 0,1 };
	r = { a,b };

	while (1) {
		long long r2 = r[r.size() - 2];
		long long r1 = r[r.size() - 1];
		q.push_back(r2 / r1);
		r.push_back(r2 % r1);

		if (r[r.size() - 1] == 0) {
			break;
		}

		long long s2 = s[s.size() - 2];
		long long s1 = s[s.size() - 1];
		long long t2 = t[t.size() - 2];
		long long t1 = t[t.size() - 1];
		long long q1 = q[q.size() - 1];
		s.push_back(s2 - s1 * q1);
		t.push_back(t2 - t1 * q1);
	};

	Info ret = { r[r.size() - 2],s[s.size() - 1],t[t.size() - 1] }; // gcd, s, t
	s.clear();
	t.clear();
	r.clear();
	q.clear();

	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> K >> C;
		Info answer = xGCD(K, C);
		if (answer.gcd != 1) { // Kx + Cy = 1�� �����ظ� ���ϴ� �����̴�. ���� GCD�� 1�� �ƴ϶�� ���� ���� �� ����
			cout << "IMPOSSIBLE"<< "\n";
		}
		else if (C == 1) { // ������ ����ִ� ������ 1���� ��
			if (K + 1 > 1000000000) { // ����� 10^9-1�� �̻� �����Ѵٸ� 10^9�� �̻��� ���� ������ �����ؾ� �ϴµ� �װ��� �Ұ����ϴ�.
				cout << "IMPOSSIBLE" << "\n";
			}
			else { // ����� 10^9-1�� �̸� �����Ѵٸ� �ϳ��� ������ ���¿��� 1���� �� �־�� �ϱ� ������ K+1������ �����Ѵ�.
				cout << K + 1 << "\n";
			}
		}
		else if (K == 1) { // ����� 1���� ��, ���� ������ ����ִ� ������ ������ 1���� ���� ������ �������Ƿ� 1������ ���� ����ִ� ����� ���� ������.
			cout << 1 << "\n";
		}
		else { // ������ ���� ���ܵ鿡 �ش����� �ʴ� ���, ���� ������ �̿��Ͽ� y��, �� ������ ���� ������ ���Ѵ�.
			// Cy�� K�� ���� �������� 1�� �Ǿ�� �ϹǷ�, GCD�� 1�� ��� ������ ������ �ش��ϴ� y�� ���ϸ� ��.
			cout << (K + answer.t) % K << "\n";
		}
	};

	getchar();
	getchar();
	return 0;
}