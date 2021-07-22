#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int K;
int arr[2 << 10];
vector<int> vec[15];

struct Node {
	int data;
	Node* left;
	Node* right;
};

void find_element(Node* node, int degree) {
	vec[degree].push_back(node->data);
	if (node->left != NULL) {
		find_element(node->left, degree + 1);
	}
	if (node->right != NULL) {
		find_element(node->right, degree + 1);
	}
}

Node* insert(Node* node, int data) {
	if (node == NULL) {
		node = new Node();
		node->data = data;
		node->left = node->right = NULL;
	}
	return node;
}

Node* dfs(int S, int E, Node* node) {
	if (S > E) {
		return NULL;
	}
	int mid = (S + E) / 2;
	if (node == NULL) {
		node = insert(node, arr[mid]);
	}

	node->left = dfs(S, mid - 1, node->left);
	node->right = dfs(mid + 1, E, node->right);

	return node;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	Node* root = NULL;
	cin >> K;
	for (int i = 0; i < (pow(2, K) - 1); i++) {
		cin >> arr[i];
	}
	root = dfs(0, pow(2, K) - 1, root);
	find_element(root, 1);
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}

	getchar();
	getchar();
	return 0;
}