#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 25
#define LL long long
#define INF 1e9

using namespace std;
int MAP[MAX];
int Another_MAP[MAX];
bool Flag = false;

bool Check_Cube() {
	if ((MAP[1] != MAP[2]) || (MAP[1] != MAP[3]) || (MAP[1] != MAP[4])) {
		return false;
	}
	if ((MAP[5] != MAP[6]) || (MAP[5] != MAP[7]) || (MAP[5] != MAP[8])) {
		return false;
	}
	if ((MAP[9] != MAP[10]) || (MAP[9] != MAP[11]) || (MAP[9] != MAP[12])) {
		return false;
	}
	if ((MAP[13] != MAP[14]) || (MAP[13] != MAP[15]) || (MAP[13] != MAP[16])) {
		return false;
	}
	if ((MAP[17] != MAP[18]) || (MAP[17] != MAP[19]) || (MAP[17] != MAP[20])) {
		return false;
	}
	if ((MAP[21] != MAP[22]) || (MAP[21] != MAP[23]) || (MAP[21] != MAP[24])) {
		return false;
	}
	return true;
}

void Copy_MAP() {
	for (int i = 1; i <= 24; i++) {
		MAP[i] = Another_MAP[i];
	}
}

void First_Rotation() { // (3, 1), (22, 24), (11, 9), (7, 5), 왼쪽 면 뒤로 돌리기
	int tmp1 = MAP[1];
	int tmp2 = MAP[3];
	MAP[1] = MAP[5];
	MAP[3] = MAP[7];
	MAP[5] = MAP[9];
	MAP[7] = MAP[11];
	MAP[9] = MAP[24];
	MAP[11] = MAP[22];
	MAP[24] = tmp1;
	MAP[22] = tmp2;
	int tmp = MAP[14];
	MAP[14] = MAP[16];
	MAP[16] = MAP[15];
	MAP[15] = MAP[13];
	MAP[13] = tmp;
}

void Second_Rotation() { // (4, 2), (21, 23), (12, 10), (8, 6), 오른쪽 면 뒤로 돌리기
	int tmp1 = MAP[2];
	int tmp2 = MAP[4];
	MAP[2] = MAP[6];
	MAP[4] = MAP[8];
	MAP[6] = MAP[10];
	MAP[8] = MAP[12];
	MAP[10] = MAP[23];
	MAP[12] = MAP[21];
	MAP[23] = tmp1;
	MAP[21] = tmp2;
	int tmp = MAP[17];
	MAP[17] = MAP[19];
	MAP[19] = MAP[20];
	MAP[20] = MAP[18];
	MAP[18] = tmp;
}

void Third_Rotation() { // (1, 3), (24, 22), (9, 11), (5, 7), 왼쪽 면 앞으로 돌리기
	int tmp1 = MAP[3];
	int tmp2 = MAP[1];
	MAP[3] = MAP[22];
	MAP[1] = MAP[24];
	MAP[22] = MAP[11];
	MAP[24] = MAP[9];
	MAP[11] = MAP[7];
	MAP[9] = MAP[5];
	MAP[7] = tmp1;
	MAP[5] = tmp2;
	int tmp = MAP[14];
	MAP[14] = MAP[13];
	MAP[13] = MAP[15];
	MAP[15] = MAP[16];
	MAP[16] = tmp;
}

void Fourth_Rotation() { // (2, 4), (23, 21), (10, 12), (6, 8), 오른쪽 면 앞으로 돌리기
	int tmp1 = MAP[4];
	int tmp2 = MAP[2];
	MAP[4] = MAP[21];
	MAP[2] = MAP[23];
	MAP[21] = MAP[12];
	MAP[23] = MAP[10];
	MAP[12] = MAP[8];
	MAP[10] = MAP[6];
	MAP[8] = tmp1;
	MAP[6] = tmp2;
	int tmp = MAP[17];
	MAP[17] = MAP[18];
	MAP[18] = MAP[20];
	MAP[20] = MAP[19];
	MAP[19] = tmp;
}

void Fifth_Rotation() { // (3, 4), (17, 19), (10, 9), (16, 14), 앞쪽 면 오른쪽으로 돌리기
	int tmp1 = MAP[3];
	int tmp2 = MAP[4];
	MAP[3] = MAP[17];
	MAP[4] = MAP[19];
	MAP[17] = MAP[10];
	MAP[19] = MAP[9];
	MAP[10] = MAP[16];
	MAP[9] = MAP[14];
	MAP[16] = tmp1;
	MAP[14] = tmp2;
	int tmp = MAP[5];
	MAP[5] = MAP[7];
	MAP[7] = MAP[8];
	MAP[8] = MAP[6];
	MAP[6] = tmp;
}

void Sixth_Rotation() { // (1, 2), (18, 20), (12, 11), (15, 13), 뒤쪽 면 오른쪽으로 돌리기
	int tmp1 = MAP[1];
	int tmp2 = MAP[2];
	MAP[1] = MAP[18];
	MAP[2] = MAP[20];
	MAP[18] = MAP[12];
	MAP[20] = MAP[11];
	MAP[12] = MAP[15];
	MAP[11] = MAP[13];
	MAP[15] = tmp1;
	MAP[13] = tmp2;
	int tmp = MAP[22];
	MAP[22] = MAP[24];
	MAP[24] = MAP[23];
	MAP[23] = MAP[21];
	MAP[21] = tmp;
}

void Seventh_Rotation() { // (4, 3), (19, 17), (9, 10), (14, 16), 앞쪽 면 왼쪽으로 돌리기
	int tmp1 = MAP[4];
	int tmp2 = MAP[3];
	MAP[4] = MAP[14];
	MAP[3] = MAP[16];
	MAP[14] = MAP[9];
	MAP[16] = MAP[10];
	MAP[9] = MAP[19];
	MAP[10] = MAP[17];
	MAP[19] = tmp1;
	MAP[17] = tmp2;
	int tmp = MAP[5];
	MAP[5] = MAP[6];
	MAP[6] = MAP[8];
	MAP[8] = MAP[7];
	MAP[7] = tmp;
}

void Eighth_Rotation() { // (2, 1), (20, 18), (11, 12), (13, 15), 뒤쪽 면 왼쪽으로 돌리기
	int tmp1 = MAP[2];
	int tmp2 = MAP[1];
	MAP[1] = MAP[13];
	MAP[2] = MAP[15];
	MAP[13] = MAP[11];
	MAP[15] = MAP[12];
	MAP[11] = MAP[20];
	MAP[12] = MAP[18];
	MAP[20] = tmp1;
	MAP[18] = tmp2;
	int tmp = MAP[22];
	MAP[22] = MAP[21];
	MAP[21] = MAP[23];
	MAP[23] = MAP[24];
	MAP[24] = tmp;
}

void Ninth_Rotation() { // (5, 6), (17, 18), (21, 22), (13, 14), 위쪽 면 시계 방향으로 돌리기
	int tmp1 = MAP[5];
	int tmp2 = MAP[6];
	MAP[5] = MAP[13];
	MAP[6] = MAP[14];
	MAP[13] = MAP[21];
	MAP[14] = MAP[22];
	MAP[21] = MAP[17];
	MAP[22] = MAP[18];
	MAP[17] = tmp1;
	MAP[18] = tmp2;
	int tmp = MAP[3];
	MAP[3] = MAP[1];
	MAP[1] = MAP[2];
	MAP[2] = MAP[4];
	MAP[4] = tmp;
}

void Tenth_Rotation() { // (7, 8), (19, 20), (23, 24), (15, 16), 아래쪽 면 시계 방향으로 돌리기
	int tmp1 = MAP[7];
	int tmp2 = MAP[8];
	MAP[7] = MAP[15];
	MAP[8] = MAP[16];
	MAP[15] = MAP[23];
	MAP[16] = MAP[24];
	MAP[23] = MAP[19];
	MAP[24] = MAP[20];
	MAP[19] = tmp1;
	MAP[20] = tmp2;
	int tmp = MAP[9];
	MAP[9] = MAP[11];
	MAP[11] = MAP[12];
	MAP[12] = MAP[10];
	MAP[10] = tmp;
}

void Eleventh_Rotation() { // (6, 5), (18, 17), (22, 21), (14, 13), 위쪽 면 반시계 방향으로 돌리기
	int tmp1 = MAP[6];
	int tmp2 = MAP[5];
	MAP[6] = MAP[18];
	MAP[5] = MAP[17];
	MAP[18] = MAP[22];
	MAP[17] = MAP[21];
	MAP[22] = MAP[14];
	MAP[21] = MAP[13];
	MAP[14] = tmp1;
	MAP[13] = tmp2;
	int tmp = MAP[3];
	MAP[3] = MAP[4];
	MAP[4] = MAP[2];
	MAP[2] = MAP[1];
	MAP[1] = tmp;
}

void Twelfth_Rotation() { // (8, 7), (20, 19), (24, 23), (16, 15), 아래쪽 면 반시계 방향으로 돌리기
	int tmp1 = MAP[8];
	int tmp2 = MAP[7];
	MAP[8] = MAP[20];
	MAP[7] = MAP[19];
	MAP[20] = MAP[23];
	MAP[19] = MAP[24];
	MAP[23] = MAP[19];
	MAP[24] = MAP[20];
	MAP[19] = tmp1;
	MAP[20] = tmp2;
	int tmp = MAP[9];
	MAP[9] = MAP[10];
	MAP[10] = MAP[12];
	MAP[12] = MAP[11];
	MAP[11] = tmp;
}

int main() {
	FIRST
	for (int i = 1; i <= 24; i++) {
		cin >> MAP[i];
	}
	for (int i = 1; i <= 24; i++) {
		Another_MAP[i] = MAP[i];
	}
	Copy_MAP();
	First_Rotation();
	if (Check_Cube()) {
		Flag = true;
		cout << Flag << "\n";
		return 0;
	}
	Copy_MAP();
	Second_Rotation();
	if (Check_Cube()) {
		Flag = true;
		cout << Flag << "\n";
		return 0;
	}
	Copy_MAP();
	Third_Rotation();
	if (Check_Cube()) {
		Flag = true;
		cout << Flag << "\n";
		return 0;
	}
	Copy_MAP();
	Fourth_Rotation();
	if (Check_Cube()) {
		Flag = true;
		cout << Flag << "\n";
		return 0;
	}
	Copy_MAP();
	Fifth_Rotation();
	if (Check_Cube()) {
		Flag = true;
		cout << Flag << "\n";
		return 0;
	}
	Copy_MAP();
	Sixth_Rotation();
	if (Check_Cube()) {
		Flag = true;
		cout << Flag << "\n";
		return 0;
	}
	Copy_MAP();
	Seventh_Rotation();
	if (Check_Cube()) {
		Flag = true;
		cout << Flag << "\n";
		return 0;
	}
	Copy_MAP();
	Eighth_Rotation();
	if (Check_Cube()) {
		Flag = true;
		cout << Flag << "\n";
		return 0;
	}
	Copy_MAP();
	Ninth_Rotation();
	if (Check_Cube()) {
		Flag = true;
		cout << Flag << "\n";
		return 0;
	}
	Copy_MAP();
	Tenth_Rotation();
	if (Check_Cube()) {
		Flag = true;
		cout << Flag << "\n";
		return 0;
	}
	Copy_MAP();
	Eleventh_Rotation();
	if (Check_Cube()) {
		Flag = true;
		cout << Flag << "\n";
		return 0;
	}
	Copy_MAP();
	Twelfth_Rotation();
	if (Check_Cube()) {
		Flag = true;
		cout << Flag << "\n";
		return 0;
	}

	cout << Flag << "\n";

	getchar();
	getchar();
	return 0;
}