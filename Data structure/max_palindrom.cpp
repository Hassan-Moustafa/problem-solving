//#include <iostream>
//#include <string>
//#include <fstream>
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
//	bool isEmpty(){
//		return head == 0;
//	}
//
//	void addToHead(int number){
//		head = new Node(number, head);
//		if (tail == 0)
//			tail = head;
//		length++;
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
//	int maxPalindrome(Node *head)
//	{
//		//Your code here
//		int * arr = new int[100];
//		int size = 0;
//		while (head != 0){
//			arr[size] = head->number;
//			size++;
//			head = head->next;
//		}
//		int max = 0;
//		int currentIteration = -1;
//		int j = (size - 1);
//		int counter = 0;
//		for (int i = 0; i < size; i++, j--){
//			if (i == 14) {
//				cout << "hello";
//			}
//			if (i > j){
//				max = (counter *2) > max ? (counter *2) : max;
//				currentIteration++;
//				i = currentIteration;
//				j = (size);
//				counter = 0;
//				continue;
//			}
//			if (i == j) {
//				max = (counter * 2 + 1) > max ? (counter * 2 + 1) : max;
//				currentIteration++;
//				i = currentIteration;
//				j = (size);
//				counter = 0;
//				continue;
//			}
//			if (arr[i] == arr[j]){
//				int x = arr[i];
//				int z = arr[j];
//				counter++;
//				//currentIteration++;
//			}
//			else {
//				counter = 0;
//				i = currentIteration;
//			}
//
//
//		}
//
//		return max;
//	}
//};
//
//int main(){
//	SingleLinkedList *list = new SingleLinkedList();
//	/*	ifstream myReadFile;
//	myReadFile.open("test.txt");
//	char output[100];
//	if (myReadFile.is_open()) {
//		while (!myReadFile.eof()) {
//
//
//			myReadFile >> output;
//			cout << output << endl;
//			list->addToTail(stoi(output));
//
//
//		}
//	}
//	myReadFile.close();*/
//
//	list->addToTail(12);
//	list->addToTail(4);
//	list->addToTail(4);
//	list->addToTail(3);
//	list->addToTail(14);
//
//	/*list->addToTail(2);
//	list->addToTail(3);
//	list->addToTail(7);
//	list->addToTail(3);
//	list->addToTail(2);
//	list->addToTail(12);
//	list->addToTail(14);*/
//
//	int result = list->maxPalindrome(list->head);
//}