#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>

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

vector<vector<int>> levelTraversal;
//deque<int> res;

void pushNumberIntoLevel(int number, int levelNumber) {
	int size = (levelTraversal.size() - 1);
	if (levelNumber <= size) {
		levelTraversal[levelNumber].push_back(number);
	}
	else {
		levelTraversal.push_back(vector<int> {number});
	}
}

void getLevel_N(Node* root, int currentLevel, int originalLevel) {
	if (root != 0) {
		if (currentLevel - 1 == 0) {
			pushNumberIntoLevel(root->data, originalLevel - 1);
		}
		else {
			getLevel_N(root->left, currentLevel - 1, originalLevel);
			getLevel_N(root->right, currentLevel - 1, originalLevel);
		}
	}
}

void getAllLevels(Node* root) {

	int n = 1;
	while (true) {
		int oldSize = levelTraversal.size();
		getLevel_N(root, n, n);
		if (oldSize == levelTraversal.size()) break;
		n++;
	}
}

deque<Node*> mergeNodes(deque<Node*> leftResult, deque<Node*> rightResult, Node* parentNode, int parentLevel) {
	deque<Node*> temp;
	for (int i = 0; i < leftResult.size(); i++) {
		temp.push_back(leftResult[i]);
	}
	for (int i = 0; i < rightResult.size(); i++) {
		temp.push_back(rightResult[i]);
	}
	vector<int> level_N = levelTraversal[parentLevel];
	if (parentNode->data == level_N[0]) {
		temp.push_front(parentNode);
	}
	else if (parentNode->data == level_N[level_N.size() - 1]) {
		temp.push_back(parentNode);
	}
	return temp;
}

deque<Node*> _printBoundary(Node* root, int level) {
	if (root != 0) {
		if (root->left == 0 && root->right == 0) {
			return deque<Node*> {root};
		}
		else {
			return mergeNodes(
				_printBoundary(root->left, level + 1),
				_printBoundary(root->right, level + 1),
				root,
				level);
		}
	}
	else {
		return deque<Node*> {};
	}
}


void printBoundary(Node* root)
{
	levelTraversal.clear();
	getAllLevels(root);
	deque<Node*> result = _printBoundary(root, 0);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i]->data << " ";
	}
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
	}
	
}