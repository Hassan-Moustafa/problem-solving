//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* left;
//	Node* right;
//
//	Node(int key) {
//		data = key;
//		left = right = NULL;
//	}
//};
//
//class Entry {
//public: 
//	int value;
//	int level;
//};
//
//vector<vector<Entry>> naturalNumbers;
//vector<vector<Entry>> negativeNumbers = { vector<Entry> {} };
//
//vector<Entry> organizeListByPriority(vector<Entry> arr) {
//	int index = arr.size() - 1;
//	for (int i = arr.size() - 2; i >= 0; i--) {
//		if (arr[index].level < arr[i].level) {
//			swap(arr[index], arr[i]);
//			index = i;
//		}
//		else {
//			break;
//		}
//	}
//	return arr;
//}
//
//void setNumber(int indicator, int value, int level) {
//	if (indicator >= 0) {
//		int maxIndex = (naturalNumbers.size() - 1);
//		if (indicator <= maxIndex) {
//			Entry e;
//			e.value = value;
//			e.level = level;
//			naturalNumbers[indicator].push_back(e);
//			naturalNumbers[indicator] = organizeListByPriority(naturalNumbers[indicator]);
//		}
//		else {
//			Entry e;
//			e.value = value;
//			e.level = level;
//			vector<Entry> t = { e };
//			naturalNumbers.push_back(t);
//		}
//	}
//	else {
//		int absIndicator = indicator * -1;
//		int maxIndex = (negativeNumbers.size() - 1);
//		if (absIndicator <= maxIndex) {
//			Entry e;
//			e.value = value;
//			e.level = level;
//			negativeNumbers[absIndicator].push_back(e);
//			negativeNumbers[absIndicator] = organizeListByPriority(negativeNumbers[absIndicator]);
//		}
//		else {
//			Entry e;
//			e.value = value;
//			e.level = level;
//			vector<Entry> t = { e };
//			negativeNumbers.push_back(t);
//		}
//	}
//}
//
//Node* insert(Node* node, int key)
//{
//	if (node == NULL) return new Node(key);
//	if (key < node->data)
//		node->left = insert(node->left, key);
//	else if (key > node->data)
//		node->right = insert(node->right, key);
//	return node;
//}
//
//void _verticalOrder(Node* root, int indicator, int level) {
//	if (root != 0) {
//		setNumber(indicator, root->data, level);
//		_verticalOrder(root->left, indicator - 1, level + 1);
//		_verticalOrder(root->right, indicator + 1, level + 1);
//	}
//}
//
//
//void printResult() {
//	for (int i = negativeNumbers.size() - 1; i >= 1; i--) {
//		for (int j = 0; j < negativeNumbers[i].size(); j++) {
//			cout << negativeNumbers[i][j].value << " ";
//		}
//	}
//
//	for (int i = 0; i < naturalNumbers.size(); i++) {
//		for (int j = 0; j < naturalNumbers[i].size(); j++) {
//			cout << naturalNumbers[i][j].value << " ";
//		}
//	}
//}
//
//void verticalOrder(Node* root)
//{
//	//Your code here
//	_verticalOrder(root, 0, 0);
//	printResult();
//	naturalNumbers.clear();
//	negativeNumbers.clear();
//	negativeNumbers = { vector<Entry> {} };
//}
//
//
//
//
//int main() {
//	int t;
//	Node* child;
//	//scanf_s("%d\n", &t);
//	cin >> t;
//	while (t--) {
//		map<int, Node*> m;
//		int n;
//		//scanf_s("%d\n", &n);
//		cin >> n;
//		Node* root = NULL;
//		while (n--) {
//			Node* parent;
//			char lr;
//			int n1, n2;
//			//scanf_s("%d %d %c", &n1, &n2, &lr);
//			cin >> n1 >> n2 >> lr;
//
//			if (m.find(n1) == m.end()) {
//				parent = new Node(n1);
//				m[n1] = parent;
//				if (root == NULL) {
//					root = parent;
//				}
//			}
//			else {
//				parent = m[n1];
//			}
//			child = new Node(n2);
//			if (lr == 'L')
//				parent->left = child;
//			else
//				parent->right = child;
//			m[n2] = child;
//		}
//		verticalOrder(root);
//		cout << endl;
//	}
//	
//}