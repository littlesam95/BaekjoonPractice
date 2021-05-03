#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
int N;
vector<int> A;

int Mid(vector<int>& A, int N) {
	sort(A.begin(), A.end());
	if (N % 2 == 0) {
		return A[(N - 1) / 2];
	}
	else {
		return A[N / 2];
	}
}

bool comp(const pair<int, int>&A, const pair<int, int>&B) {
	if (A.second == B.second) {
		return A.first < B.first;
	}
	else {
		return A.second > B.second;
	}
}

// pair형 vector
int Most(vector<int> A) {
	vector<pair<int, int>> count; // key = 수, value = 빈도수를 저장할 pair형 vector 선언
	vector<int>::size_type i;

	for (i = 0; i < A.size(); i++) {
		if (count.empty()) {
			count.push_back(pair<int, int>(A[i], 1));
			continue;
		}

		if (count.back().first == A[i]) { // 같은 수가 있으면
			pair<int, int> tmp = count.back(); // 임시로 pair형 vector 선언해 그 수에 해당하는 key를 가진 vector로 초기화
			tmp.second++; // 빈도수 1 증가
			count.pop_back(); // 해당 수에 해당하는 key를 가진 vector를 pop
			count.push_back(tmp); // 빈도수를 1 증가시킨 vector를 push
		}
		else {
			count.push_back(pair<int, int>(A[i], 1)); // count가 비어있으면 첫 번째 수를 count에 push
		}
	}

	sort(count.begin(), count.end(), comp);
	if (count[0].second == count[1].second) {
		return count[1].first;
	}
	else {
		return count[0].first;
	}
}

int Scope(vector<int> A) {
	int low = A[0];
	int high = A[0];
	for (int i = 0; i < N; i++) {
		if (A[i] < low) {
			low = A[i];
		}
		if (A[i] > high) {
			high = A[i];
		}
	}

	return (high - low);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;

	double sum = 0;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		sum += number;
		A.push_back(number);
	}

	if (N > 1) {
		double avg = sum / (double)N;
		cout << round(avg) << "\n"; // 산술평균
		cout << Mid(A, N) << "\n"; // 중앙값
		cout << Most(A) << "\n"; // 최빈값
		cout << Scope(A);
	}
	else if (N == 1) {
		cout << A[0] << "\n";
		cout << A[0] << "\n";
		cout << A[0] << "\n";
		cout << 0 << "\n";
	}

	getchar();
	getchar();
	return 0;
}