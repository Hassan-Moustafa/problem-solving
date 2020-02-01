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
//	int find_N_over_K_node(int k){
//		int arr[100];
//		int length = 0;
//		for (Node *temp = head; temp != 0; temp = temp->next){
//			arr[length] = temp->number;
//			length++;
//		}
//
//		float div = (float)length / k;
//		int index = ceil(div);
//		return arr[index-1];
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
//		int result = linkedList->find_N_over_K_node(k);
//
//		cout << result << endl;
//
//	}
//
//
//
//}