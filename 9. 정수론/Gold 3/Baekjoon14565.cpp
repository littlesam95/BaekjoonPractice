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

long long N, A;
vector<long long> s, t, r, q;

// È®Àå À¯Å¬¸®µå È£Á¦¹ý ¾Ë°í¸®Áò
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

	Info ret = { r[r.size() - 2],s[s.size() - 1],t[t.size() - 1] };
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

	cin >> N >> A;
	Info answer = xGCD(N, A);
	cout << N - A << " "; // µ¡¼À ¿ª¿ø
	if (answer.gcd != 1) {
		cout << -1 << "\n";
	}
	else { // °ö¼À ¿ª¿ø
		cout << (N + answer.t) % N << "\n";
	}

	getchar();
	getchar();
	return 0;
}