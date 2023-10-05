#include<iostream>
using namespace std;
struct Node {
	int key;
	Node* left, * right;
};
typedef struct Node* TREE;
void createTree(TREE& t) {
	t = NULL;
}
int main() {
	TREE test;
}