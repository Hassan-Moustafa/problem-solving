//#include <iostream>
//#include <stack>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	int BF;
//	Node* left;
//	Node* right;
//	Node* parent;
//
//	Node(int data) {
//		this->data = data;
//		left = right = parent = 0;
//		BF = 0;
//	}
//};
//
//class AVL {
//public:
//
//	Node* root;
//	int size;
//
//	AVL() {
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
//						temp->right->parent = temp;
//						updateBalanceFactors(temp->right, data);
//						break;
//					}
//				}
//				else {
//					if (temp->left != 0) {
//						temp = temp->left;
//					}
//					else {
//						temp->left = new Node(data);
//						temp->left->parent = temp;
//						updateBalanceFactors(temp->left, data);
//						break;
//					}
//				}
//			}
//		}
//		size++;
//	}
//
//	void updateBalanceFactors(Node* nodeJustInserted, int data){
//
//		Node* parentNode = nodeJustInserted->parent;
//		if (nodeIsLeftChildOfParent(nodeJustInserted, parentNode)){
//			parentNode->BF--;
//		}
//		else {
//			parentNode->BF++;
//		}
//
//		while (parentNode != root && parentNode->BF != 2 && parentNode->BF != -2) {
//			nodeJustInserted = parentNode;
//			parentNode = parentNode->parent;
//			if (nodeJustInserted->BF == 0) break;
//			if (nodeIsLeftChildOfParent(nodeJustInserted, parentNode)) {
//				parentNode->BF--;
//			}
//			else parentNode->BF++;
//		}
//
//		if (parentNode->BF == 2 || parentNode->BF == -2) {
//			// rebalance the tree from that node.
//			rebalanceTree(parentNode, data);
//		}
//	}
//
//	void rebalanceTree(Node* parentNode, int insertedData) {
//		
//		// right child - right subtree
//		if (insertedData > parentNode->data && insertedData > parentNode->right->data){ 
//			Node* Q = parentNode->right;
//			Q->BF = 0;
//			rotateNodeLeft(Q);
//		}
//		// right child - left subtree
//		else if (insertedData > parentNode->data && insertedData < parentNode->right->data) {
//			Node* R = parentNode->right->left;
//			parentNode->BF = 0;
//			parentNode->right->BF = 0;
//			R->BF = 0;
//			rotateNodeRight(R);
//			rotateNodeLeft(R);
//		}
//		// left child - right subtree
//		else if (insertedData < parentNode->data && insertedData > parentNode->left->data) {
//			Node* R = parentNode->left->right;
//			parentNode->BF = 0;
//			parentNode->left->BF = 0;
//			R->BF = 0;
//			rotateNodeLeft(R);
//			rotateNodeRight(R);
//		}
//		// left child - left subtree
//		else {
//			Node* Q = parentNode->left;
//			Q->BF = 0;
//			rotateNodeRight(Q);
//		}
//	}
//
//	bool nodeIsLeftChildOfParent(Node* child, Node* parent) {
//		if (child == parent->left) {
//			return true;
//		}
//		else return false;
//	}
//
//	void rotateNodeRight(Node * node) {
//		
//		Node* parentNode = node->parent;
//		Node* grandParentNode = parentNode->parent;
//		bool parentNodeIsRoot = true;
//		if (parentNode != root){
//			if (nodeIsLeftChildOfParent(parentNode, grandParentNode)) {
//				grandParentNode->left = node;
//				node->parent = grandParentNode;
//			}
//			else {
//				grandParentNode->right = node;
//				node->parent = grandParentNode;
//			}
//			parentNodeIsRoot = false;
//		}
//
//		if (parentNodeIsRoot){
//			root = node;
//			node->parent = 0;
//		}
//
//		parentNode->left = node->right;
//		if (node->right != 0) {
//			node->right->parent = parentNode;
//		}
//		node->right = parentNode;
//		parentNode->parent = node;
//	}
//
//	void rotateNodeLeft(Node * node) {
//
//		Node* parentNode = node->parent;
//		Node* grandParentNode = parentNode->parent;
//		bool parentNodeIsRoot = true;
//		parentNode->BF = 0;
//
//		if (parentNode != root){
//			if (nodeIsLeftChildOfParent(parentNode, grandParentNode)) {
//				grandParentNode->left = node;
//				node->parent = grandParentNode;
//			}
//			else {
//				grandParentNode->right = node;
//				node->parent = grandParentNode;
//			}
//			parentNodeIsRoot = false;
//		}
//
//		if (parentNodeIsRoot) {
//			root = node;
//			node->parent = 0;
//		}
//
//		parentNode->right = node->left;
//		if (node->left != 0) {
//			node->left->parent = parentNode;
//		}
//		node->left = parentNode;
//		parentNode->parent = node;
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
//};
//
//int main() {
//	AVL tree;
//	tree.insert(25);
//	tree.insert(10);
//	tree.insert(15);
//	tree.insert(3);
//	tree.insert(3);
//
//
//}