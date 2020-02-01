//#include <iostream>
//#include <vector>
//#include <stdlib.h>     /* srand, rand */
//using namespace std;
//
//class Node {
//public:
//	int start;
//	int end;
//	vector<int> value;
//	Node* left;
//	Node* right;
//	Node() {
//		start = end = -1;
//	}
//	Node(int start, int end) {
//		this->start = start;
//		this->end = end;
//		this->left = this->right = 0;
//	}
//};
//
//class IntervalTree {
//public:
//	Node* root;
//
//	IntervalTree() {
//		this->root = NULL;
//	}
//
//	Node* mergeNodes(Node* node1, Node* node2) {
//		Node* res = new Node();
//		int i = 0, j = 0;
//		while (true) {
//			if (i < node1->value.size() && j < node2->value.size()) {
//				if (node1->value[i] < node2->value[j]) {
//					res->value.push_back(node1->value[i]);
//					i++;
//				}
//				else {
//					res->value.push_back(node2->value[j]);
//					j++;
//				}
//			}
//			else {
//				for (int z = i; z < node1->value.size(); z++) {
//					res->value.push_back(node1->value[z]);
//				}
//
//				for (int z = j; z < node2->value.size(); z++) {
//					res->value.push_back(node2->value[z]);
//				}
//				break;
//			}
//		}
//		return res;
//	}
//
//	void constructTree(vector<int> v, int start, int end, Node* node) {
//		if (start != end) {
//			int rangeLength = end - start + 1;
//
//			if (rangeLength % 2 == 0) {
//				int newEnd = ((rangeLength / 2) - 1) + start;
//				node->left = new Node(start, newEnd);
//				constructTree(v, start, newEnd, node->left);
//				node->right = new Node(newEnd + 1, end);
//				constructTree(v, newEnd + 1, end, node->right);
//				node->value = mergeNodes(node->left, node->right)->value;
//			}
//			else {
//				int newEnd = (rangeLength / 2) + start;
//				node->left = new Node(start, newEnd);
//				constructTree(v, start, newEnd, node->left);
//				node->right = new Node(newEnd + 1, end);
//				constructTree(v, newEnd + 1, end, node->right);
//				node->value = mergeNodes(node->left, node->right)->value;
//			}
//		}
//		else {
//			node->value.push_back(v[start]);
//		}
//	}
//
//	void buildTree(vector<int> v) {
//		this->root = new Node(0, v.size() - 1);
//		constructTree(v, 0, v.size() - 1, root);
//	}
//
//	Node* search(int start, int end, Node* node) {
//		if (start <= node->start && end >= node->end) {
//			return node;
//		}
//		else if ((node->end < start) || (node->start > end)) {
//			return new Node();
//		}
//		else {
//			return mergeNodes(search(start, end, node->left),
//			search(start, end, node->right));
//		}
//	}
//
//	
//};
//
//class Query {
//public:
//	int X;
//	int Y;
//	int K;
//	Query(int x, int y, int k) {
//		this->X = x;
//		this->Y = y;
//		this->K = k;
//	}
//};
//
//int main() {
//
//	int testCases;
//	cin >> testCases;
//	for (int x = 0; x < testCases; x++) {
//		int arrSize, queryNum;
//		cin >> arrSize >> queryNum;
//		vector<int> arr;
//		for (int i = 0; i < arrSize; i++) {
//			int num;//= rand() % 30;
//			cin >> num;
//			arr.push_back(num);
//		}
//		vector<Query> queries;
//		for (int i = 0; i < queryNum; i++) {
//			int X, Y, K;
//			cin >> X >> Y >> K;
//			Query q = { X, Y, K };
//			queries.push_back(q);
//		}
//		IntervalTree* t = new IntervalTree();
//		t->buildTree(arr);
//		for (int i = 0; i < queryNum; i++) {
//			Node* res = t->search(queries[i].X-1, queries[i].Y-1, t->root);
//			cout << res->value[queries[i].K - 1] << " ";
//		}
//		cout << endl;
//	}
//
//}
//
//
////int main() {
////
////	IntervalTree *t = new IntervalTree();
////	vector<int> arr = { 18,17,13,19,15,11,20,80,77,35 };
////	t->buildTree(arr);
////	Node* res = t->search(2, 4, t->root);
////
////}
//
