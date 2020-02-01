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
//	int sumOfLastN_Nodes(int n){
//
//		int arr[1000];
//		int i = 0;
//		for (Node *temp = head; temp != 0; temp = temp->next){
//			if (temp == head){
//				arr[i] = temp->number;
//			}
//			else {
//				arr[i] = temp->number + arr[i - 1];
//			}
//			i++;
//		}
//		i--;
//
//		int secondIndex = i - n;
//		if (secondIndex < 0) {
//			return arr[i];
//		}
//
//		int result = arr[i] - arr[secondIndex];
//		return result;
//
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