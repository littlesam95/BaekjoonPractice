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
		// �ش� ��⿡ �÷��װ� �����ִ°�
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
		// �÷��׿� �� ���� �ִ°�
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
		// �÷��׿� �� ���� ���� ���
		int idx, device_idx = -1;
		for (int j = 0; j < N; j++) {
			int last_idx = 0;
			for (int k = i + 1; k < K; k++) {
				if (plug[j] == device[k]) { // ���Ŀ� �ѹ��� ���� ���� ��� ����. if���� true��� j��° plug�� ���� �ִ� ��ġ�� ����.
					break;
				}
				last_idx++; // k��° ��ġ�� plug�� ���� ���� �ʴٸ� last_idx ����.
			}
			if (last_idx > device_idx) { // last_idx�� device_idx���� ũ�� j��° ��ġ�� plug���� ����� ����.
				idx = j;
				device_idx = last_idx;
			}
		} // �� ������ ��Ƽ�� ������ ������ŭ �ݺ�
		answer++;
		plug[idx] = device[i];
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}

// �ʹ� ������� https://jaimemin.tistory.com/759 ������.