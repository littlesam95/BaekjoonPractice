#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int idx, a, b;
} bus;

int N, M;
vector<bus> vec1;
vector<bus> vec2;
bool line[500001] = { false, };

bool comp(const bus&A, const bus&B) {
	if (A.a == B.a) {
		return (A.b > B.b);
	}
	else {
		return (A.a < B.a);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long min_a = 1000000000000;
	long long max_b = -1;

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		bus tmp;
		long long n1, n2;
		cin >> n1 >> n2;
		tmp.idx = i + 1;
		tmp.a = n1;
		tmp.b = n2;
		if (n1 <= n2) {
			vec1.push_back(tmp);
		}
		else {
			min_a = min(min_a, n1);
			max_b = max(max_b, n2);
			tmp.b = n2 + N;

			vec2.push_back(tmp);
		}
		line[i + 1] = true;
	}
	sort(vec1.begin(), vec1.end(), comp);
	sort(vec2.begin(), vec2.end(), comp);

	int right = 0;
	for (int i = 0; i < vec1.size(); i++) {
		if (min_a <= vec1[i].a) {
			line[vec1[i].idx] = false;
		}
		if (max_b >= vec1[i].b) {
			line[vec1[i].idx] = false;
		}

		if (vec1[i].b <= right) {
			line[vec1[i].idx] = false;
		}
		else {
			right = vec1[i].b;
		}
	}

	right = 0;
	for (int i = 0; i < vec2.size(); i++) {
		if (vec2[i].b <= right) {
			line[vec2[i].idx] = false;
		}
		else {
			right = vec2[i].b;
		}
	}

	for (int i = 1; i <= M; i++) {
		if (line[i]) {
			cout << i << " ";
		}
	}

	getchar();
	getchar();
	return 0;
}

// 어려워서 https://chanhuiseok.github.io/posts/baek-32/ 참고함.