#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
int N, M;
vector<pair<int, int>> paper;
queue<vector<pair<int, int>>> q;

bool comp(pair<int, int> A, pair<int, int> B) { // 중요도들을 오름차순으로 정렬
	return A.first < B.first;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) { // 테스트케이스 개수만큼 진행
		int order;
		cin >> N >> M;

		vector<pair<int, int>> orderArr; // 중요도들을 pair vector에 저장
		int orderArrIndex = 0; // 저장된 orderArr의 개수
		for (int i = 0; i < N; i++) {
			bool res = false;
			cin >> order;
			paper.push_back(make_pair(i, order));
			q.push(paper);
			for (int j = 0; j < orderArrIndex; j++) { // 문서의 중요도를 파악하여 중복된 중요도가 존재하면 개수를 증가시키고 없으면 orderArr에 추가
				if (orderArr[j].first == order) {
					orderArr[j].second++;
					res = true;
					break;
				}
			}
			if (!res) {
				orderArr.push_back(make_pair(order, 1));
				orderArrIndex++;
			}
		}

		sort(orderArr.begin(),orderArr.end(), comp); // orderArr를 오름차순 정렬

		int count = 0;
		vector<pair<int, int>> printOrder; // 중요도 순으로 출력되는 페이지를 순서대로 저장하기 위한 pair vector 선언
		for (int number = orderArrIndex - 1; number >= 0; number--) {
			int countNumber = q.size();
			for (int i = 0; i < countNumber; i++) {
				vector<pair<int, int>> tmpVec = q.front(); // q.front().first가 안됨
				int x = tmpVec.back().first;
				int y = tmpVec.back().second; // queue의 front의 queue, 중요도를 변수에 저장
				if (orderArr[number].first > y) { // 중요도 비교해 낮으면 맨 뒤로 보냄
					q.push(q.front());
					q.pop();
				}
				else if (orderArr[number].first == y) { // 높은 경우는 없고 같으면 pop
					count++;
					printOrder.push_back(make_pair(x, count));
					orderArr[number].second--;
					q.pop(); // printOrder에 push 후 그 중요도의 개수를 -1
					if (orderArr[number].second == 0) break; // 중요도가 0이 되면 반복문 종료
				}
			}
		}
		
		for (int i = 0; i < N; i++) {
			if (printOrder[i].first == M) {
				cout << printOrder[i].second << "\n"; // M과 일치하는 문서가 몇 번째로 나왔는 지 출력
			}
		}
	}

	getchar();
	getchar();
	return 0;
}