#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
int plug[101];
vector<int> device;
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int n;
		cin >> n;
		device.push_back(n);
	}

	for (int i = 0; i < K; i++) {
		// 해당 기기에 플러그가 꽂혀있는가
		bool plugged = false;
		for (int j = 0; j < N; j++) {
			if (plug[j] == device[i]) {
				plugged = true;
				break;
			}
		}
		if (plugged) {
			continue;
		}
		// 플러그에 빈 곳이 있는가
		bool blank = false;
		for (int j = 0; j < N; j++) {
			if (!plug[j]) {
				plug[j] = device[i];
				blank = true;
				break;
			}
		}
		if (blank) {
			continue;
		}
		// 플러그에 빈 곳이 없는 경우
		int idx, device_idx = -1;
		for (int j = 0; j < N; j++) {
			int last_idx = 0;
			for (int k = i + 1; k < K; k++) {
				if (plug[j] == device[k]) { // 이후에 한번도 쓰지 않을 기기 판정. if문이 true라면 j번째 plug에 꽂혀 있는 장치는 제외.
					break;
				}
				last_idx++; // k번째 장치가 plug에 꽂혀 있지 않다면 last_idx 증가.
			}
			if (last_idx > device_idx) { // last_idx가 device_idx보다 크면 j번째 장치를 plug에서 빼기로 결정.
				idx = j;
				device_idx = last_idx;
			}
		} // 이 과정을 멀티탭 구멍의 개수만큼 반복
		answer++;
		plug[idx] = device[i];
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}

// 너무 어려워서 https://jaimemin.tistory.com/759 참고함.