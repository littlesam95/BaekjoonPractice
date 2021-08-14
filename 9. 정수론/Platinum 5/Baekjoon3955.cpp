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

// 확장 유클리드 호제법 알고리즘
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
		if (answer.gcd != 1) { // Kx + Cy = 1의 정수해를 구하는 문제이다. 따라서 GCD가 1이 아니라면 답을 구할 수 없음
			cout << "IMPOSSIBLE"<< "\n";
		}
		else if (C == 1) { // 봉지에 들어있는 사탕이 1개일 때
			if (K + 1 > 1000000000) { // 사람이 10^9-1명 이상 존재한다면 10^9개 이상의 사탕 봉지를 구매해야 하는데 그것은 불가능하다.
				cout << "IMPOSSIBLE" << "\n";
			}
			else { // 사람이 10^9-1명 미만 존재한다면 하나씩 나눠준 상태에서 1개가 더 있어야 하기 때문에 K+1봉지를 구입한다.
				cout << K + 1 << "\n";
			}
		}
		else if (K == 1) { // 사람이 1명일 때, 사탕 봉지에 들어있는 사탕의 개수가 1개일 때는 위에서 따졌으므로 1개보다 많이 들어있는 경우의 수만 따진다.
			cout << 1 << "\n";
		}
		else { // 위에서 따진 예외들에 해당하지 않는 경우, 곱셈 역원을 이용하여 y를, 즉 사탕의 봉지 개수를 구한다.
			// Cy를 K로 나눈 나머지가 1이 되어야 하므로, GCD가 1일 경우 곱셈의 역원에 해당하는 y를 구하면 끝.
			cout << (K + answer.t) % K << "\n";
		}
	};

	getchar();
	getchar();
	return 0;
}