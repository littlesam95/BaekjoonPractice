#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 123457
#define INF 2e9

using namespace std;
struct ROOM {
	long long T, A, H;
};

long long N, ATK;
vector<ROOM> room;
long long MaxHP = 0;

bool Monster_Battle(long long IDX, long long ATK, long long &HP) {
	long long MobATK = room[IDX].A;
	long long MobHP = room[IDX].H;
	long long CurHP = HP;
	long long nextHP = CurHP / MobATK; // 몬스터가 용사를 몇 번 때려야 용사가 죽는지 확인
	if (CurHP % MobATK != 0) {// 용사의 체력이 0 이하로 떨어지는 경우 체력을 1 더한다.
		nextHP++;
	}
	long long nextMobHP = MobHP / ATK; // 용사가 몬스터를 몇 번 때려야 몬스터가 죽는지 확인
	if (MobHP % ATK != 0) { // 몬스터의 체력이 0 이하로 떨어지는 경우 체력을 1 더한다. 
		nextMobHP++;
	}
	if (nextMobHP > nextHP) { // 전투가 끝나고 몬스터의 체력이 용사보다 많은 경우 용사가 패배
		return false;
	}
	CurHP -= (MobATK * (nextMobHP - 1)); // 용사가 승리한 경우 몬스터가 용사를 공격한 횟수 * 몬스터의 공격력만큼 용사의 체력을 깎는다.
	HP = CurHP;
	return true;
}

void Potion_Drink(long long IDX, long long &ATK, long long &HP) {
	ATK += room[IDX].A;
	HP += room[IDX].H;
}

void Find_HP(long long left, long long right) {
	long long CurHP, CurATK;
	while (left <= right) {
		CurATK = ATK;
		CurHP = left + (right - left) / 2; // 최소의 MaxHP를 이분 탐색으로 정한다.
		long long tmp = CurHP;
		bool flag = true;
		for (int i = 1; i <= N; i++) { // 1번 방부터 탐색
			if (room[i].T == 1) { // 방에 몬스터가 있는 경우
				bool Battle = Monster_Battle(i, CurATK, tmp); // 몬스터와 전투
				if (!Battle) { // 용사가 패배했을 경우
					flag = false;
					break;
				}
			}
			else if (room[i].T == 2) { // 방에 포션이 있는 경우
				Potion_Drink(i, CurATK, tmp); // 포션을 마신다.
				if (tmp > CurHP) { // 현재 체력이 이분 탐색으로 정한 MaxHP보다 높아질 경우 현재 체력이 MaxHP와 같아진다고 하였으므로
					tmp = CurHP;
				}
			}
		}
		if (flag) { // 현재 MaxHP로 공주를 구출할 수 있다면 right값을 낮춘다.
			MaxHP = CurHP;
			right = CurHP - 1;
		}
		else { // 현재 MaxHP로 공주를 구출할 수 없다면 left값을 높인다.
			left = CurHP + 1;
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> ATK;
	room.resize(N + 1);
	for (int i = 1; i <= N; i++) { // 1번부터 N번까지의 방 정보를 입력받는다.
		cin >> room[i].T >> room[i].A >> room[i].H;
	}
	Find_HP(1, LLONG_MAX); // 최솟값은 1, 최댓값은 long long의 최댓값
	cout << MaxHP << "\n";

	getchar();
	getchar();
	return 0;
}