#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
struct Customer {
	int y;
	int x;
	int dest_y;
	int dest_x;
};

struct Human_Info {
	int y;
	int x;
	int dist;
	int idx;
};

int N, M, fuel;
int car_y, car_x;
int arr[21][21];
bool visited[21][21];
bool human_finding[21][21];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
Customer Cus[401];

void init() { // 사람 - 차 간의 거리 측정을 위한 칸 방문 체크용 배열 초기화
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			human_finding[i][j] = false;
		}
	}
}

void init2() { // 사람 - 차 간의 거리 측정을 위한 칸 방문 체크용 배열 초기화
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			visited[i][j] = false;
		}
	}
}

bool comp(Human_Info A, Human_Info B) {
	if (A.dist == B.dist) {
		if (A.y == B.y) {
			return A.x < B.x;
		}
		else {
			return A.y < B.y;
		}
	}
	else {
		return A.dist < B.dist;
	}
}

int humanLen() { // 사람 - 차 간의 거리 측정을 위한 BFS 함수
	init();
	queue<pair<pair<int, int>, pair<int, int> > > q;
	human_finding[car_y][car_x] = true;
	q.push(make_pair(make_pair(car_y, car_x), make_pair(fuel, 0)));
	vector<Human_Info> vec;

	if (arr[car_y][car_x] >= 1) {
		vec.push_back({ car_y,car_x,0,arr[car_y][car_x] });
	}

	while (!q.empty()) {
		int now_y = q.front().first.first;
		int now_x = q.front().first.second;
		int now_fuel = q.front().second.first;
		int now_count = q.front().second.second;
		q.pop();

		if (arr[now_y][now_x] >= 1) {
			vec.push_back({ now_y,now_x,now_count,arr[now_y][now_x] });
		}
		if (now_fuel == 0) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y > 0) && (next_y <= N) && (next_x > 0) && (next_x <= N)) {
				if ((!human_finding[next_y][next_x]) && (arr[next_y][next_x] != -1)) {
					human_finding[next_y][next_x] = true;
					q.push(make_pair(make_pair(next_y, next_x), make_pair(now_fuel - 1, now_count + 1)));
				}
			}
		}
	};

	if (vec.size() == 0) {
		return -1;
	}
	sort(vec.begin(), vec.end(), comp);
	arr[vec[0].y][vec[0].x] = 0;
	fuel -= vec[0].dist;
	return vec[0].idx;
}

void bfs(int start_y, int start_x, int end_y, int end_x, int&used_fuel) { // 사람 목적지까지 태우기, return값은 fuel
	init2();
	queue<pair<pair<int, int>, pair<int, int> > > q;
	visited[start_y][start_x] = true;
	q.push(make_pair(make_pair(start_y, start_x), make_pair(fuel, 0)));

	// 목적지 도달하면 종료
	while (!q.empty()) {
		int now_y = q.front().first.first;
		int now_x = q.front().first.second;
		int now_fuel = q.front().second.first;
		int now_used_fuel = q.front().second.second;
		q.pop();

		if ((now_y == end_y) && (now_x == end_x)) {
				car_y = now_y;
				car_x = now_x;
				used_fuel = now_used_fuel;
				return;
		}

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y > 0) && (next_y <= N) && (next_x > 0) && (next_x <= N)) {
				if ((arr[next_y][next_x] != -1) && (!visited[next_y][next_x])) {
					visited[next_y][next_x] = true;
					q.push(make_pair(make_pair(next_y, next_x), make_pair(now_fuel - 1, now_used_fuel + 1)));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> fuel;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				arr[i][j] = -1;
			}
		}
	}
	cin >> car_y >> car_x;
	for (int i = 1; i <= M; i++) {
		int n1, n2, n3, n4;
		cin >> n1 >> n2 >> n3 >> n4;
		Cus[i] = { n1,n2,n3,n4 };
		arr[n1][n2] = i;
	}
	int human_size = M;
	while (human_size > 0) {
		int num = humanLen();
		if (num == -1) {
			fuel = -1;
			break;
		}
		int used_fuel = -1;
		bfs(Cus[num].y, Cus[num].x, Cus[num].dest_y, Cus[num].dest_x, used_fuel);
		if (used_fuel == -1) {
			fuel = -1;
			break;
		}
		if (fuel < used_fuel) {
			fuel = -1;
			break;
		}
		fuel += used_fuel;
		human_size--;
	};
	if (human_size > 0) {
		fuel = -1;
	}
	cout << fuel << "\n";

	getchar();
	getchar();
	return 0;
}