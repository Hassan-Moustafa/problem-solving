//#include<iostream>
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
//	// Segregate even and odd nodes
//	Node* segregateEvenOdds(Node *head){
//		Node *evenListHead = 0, *evenListTail = 0, *oddListHead = 0, *oddListTail = 0;
//
//		while (head != 0){
//			if (head->number % 2 == 0){
//				Node *temp = new Node(head->number);
//				if (evenListHead == 0) {
//					evenListHead = temp;
//				}
//				temp->next = 0;
//				if (evenListTail != 0)
//					evenListTail->next = temp;
//				evenListTail = temp;
//			} else {
//				Node *temp = new Node(head->number);
//				if (oddListHead == 0) {
//					oddListHead = temp;
//				}
//				temp->next = 0;
//				if (oddListTail != 0)
//					oddListTail->next = temp;
//				oddListTail = temp;
//			}
//			head = head->next;
//		}
//		if (evenListTail == 0) {
//			return oddListHead;
//		}
//		evenListTail->next = oddListHead;
//		return evenListHead;
//	}
//
//	void showList(){
//		for (Node *temp = head; temp != 0 ; temp = temp->next){
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
//	Node ** results = new Node*[testcases];
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
//		results[i] = linkedList->segregateEvenOdds(linkedList->head);
//	}
//
//	for (int i = 0; i < testcases; i++) {
//		for (Node *temp = results[i]; temp != 0; temp = temp->next){
//			if (temp->next == 0){
//				cout << temp->number << endl;
//			}
//			else {
//				cout << temp->number << " " ;
//			}
//		}
//	}
//
//}