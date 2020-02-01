//#include <iostream>
//#include <stack>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* left;
//	Node* right;
//	Node* nextRight; // for level traversal
//
//	Node(int data) {
//		this->data = data;
//		left = right = 0;
//	}
//};
//
//int maxSize = 0;
//vector<int> v;
//
//class ReturnData {
//public:
//	bool isBST;
//	int size;
//	int min;
//	int max;
//};
//
//class LevelTraversalNode {
//public:
//	Node* node;
//	int level;
//	LevelTraversalNode(Node* d){
//		this->node = d;
//	}
//};
//
//
//class BST {
//public:
//
//	Node* root;
//	int size;
//
//	BST() {
//		root = 0;
//		size = 0;
//	}
//
//	void insert(int data) {
//		if (root == 0) {
//			root = new Node(data);
//		}
//		else {
//			Node* temp = root;
//			while (true) {
//				if (data > temp->data) {
//					if (temp->right != 0) {
//						temp = temp->right;
//					}
//					else {
//						temp->right = new Node(data);
//						break;
//					}
//				}
//				else {
//					if (temp->left != 0) {
//						temp = temp->left;
//					}
//					else {
//						temp->left = new Node(data);
//						break;
//					}
//				}
//			}
//		}
//		size++;
//	}
//
//	bool searchBST(Node* root, int val) {
//		if (root != 0) {
//			if (root->data == val) return true;
//			else if (val < root->data) {
//				return searchBST(root->left, val);
//			}
//			else {
//				return searchBST(root->right, val);
//			}
//		}
//		else {
//			return false;
//		}
//	}
//
//	void BFS(Node* root) {
//		if (root != 0) {
//			if (root == this->root)
//				cout << root->data << endl;
//			if (root->left)
//				cout << root->left->data << endl;
//			if (root->right)
//				cout << root->right->data << endl;
//			BFS(root->left);
//			BFS(root->right);
//		}
//	}
//
//	void preOrder(Node* root) {
//		if (root != 0) {
//			cout << root->data << endl;
//			preOrder(root->left);
//			preOrder(root->right);
//		}
//	}
//
//	void preOrderIterative() {
//		stack<Node*> s;
//		bool show = true;
//		Node* start = root;
//		Node* prev = 0;
//		while (true) {
//			if (s.empty() || start != s.top()) {
//				if (start != 0) {
//					cout << start->data << endl;
//					s.push(start);
//					if (start->left != 0 && prev != start->left) {
//						start = start->left;
//						prev = start;
//						continue;
//					}
//				}
//			}
//			if (start->right && prev != start->right) {
//
//				start = start->right;
//				prev = start;
//			}
//			else {
//				prev = s.top();
//				s.pop();
//				if (!s.empty()) {
//					start = s.top();
//				}
//				else {
//					break;
//				}
//			}
//
//		}
//	}
//
//	void postOrderIterative() {
//		stack<Node*> s;
//		bool show = true;
//		Node* start = root;
//		Node* prev = 0;
//		while (true) {
//			if (s.empty() || start != s.top()) {
//				if (start != 0) {
//
//					s.push(start);
//					if (start->left != 0 && prev != start->left) {
//						start = start->left;
//						prev = start;
//						continue;
//					}
//				}
//			}
//			if (start->right && prev != start->right) {
//
//				start = start->right;
//				prev = start;
//			}
//			else {
//				prev = s.top();
//				cout << s.top()->data << endl;
//				s.pop();
//				if (!s.empty()) {
//					start = s.top();
//				}
//				else {
//					break;
//				}
//			}
//
//		}
//	}
//
//	void inOrderIterative(Node* root) {
//		stack<Node*> s;
//		bool show = true;
//		Node* start = root;
//		Node* prev = 0;
//		while (start != 0) {
//			if (s.empty() || (!s.empty() && start != s.top())) {
//				if (start != 0) {
//
//					s.push(start);
//					if (start->left != 0 && prev != start->left) {
//						start = start->left;
//						prev = start;
//						continue;
//					}
//				}
//			}
//			if ((start->right != 0 && prev != start->right) || start->right == 0) {
//				v.push_back(start->data);
//			}
//			if (start->right && prev != start->right) {
//
//				start = start->right;
//				prev = start;
//			}
//			else {
//				prev = s.top();
//				s.pop();
//				if (!s.empty()) {
//					start = s.top();
//				}
//				else {
//					break;
//				}
//			}
//
//		}
//	}
//
//	void inOrderIterative() {
//		stack<Node*> s;
//		bool show = true;
//		Node* start = root;
//		Node* prev = 0;
//		while (start != 0) {
//			if (s.empty() || (!s.empty() && start != s.top())) {
//				if (start != 0) {
//
//					s.push(start);
//					if (start->left != 0 && prev != start->left) {
//						start = start->left;
//						prev = start;
//						continue;
//					}
//				}
//			}
//			if ((start->right != 0 && prev != start->right) || start->right == 0) {
//				cout << start->data << endl;
//			}
//			if (start->right && prev != start->right) {
//
//				start = start->right;
//				//prev = start;  return it again if the code crashes
//			}
//			else {
//				prev = s.top();
//				s.pop();
//				if (!s.empty()) {
//					start = s.top();
//				}
//				else {
//					break;
//				}
//			}
//
//		}
//	}
//
//	void inOrderIterativeTreeMerge(Node* root1, Node* root2) {
//		stack<Node*> s1, s2;
//		bool s1Finished = false;
//		bool s2Finished = false;
//		Node* start1 = root1;
//		Node* start2 = root2;
//		Node* prev1 = 0;
//		Node* prev2 = 0;
//		while (true) {
//			/*started = true;
//			if (s1.empty() && s2.empty()) started = false;*/
//			if (!s1Finished && (s1.empty() || (!s1.empty() && start1 != s1.top()))) {
//				if (start1 != 0) {
//					s1.push(start1);
//					if (start1->left != 0 && prev1 != start1->left) {
//						start1 = start1->left;
//						prev1 = start1;
//						continue;
//					}
//				}
//			}
//			if (!s2Finished && (s2.empty() || (!s2.empty() && start2 != s2.top()))) {
//				if (start2 != 0) {
//					s2.push(start2);
//					if (start2->left != 0 && prev2 != start2->left) {
//						start2 = start2->left;
//						prev2 = start2;
//						continue;
//					}
//				}
//			}
//
//			if (   (s1Finished || (start1->right && prev1 != start1->right) || start1->right == 0) && 
//				   (s2Finished || ((start2->right && prev2 != start2->right) || start2->right == 0))     ) {
//				//cout << start1->data << endl;
//				if ((!s2Finished && !s1Finished && start1->data < start2->data) || (s2Finished && !s1Finished)) {
//					cout << start1->data << endl;
//					if (start1->right && prev1 != start1->right) {
//						start1 = start1->right;
//					}
//					else if(!s1.empty()) {
//						prev1 = s1.top();
//						s1.pop();
//						if (!s1.empty()) {
//							start1 = s1.top();
//						}
//						else {
//							s1Finished = true;
//						}
//					}
//				}
//				else if ((!s2Finished && !s1Finished && start1->data >= start2->data) || (s1Finished && !s2Finished)) {
//					cout << start2->data << endl;
//					if (start2->right && prev2 != start2->right) {
//						start2 = start2->right;
//					}
//					else if(!s2.empty()) {
//						prev2 = s2.top();
//						s2.pop();
//						if (!s2.empty()) {
//							start2 = s2.top();
//						}
//						else {
//							s2Finished = true;
//						}
//					}
//				}
//				else {
//					break;
//				}
//			}
//			if (start1->right && prev1 == start1->right && !s1.empty()) {
//				prev1 = s1.top();
//				s1.pop();
//				if (!s1.empty()) {
//					start1 = s1.top();
//				}
//				else {
//					s1Finished = true;
//				}
//			} 
//			if (start2->right && prev2 == start2->right && !s2.empty()) {
//				prev2 = s2.top();
//				s2.pop();
//				if (!s2.empty()) {
//					start2 = s2.top();
//				}
//				else {
//					s2Finished = true;
//				}
//			}
//		}
//	}
//
//	bool isPairPresent(Node *root, int target)
//	{
//		v.clear();
//		inOrderIterative(root);
//		for (int i = 0; i < v.size(); i++) {
//			if (target > v[i] && 2*(target-v[i]) != target && searchBST(root, target - v[i])) {
//				return true;
//			}
//		}
//		return false;
//	}
//
//	void deleteNodeByMerging(int data) {
//
//
//		Node* temp = root;
//		Node* prevTemp = root;
//		while (true) {
//			if (temp->data == data && temp == root) {
//				Node* leftSubTreeRightMost = findRightMost(temp->left);
//				if (leftSubTreeRightMost != 0) {
//					leftSubTreeRightMost->right = temp->right;
//					root = root->left;
//				}
//				else {
//					root = root->right;
//				}
//				delete temp;
//				size--;
//				break;
//			}
//			else if (temp->data == data) {
//				Node* leftSubTreeRightMost = findRightMost(temp->left);
//				if (leftSubTreeRightMost != 0) {
//					leftSubTreeRightMost->right = temp->right;
//					if (prevTemp->data < temp->data)
//						prevTemp->right = temp->left;
//					else
//						prevTemp->left = temp->left;
//
//				}
//				else {
//					if (prevTemp->data < temp->data)
//						prevTemp->right = temp->right;
//					else
//						prevTemp->left = temp->right;
//				}
//				delete temp;
//				size--;
//				break;
//			}
//			else {
//				if (data > temp->data) {
//					if (temp->right != 0) {
//						prevTemp = temp;
//						temp = temp->right;
//					}
//					else break;
//				}
//				else if (data < temp->data) {
//					if (temp->left != 0) {
//						prevTemp = temp;
//						temp = temp->left;
//					}
//					else break;
//				}
//			}
//		}
//
//		if (size == 0) root = 0;
//	}
//
//	Node* findRightMost(Node* root) {
//		Node* treeRoot = root;
//		if (treeRoot != 0) {
//			while (true)
//			{
//				if (treeRoot->right == 0) {
//					return treeRoot;
//				}
//				else {
//					treeRoot = treeRoot->right;
//				}
//			}
//		}
//		else {
//			return treeRoot;
//		}
//	}
//
//	Node* findPrevOfRightMost(Node* root) {
//		Node* treeRoot = root;
//		Node* prev = treeRoot;
//		if (treeRoot != 0) {
//			while (true)
//			{
//				if (treeRoot->right == 0) {
//					return prev;
//				}
//				else {
//					prev = treeRoot;
//					treeRoot = treeRoot->right;
//				}
//			}
//		}
//		else {
//			return treeRoot;
//		}
//	}
//
//	Node* findPrevOfLeftMost(Node* root) {
//		Node* treeRoot = root;
//		Node* prev = treeRoot;
//		if (treeRoot != 0) {
//			while (true)
//			{
//				if (treeRoot->left == 0) {
//					return prev;
//				}
//				else {
//					prev = treeRoot;
//					treeRoot = treeRoot->left;
//				}
//			}
//		}
//		else {
//			return treeRoot;
//		}
//	}
//
//	void deleteNodeByCopying(int data) {
//		Node* temp = root;
//		Node* prevTemp = root;
//		while (root != 0) {
//			if (temp->data == data) {
//				Node* leftSubTreeRightMostPrev = findPrevOfRightMost(temp->left);
//				Node* rightSubTreeLeftMostPrev = findPrevOfLeftMost(temp->right);
//
//				if (leftSubTreeRightMostPrev != 0) {
//					if (leftSubTreeRightMostPrev->right != 0) {
//						temp->data = leftSubTreeRightMostPrev->right->data;
//						Node* oldNode = leftSubTreeRightMostPrev->right;
//						leftSubTreeRightMostPrev->right = leftSubTreeRightMostPrev->right->left;
//						delete oldNode;
//						size--;
//					}
//					else {
//						temp->data = leftSubTreeRightMostPrev->data;
//						temp->left = leftSubTreeRightMostPrev->left;
//						delete leftSubTreeRightMostPrev;
//						size--;
//					}
//				}
//				else if (rightSubTreeLeftMostPrev != 0) {
//					if (rightSubTreeLeftMostPrev->left != 0) {
//						temp->data = rightSubTreeLeftMostPrev->left->data;
//						Node* oldNode = rightSubTreeLeftMostPrev->left;
//						rightSubTreeLeftMostPrev->left = rightSubTreeLeftMostPrev->left->right;
//						delete oldNode;
//						size--;
//					}
//					else {
//						temp->data = rightSubTreeLeftMostPrev->data;
//						temp->right = rightSubTreeLeftMostPrev->right;
//						delete rightSubTreeLeftMostPrev;
//						size--;
//					}
//				}
//				else {
//					if (prevTemp->left != 0 && prevTemp->left->data == temp->data) {
//						prevTemp->left = 0;
//					}
//					else {
//						prevTemp->right = 0;
//					}
//					delete temp;
//					size--;
//				}
//				break;
//			}
//			else {
//				if (data > temp->data) {
//					if (temp->right != 0) {
//						prevTemp = temp;
//						temp = temp->right;
//					}
//					else break;
//				}
//				else if (data < temp->data) {
//					if (temp->left != 0) {
//						prevTemp = temp;
//						temp = temp->left;
//					}
//					else break;
//				}
//			}
//		}
//
//		if (size == 0) root = 0;
//	}
//
//	void getLevel_N(Node* root,int originalLevel, int currentLevel, vector<LevelTraversalNode> &v) {
//		if (root != 0) {
//			if (currentLevel - 1 == 0) {
//				LevelTraversalNode t = {root};
//				t.level = originalLevel;
//				v.push_back(t);
//			}
//			else {
//				getLevel_N(root->left, originalLevel, currentLevel - 1, v);
//				getLevel_N(root->right, originalLevel,currentLevel - 1, v);
//			}
//		}
//	}
//	void levelTraversal(Node* root) {
//		vector<LevelTraversalNode> v;
//		int currentLevel = 1;
//		while (true) {
//			int oldSize = v.size();
//			getLevel_N(root, currentLevel, currentLevel, v);
//			currentLevel++;
//			if (v.size() == oldSize) break;
//		}
//
//		for (int i = 0; i < v.size() - 1; i++) {
//			if (v[i + 1].level == v[i].level) {
//				v[i].node->nextRight = v[i + 1].node;
//			}
//		}
//	}
//	
//};
//
//void setMinAndMax(int data, ReturnData* rootResult, ReturnData* leftResult, ReturnData* rightResult) {
//	if (leftResult->size != 0) {
//		rootResult->min = min(leftResult->min, data);
//		rootResult->max = max(leftResult->max, data);
//		if (rightResult->size != 0) {
//			rootResult->min = min(rightResult->min, rootResult->min);
//			rootResult->max = max(rightResult->max, rootResult->max);
//		}
//	}
//	else if (rightResult->size != 0) {
//		rootResult->min = min(rightResult->min, data);
//		rootResult->max = max(rightResult->max, data);
//	}
//	else {
//		rootResult->min = data;
//		rootResult->max = data;
//	}
//
//}
//
//ReturnData* isTreeBST(Node *root) {
//
//	if (root == 0) {
//		ReturnData* temp = new ReturnData();
//		temp->isBST = true;
//		temp->size = 0;
//		temp->min = 0;
//		temp->max = 0;
//		return temp;
//	}
//	else {
//
//		ReturnData* leftResult = isTreeBST(root->left);
//		ReturnData* rightResult = isTreeBST(root->right);
//
//		ReturnData* rootResult = new ReturnData();
//		if (leftResult->isBST == true && rightResult->isBST == true) {
//			if ((leftResult->size == 0) || (leftResult->size > 0 && root->data > leftResult->max)) {
//				if ((rightResult->size == 0) || (rightResult->size > 0 && root->data <= rightResult->min)){
//					rootResult->isBST = true;
//					rootResult->size = leftResult->size + rightResult->size + 1;
//					maxSize = rootResult->size > maxSize ? rootResult->size : maxSize;
//					setMinAndMax(root->data, rootResult, leftResult, rightResult);
//
//					return rootResult;
//				}
//			}
//		}
//		rootResult->isBST = false;
//		rootResult->size = leftResult->size + rightResult->size + 1;
//		setMinAndMax(root->data, rootResult, leftResult, rightResult);
//		return rootResult;
//	}
//
//}
//
//int largestBst(Node *root)
//{
//	//Your code here
//	maxSize = 0;
//	isTreeBST(root);
//	return maxSize;
//}
//
//int main() {
//
//	BST tree1, tree2;
//
//	tree1.insert(30);
//	tree1.insert(20);
//	tree1.insert(40);
//	tree1.insert(10);
//	tree1.insert(25);
//	tree1.insert(38);
//	tree1.insert(2);
//	tree1.insert(15);
//
//	tree1.levelTraversal(tree1.root);
//	
//
//	/*tree2.insert(6);
//	tree2.insert(1);
//	tree2.insert(7);*/
//
//	//cout<< tree.isPairPresent(tree.root, 3) << endl;
//	//tree1.inOrderIterativeTreeMerge(tree1.root, tree2.root);
//	/*tree.deleteNodeByCopying(2);
//	tree.inOrderIterative();*/
//}