//#include<iostream>
//#include "math.h";
//using namespace std;
//
//class Node{
//public:
//	int number;
//	Node *next;
//
//	Node(){
//		next = 0;
//	}
//	Node(int data, Node *nextNode = 0){
//		number = data;
//		next = nextNode;
//	}
//};
//
//class SingleLinkedList{
//public:
//	Node *head, *tail;
//	int length;
//
//	SingleLinkedList(){
//		head = tail = 0;
//		length = 0;
//	}
//
//	void addToTail(int number){
//		if (tail != 0)
//		{
//			tail->next = new Node(number);
//			tail = tail->next;
//		}
//		else {
//			head = tail = new Node(number);
//		}
//		length++;
//	}
//
//	void delete_without_head(Node *node){
//		if (node != 0){
//			Node *nextNode = node->next;
//			while (nextNode != 0){
//
//				node->number = nextNode->number;
//				node = node->next;
//				nextNode = nextNode->next;
//			}
//			delete node;
//		}
//	}
//
//	void showList(){
//		for (Node *temp = head; temp != 0; temp = temp->next){
//			cout << temp->number << endl;
//		}
//		cout << "---------------------------------------" << endl;
//
//	}
//};
//
//int main() {
//
//	int testcases;
//	cin >> testcases;
//
//	for (int i = 0; i < testcases; i++){
//		int listSize;
//		cin >> listSize;
//		SingleLinkedList *linkedList = new SingleLinkedList();
//
//		for (int j = 0; j < listSize; j++){
//			int number;
//			cin >> number;
//			linkedList->addToTail(number);
//		}
//
//		int n;
//		cin >> n;
//
//		int result = linkedList->sumOfLastN_Nodes(n);
//
//		cout << result << endl;
//
//	}
//
//
//
//}