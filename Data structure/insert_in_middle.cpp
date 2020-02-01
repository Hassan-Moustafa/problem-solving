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
//	void insertInMiddle(int number){
//
//		Node* temp1 = head;
//		Node* temp2 = head->next == 0 ? 0 : head->next->next;
//		while (temp2 != 0){
//			temp1 = temp1->next;
//			temp2 = temp2->next == 0 ? 0 : temp2->next->next;
//		}
//
//		Node* newNode = new Node(number);
//		newNode->next = temp1->next;
//		temp1->next = newNode;
//
//	}
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
//		linkedList->insertInMiddle(25);
//		linkedList->showList();
//	}
//
//	
//
//}