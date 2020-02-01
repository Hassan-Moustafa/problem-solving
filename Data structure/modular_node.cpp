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
//	int modularNode(int k){
//		
//		int i = 1;
//		Node* resultNode = 0;
//		for (Node *temp = head; temp != 0; temp = temp->next){
//			if (i % k == 0){
//				resultNode = temp;
//			}
//			i++;
//		}
//
//		return resultNode != 0 ? resultNode->number : -1;
//
//	}
//
//
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
//		int k;
//		cin >> k;
//
//		int result = linkedList->modularNode(k);
//
//		cout << result << endl;
//
//	}
//
//
//
//}