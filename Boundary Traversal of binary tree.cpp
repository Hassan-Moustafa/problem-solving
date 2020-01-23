#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int key) {
		data = key;
		left = right = NULL;
	}
};

void printBoundary(Node* root)
{

}




int main() {
	int t;
	Node* child;
	//scanf_s("%d\n", &t);
	cin >> t;
	while (t--) {
		map<int, Node*> m;
		int n;
		//scanf_s("%d\n", &n);
		cin >> n;
		Node* root = NULL;
		while (n--) {
			Node* parent;
			char lr;
			int n1, n2;
			//scanf_s("%d %d %c", &n1, &n2, &lr);
			cin >> n1 >> n2 >> lr;

			if (m.find(n1) == m.end()) {
				parent = new Node(n1);
				m[n1] = parent;
				if (root == NULL) {
					root = parent;
				}
			}
			else {
				parent = m[n1];
			}
			child = new Node(n2);
			if (lr == 'L')
				parent->left = child;
			else
				parent->right = child;
			m[n2] = child;
		}
		printBoundary(root);
		cout << endl;
	}
	
}