//#include <iostream>
//#include <stack>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//
//class Node {
//public:
//	int data;
//	Node* left;
//	Node* right;
//
//	Node(int data) {
//		this->data = data;
//		left = right = 0;
//	}
//};
//
//class BST {
//public:
//	Node* root;
//};
//
//class MinMax {
//public:
//	Node* min;
//	Node* max;
//};
//
//vector<Node*> v;
//void inOrderIterative(Node* root) {
//	stack<Node*> s;
//	bool show = true;
//	Node* start = root;
//	Node* prev = 0;
//	while (start != 0) {
//		if (s.empty() || (!s.empty() && start != s.top())) {
//			if (start != 0) {
//
//				s.push(start);
//				if (start->left != 0 && prev != start->left) {
//					start = start->left;
//					prev = start;
//					continue;
//				}
//			}
//		}
//		if ((start->right != 0 && prev != start->right) || start->right == 0) {
//			v.push_back(start);
//			// v[vSize] = start;
//			// vSize++;
//		}
//		if (start->right && prev != start->right) {
//
//			start = start->right;
//			prev = start;
//		}
//		else {
//			prev = s.top();
//			s.pop();
//			if (!s.empty()) {
//				start = s.top();
//			}
//			else {
//				break;
//			}
//		}
//
//	}
//}
//
//MinMax getMinMax(vector<Node*> arr) {
//	Node* min = arr[0];
//	Node* max = arr[0];
//	for (int i = 1; i < arr.size(); i++){
//		if (arr[i]->data > max->data) {
//			max = arr[i];
//		}
//		else if (arr[i]->data < min->data) {
//			min = arr[i];
//		}
//	}
//
//	MinMax temp;
//	temp.min = min;
//	temp.max = max;
//	return temp;
//}
//
//Node *correctBST(struct Node* root)
//{
//	// add code here.
//	inOrderIterative(root);
//	int firstIndex = -1;
//	int secondIndex = -1;
//
//	for (int i = 1; i < v.size(); i++) {
//		if (v[i]->data < v[i - 1]->data) {
//			if (firstIndex == -1) firstIndex = i;
//			else secondIndex = i;
//		}
//	}
//
//	if (secondIndex == -1) {
//		int temp = v[firstIndex]->data;
//		v[firstIndex]->data = v[firstIndex - 1]->data;
//		v[firstIndex - 1]->data = temp;
//	}
//	else {
//		vector<Node*> t;
//		t.push_back(v[firstIndex]);
//		t.push_back(v[firstIndex - 1]);
//		t.push_back(v[secondIndex]);
//		t.push_back(v[secondIndex - 1]);
//		MinMax minmax = getMinMax(t);
//
//		int temp = minmax.min->data;
//		minmax.min->data = minmax.max->data;
//		minmax.max->data = temp;
//	}
//
//	return root;
//}
//
//int main() {
//
//	BST t;
//	t.root = new Node(10);
//	Node* root = t.root;
//	
//	root->left = new Node(5);
//	root->right = new Node(8);
//
//	root->left->left = new Node(2);
//	root->left->right = new Node(20);
//
//	Node* newRoot = correctBST(t.root);
//
//}