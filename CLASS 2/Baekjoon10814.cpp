#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct User {
	int age;
	string name;
	int order;
};

bool selectUser(User a, User b) {
	if (a.age < b.age) {
		return true;
	}
	else if (a.age == b.age) {
		return (a.order < b.order);
	}
	else {
		return false;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	
	vector<User> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i].age;
		cin.ignore();
		getline(cin, vec[i].name);
		vec[i].order = i + 1;
	}

	sort(vec.begin(), vec.end(), selectUser);

	for (int i = 0; i < N; i++) {
		if (i < N - 1) {
			cout << vec[i].age << " " << vec[i].name << "\n";
		}
		else if (i == N - 1) {
			cout << vec[i].age << " " << vec[i].name;
		}
	}

	getchar();
	getchar();
	return 0;
}