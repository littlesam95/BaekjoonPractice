#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 500001

using namespace std;
int N;
int arr[MAX];
stack<pair<int, int> > s;
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		while (!s.empty()) { // stack이 empty가 아니라면
			if (s.top().first < arr[i]) { // 현재 사람의 키보다 작은 사람들은 전부 pop시켜준다.
				answer += s.top().second;
				s.pop();
			}
			else {
				break;
			}
		};
		if (s.empty()) { // stack이 empty라면 현재 사람의 키, 1을 pair로 묶어 push시켜준다.
			s.push(make_pair(arr[i], 1));
		}
		else { // stack이 empty일 때
			if (s.top().first == arr[i]) { // 현재 사람의 키와 stack의 top에 위치하는 사람의 키가 같다면 top에 위치하는 사람의 second(연속 몇 명)을 수정해준다.
				pair<int, int> tmp = s.top();
				s.pop();
				answer += tmp.second;
				if (!s.empty()) { // stack이 비어있지 않다면 stack 내 제일 큰 사람과 쌍을 이루므로 답을 1 증가시켜준다.
					answer++;
				}
				tmp.second++;
				s.push(tmp);
			}
			else { // 현재 사람의 키가 더 작다면 push해준다.
				s.push(make_pair(arr[i], 1));
				answer++; // 현재 사람보다 처음으로 키가 큰 사람과 쌍을 이루므로 답을 1 증가시켜준다.
			}
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}