#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1001

using namespace std;
struct INFO {
	int Nation;
	int Gold;
	int Silver;
	int Bronze;
};

int N, K;
vector<INFO> vec;

bool comp(INFO A, INFO B) {
	if (A.Gold == B.Gold) {
		if (A.Silver == B.Silver) {
			return(A.Bronze > B.Bronze);
		}
		return (A.Silver > B.Silver);
	}
	return (A.Gold > B.Gold);
}

int main() {
	FIRST;
	cin >> N >> K;
	vec.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> vec[i].Nation >> vec[i].Gold >> vec[i].Silver >> vec[i].Bronze;
	}
	sort(vec.begin() + 1, vec.end(), comp);
	for (int i = 1; i <= N; i++) {
		if (vec[i].Nation == K) {
			int answer = i;
			for (int j = 1; j < i; j++) {
				bool Flag = true;
				if (vec[j].Gold != vec[i].Gold) {
					Flag = false;
				}
				if (vec[j].Silver != vec[i].Silver) {
					Flag = false;
				}
				if (vec[j].Bronze != vec[i].Bronze) {
					Flag = false;
				}
				if (Flag) {
					answer = j;
					break;
				}
			}
			cout << answer << "\n";
			break;
		}
	}

	getchar();
	getchar();
	return 0;
}