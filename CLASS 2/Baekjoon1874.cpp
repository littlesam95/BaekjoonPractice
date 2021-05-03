#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int*stackArr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> stackArr[i];
	}

	stack<int> st;
	int number = 1;
	char*result = new char[(n * 2)];
	int index = 0;
	bool res = true;
	for (int i = 0; i < n; i++) {
		if (st.size() == 0) { // stack이 비어있다면
			while (number <= stackArr[i]) { // 처음 수부터 i번째 수열에 있는 수까지 1씩 증가시키며 push
				st.push(number);
				number++;
				result[index++] = '+';
			};
			st.pop(); // i번째 수열에 있는 수 = top pop
			result[index++] = '-';;
		}
		else { // stack이 비어있지 않다면
			if (stackArr[i] > stackArr[i - 1]) { // i-1번째 수열보다 i번째 수열에 있는 수가 더 크면
				while (number <= stackArr[i]) { // i번째 수열에 있는 수까지 1씩 증가시키며 push
					st.push(number);
					number++;
					result[index++] = '+';
				};
				st.pop(); // i번째 수열에 있는 수 = top pop
				result[index++] = '-';;
			}
			else if (stackArr[i] < stackArr[i - 1]) { // i-1번째 수열보다 i번째 수열에 있는 수가 더 작으면
				if (st.top() == stackArr[i]) { // top과 i번째 수열에 있는 수 비교해서 같다면 pop
					st.pop();
					result[index++] = '-';;
				}
				else { // 다르면 반복문 종료 후 NO 출력
					res = false;
					break;
				}
			}
		}
	}

	if (res) { // 가능한 수열이라면 push와 pop 순서를 기호로 출력함
		for (int i = 0; i < index; i++) {
			cout << result[i] << "\n";
		}
	}
	else {
		cout << "NO";
	}


	getchar();
	getchar();
	return 0;
}