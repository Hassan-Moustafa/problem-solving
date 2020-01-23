//#include <iostream>
//#include <stack>
//#include <vector>
//
//using namespace std;
//
//vector<int> currentResult;
//
//enum NodeType {
//	LeftNode,
//	RightNode,
//	RootNode
//} NodeTypes;
//
//class Node {
//public:
//	int value;
//	bool isLeftFound;
//	bool isRightFound;
//	int parentIndex;
//	int nodeIndex;
//	NodeType nodeType;
//	
//	Node(bool isLeftFound, bool isRightFound, int parentIndex, int nodeIndex, NodeType nodeType, int value) {
//		this->isLeftFound = isLeftFound;
//		this->isRightFound = isRightFound;
//		this->parentIndex = parentIndex;
//		this->nodeIndex = nodeIndex;
//		this->nodeType = nodeType;
//		this->value = value;
//	}
//
//};
//
//Node* getNode(vector<Node*> s, int nodeValue) {
//	for (int i = s.size() - 1; i >= 0; i--) {
//		if (s[i]->value == nodeValue) {
//			return s[i];
//		}
//	}
//}
//
//bool isNodeRightChild(vector<int> v,vector<Node*> s, int suggestedParentIndex  ,int num) {
//	
//	int currentNodeIndex = suggestedParentIndex;
//	Node* currentNode = getNode(s, v[currentNodeIndex]);
//	if (currentNode->parentIndex == -1)
//		return true;
//	Node* nodeParent = getNode(s, v[currentNode->parentIndex]);
//	while (true) {
//		if (currentNode->nodeType == LeftNode && num > nodeParent->value) {
//			return false;
//		}
//		currentNode = nodeParent;
//		if (currentNode->parentIndex == -1) 
//			return true;
//		nodeParent = getNode(s, v[currentNode->parentIndex]);
//	}
//	return true;
//}
//
//
//bool isNodeLeftChild(vector<int> v, vector<Node*> s, int suggestedParentIndex, int num) {
//
//	int currentNodeIndex = suggestedParentIndex;
//	Node* currentNode = getNode(s, v[currentNodeIndex]);
//	if (currentNode->parentIndex == -1)
//		return true;
//	Node* nodeParent = getNode(s, v[currentNode->parentIndex]);
//	while (true) {
//		if (currentNode->nodeType == RightNode && num < nodeParent->value) {
//			return false;
//		}
//		currentNode = nodeParent;
//		if (currentNode->parentIndex == -1)
//			return true;
//		nodeParent = getNode(s, v[currentNode->parentIndex]);
//	}
//	return true;
//}
//
//void convertTree(vector<int> v) {
//	int currentIndex = 0;
//	int nextIndex = currentIndex +1;
//
//	vector<Node*> s;
//	while (nextIndex < v.size()) {
//		if (currentIndex == 0 && nextIndex == 1) {
//			Node* currentNode;
//			Node* nextNode;
//			if (v[nextIndex] < v[currentIndex]) {
//				currentNode = new Node(true,false, -1, currentIndex, RootNode, v[currentIndex]);
//				nextNode = new Node(false, false, currentIndex, nextIndex, LeftNode, v[nextIndex]);
//			}
//			else {
//				currentNode = new Node(false, true, -1, currentIndex, RootNode, v[currentIndex]);
//				nextNode = new Node(false, false, currentIndex, nextIndex, RightNode, v[nextIndex]);
//			}
//			s.push_back(currentNode);
//			s.push_back(nextNode);
//			currentIndex++;
//			nextIndex++;
//		}
//		else {
//			if (v[nextIndex] < v[currentIndex]) {
//				
//				Node* nextNode = new Node(false, false, currentIndex, nextIndex , LeftNode, v[nextIndex]);
//				s.back()->isLeftFound = true;
//				s.push_back(nextNode);
//				currentIndex++;
//				nextIndex++;
//			}
//			else {
//				if (isNodeRightChild(v, s, currentIndex, v[nextIndex])) {
//					Node* nextNode = new Node(false, false, currentIndex, nextIndex, RightNode, v[nextIndex]);
//					s.back()->isRightFound = true;
//					s.back()->isLeftFound = true;
//					s.push_back(nextNode);
//					currentIndex = nextIndex;
//					nextIndex++;
//				}
//				else {
//					currentResult.push_back(s.back()->value);
//					s.pop_back();
//					currentIndex = s.back()->nodeIndex;
//
//
//				}
//			}
//		}
//	}
//	for (int i = s.size() - 1; i >= 0; i--) {
//		currentResult.push_back(s.back()->value);
//		s.pop_back();
//	}
//}
//
//bool checkIfArrIsPreorder(vector<int> v) {
//	int currentIndex = 0;
//	int nextIndex = currentIndex + 1;
//
//	vector<Node*> s;
//	while (nextIndex < v.size()) {
//		if (currentIndex == 0 && nextIndex == 1) {
//			Node* currentNode;
//			Node* nextNode;
//			if (v[nextIndex] < v[currentIndex]) {
//				currentNode = new Node(true, false, -1, currentIndex, RootNode, v[currentIndex]);
//				nextNode = new Node(false, false, currentIndex, nextIndex, LeftNode, v[nextIndex]);
//			}
//			else {
//				currentNode = new Node(false, true, -1, currentIndex, RootNode, v[currentIndex]);
//				nextNode = new Node(false, false, currentIndex, nextIndex, RightNode, v[nextIndex]);
//			}
//			s.push_back(currentNode);
//			s.push_back(nextNode);
//			currentIndex++;
//			nextIndex++;
//		}
//		else {
//			if (v[nextIndex] < v[currentIndex]) {
//				if (isNodeLeftChild(v, s, currentIndex, v[nextIndex])) {
//					Node* nextNode = new Node(false, false, currentIndex, nextIndex, LeftNode, v[nextIndex]);
//					s.back()->isLeftFound = true;
//					s.push_back(nextNode);
//					currentIndex++;
//					nextIndex++;
//				}
//				else {
//					return 0;
//				}
//			}
//			else {
//				if (isNodeRightChild(v, s, currentIndex, v[nextIndex])) {
//					Node* nextNode = new Node(false, false, currentIndex, nextIndex, RightNode, v[nextIndex]);
//					s.back()->isRightFound = true;
//					s.back()->isLeftFound = true;
//					s.push_back(nextNode);
//					currentIndex = nextIndex;
//					nextIndex++;
//				}
//				else {
//					currentResult.push_back(s.back()->value);
//					s.pop_back();
//					currentIndex = s.back()->nodeIndex;
//
//
//				}
//			}
//		}
//	}
//	for (int i = s.size() - 1; i >= 0; i--) {
//		currentResult.push_back(s.back()->value);
//		s.pop_back();
//	}
//	return 1;
//}
//
//vector<int> getLeafNodes(vector<int> v) {
//	int currentIndex = 0;
//	int nextIndex = currentIndex + 1;
//
//	vector<int> leafNodes;
//
//	vector<Node*> s;
//	if (v.size() == 1) {
//		return vector<int>{ v[0] };
//	}
//	while (nextIndex < v.size()) {
//		if (currentIndex == 0 && nextIndex == 1) {
//			Node* currentNode;
//			Node* nextNode;
//			if (v[nextIndex] < v[currentIndex]) {
//				currentNode = new Node(true, false, -1, currentIndex, RootNode, v[currentIndex]);
//				nextNode = new Node(false, false, currentIndex, nextIndex, LeftNode, v[nextIndex]);
//			}
//			else {
//				currentNode = new Node(false, true, -1, currentIndex, RootNode, v[currentIndex]);
//				nextNode = new Node(false, false, currentIndex, nextIndex, RightNode, v[nextIndex]);
//			}
//			s.push_back(currentNode);
//			s.push_back(nextNode);
//			currentIndex++;
//			nextIndex++;
//		}
//		else {
//			if (v[nextIndex] < v[currentIndex]) {
//				Node* nextNode = new Node(false, false, currentIndex, nextIndex, LeftNode, v[nextIndex]);
//				s.back()->isLeftFound = true;
//				s.push_back(nextNode);
//				currentIndex++;
//				nextIndex++;
//			}
//			else {
//				if (isNodeRightChild(v, s, currentIndex, v[nextIndex])) {
//					Node* nextNode = new Node(false, false, currentIndex, nextIndex, RightNode, v[nextIndex]);
//					s.back()->isRightFound = true;
//					s.back()->isLeftFound = true;
//					s.push_back(nextNode);
//					currentIndex = nextIndex;
//					nextIndex++;
//				}
//				else {
//					if (!s.back()->isLeftFound && !s.back()->isRightFound) {
//						leafNodes.push_back(s.back()->value);
//					}
//					currentResult.push_back(s.back()->value);
//					s.pop_back();
//					currentIndex = s.back()->nodeIndex;
//				}
//			}
//		}
//	}
//	for (int i = s.size() - 1; i >= 0; i--) {
//		currentResult.push_back(s.back()->value);
//		if (!s.back()->isLeftFound && !s.back()->isRightFound) {
//			leafNodes.push_back(s.back()->value);
//		}
//		s.pop_back();
//	}
//	return leafNodes;
//}
//
//void main() {
//
//	int testCases;
//	cin >> testCases;
//	vector<vector<int>> res;
//	for (int i = 0; i < testCases; i++) {
//		int arrSize;
//		cin >> arrSize;
//		vector<int> arr;
//		for (int j = 0; j < arrSize; j++) {
//			int num;
//			cin >> num;
//			arr.push_back(num);
//		}
//		//cout << checkIfArrIsPreorder(arr)<< endl;
//		vector<int> leafNodes = getLeafNodes(arr);
//		for (int j = 0; j < leafNodes.size() - 1; j++) {
//			cout << leafNodes[j] << " ";
//		}
//		cout << leafNodes[leafNodes.size() - 1] << endl;
//		/*for (int j = 0; j < currentResult.size() - 1; j++) {
//			cout << currentResult[j] << " ";
//		}
//		cout << currentResult[currentResult.size() - 1] << endl;*/
//		currentResult.clear();
//	}
//}