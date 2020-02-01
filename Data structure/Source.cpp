//#include <iostream>
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
//		head = new Node(number,head);
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
//	void deleteFromHead(){
//		if (head != 0){
//			Node *temp = head;
//			if (head == tail){
//				head = tail = 0;
//			}
//			else {
//				head = head->next;
//			}
//			delete temp;
//			length--;
//		}
//	}
//
//	void deleteFromTail(){
//		if (tail != 0){
//			if (head == tail){
//				delete tail;
//				head = tail = 0;
//			}
//			else {
//				Node *temp = head;
//				for (int i = 0; i < length - 2; i++){
//					temp = temp->next;
//				}
//				temp->next = 0;
//				delete tail;
//				tail = temp;
//			}
//			length--;
//		}
//	}
//
//	void deleteNode(int number) {
//		if (length != 0)
//		{
//			if ((head == tail && head->number == number) || head->number == number){
//				deleteFromHead();
//			}
//			else {
//				Node *temp1 = head;
//				Node *temp2 = temp1->next;
//
//				while (temp2 != 0){
//					if (temp2->number == number){
//						if (temp2->next == 0){
//							deleteFromTail();
//						}
//						else{
//							temp1->next = temp2->next;
//							delete temp2;
//						}
//						length--;
//						break;
//					}
//					temp1 = temp1->next;
//					temp2 = temp2->next;
//				}
//			}
//		}
//	}
//
//	Node *reverse(Node *head, int k)
//	{
//		int current_k = 1;
//		Node *NewHead = 0;
//		Node **arr = new Node*[300];
//		int currentPrevList = 0;
//		Node *finalHead = 0;
//		while (true){
//			if (head == 0)
//			{
//				if (currentPrevList - 1 > 0 && finalHead != 0){
//					arr[currentPrevList - 2]->next = NewHead;
//
//				}
//				if (finalHead == 0){
//					finalHead = NewHead;
//				}
//				for (Node *temp = finalHead; temp != 0; temp = temp->next){
//					cout << temp->number << endl;
//				}
//				cout << "---------------------------------------" << endl;
//				return finalHead;
//			}
//			if (current_k <= k){
//				Node *NewNode = new Node();
//				NewNode->number = head->number;
//				if (current_k == 1) {
//					arr[currentPrevList] = NewNode;
//					currentPrevList++;
//				}
//				NewNode->next = NewHead;
//				NewHead = NewNode;
//				current_k++;
//				head = head->next;
//			}
//			else {
//				current_k = 1;
//				if (currentPrevList - 1 > 0){
//					arr[currentPrevList - 2]->next = NewHead;
//				}
//				else {
//					finalHead = NewHead;
//				}
//				NewHead = 0;
//			}
//		}
//		
//	}
//
//	// delete nodes having greater value on right
//	Node *compute(Node *head)
//	{
//		// your code goes here
//		Node *NewHead = 0;
//		while (true){
//			if (head == 0){
//				break;
//			}
//			Node *temp = new Node(head->number);
//			temp->next = NewHead;
//			NewHead = temp;
//			head = head->next;
//		}
//		if (NewHead == 0) return NewHead;
//		Node *NewTemp = NewHead;
//		int max = NewTemp->number;
//		Node *prev = NewTemp;
//		if (NewTemp->next != 0){
//			NewTemp = NewTemp->next;
//		}
//		else {
//			return NewTemp;
//		}
//		while (true){
//			if (NewTemp != 0){
//				if (NewTemp->number >= max){
//					max = NewTemp->number;
//					NewTemp = NewTemp->next;
//					prev = prev->next;
//				}
//				else {
//					prev->next = NewTemp->next;
//					//  delete temp;
//					NewTemp = prev->next;
//				}
//			}
//			else {
//				break;
//			}
//		}
//
//		Node *NewHead2 = 0;
//		while (true){
//			if (NewHead == 0){
//				break;
//			}
//			Node *temp = new Node(NewHead->number);
//			temp->next = NewHead2;
//			NewHead2 = temp;
//			NewHead = NewHead->next;
//		}
//
//		for (Node *temp = NewHead2; temp != 0; temp = temp->next){
//			cout << temp->number << endl;
//		}
//		return NewHead;
//	}
//
//	// Segregate even and odd nodes
//	void segregateEvenOdds(Node *head){
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
//		evenListTail->next = oddListHead;
//		for (Node *temp = evenListHead; temp != 0; temp = temp->next){
//			cout << temp->number << endl;
//		}
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
//class D_Node{
//public:
//	int number;
//	D_Node *next;
//	D_Node *prev;
//
//	D_Node(){
//		next = prev = 0;
//	}
//	D_Node(int data, D_Node *nextNode = 0 , D_Node *prevNode = 0){
//		number = data;
//		next = nextNode;
//		prev = prevNode;
//	}
//};
//
//class DoublyLinkedList{
//public:
//	D_Node *head, *tail;
//	int length;
//
//	DoublyLinkedList(){
//		head = tail = 0;
//		length = 0;
//	}
//
//	bool isEmpty(){
//		return head == 0;
//	}
//
//	void addToHead(int number){
//		D_Node *temp = new D_Node(number, head);
//		head->prev = temp;
//		head = temp;
//		if (tail == 0)
//			tail = head;
//		length++;
//	}
//
//	void addToTail(int number){
//		if (tail != 0)
//		{
//			tail->next = new D_Node(number);
//			tail->next->prev = tail;
//			tail = tail->next;
//		}
//		else {
//			head = tail = new D_Node(number);
//		}
//		length++;
//	}
//
//	void deleteFromHead(){
//		if (head != 0){
//			D_Node *temp = head;
//			if (head == tail){
//				head = tail = 0;
//			}
//			else {
//				head = head->next;
//				head->prev = 0;
//			}
//			delete temp;
//			length--;
//		}
//	}
//
//	void deleteFromTail(){
//		if (tail != 0){
//			if (head == tail){
//				delete tail;
//				head = tail = 0;
//			}
//			else {
//				tail = tail->prev;
//				delete tail->next;
//				tail->next = 0;
//			}
//			length--;
//		}
//	}
//
//	void deleteNode(int number) {
//		if (length != 0)
//		{
//			if ((head == tail && head->number == number) || head->number == number){
//				deleteFromHead();
//			}
//			else {
//				D_Node *temp = head->next;
//
//
//				while (temp != 0){
//					if (temp->number == number){
//						if (temp->next == 0){
//							deleteFromTail();
//						}
//						else{
//							temp->prev->next = temp->next;
//							temp->next->prev = temp->prev;
//							delete temp;
//						}
//						length--;
//						break;
//					}
//					temp = temp->next;
//				}
//			}
//		}
//	}
//
//	void showList(){
//		for (D_Node *temp = head; temp != 0; temp = temp->next){
//			cout << temp->number << endl;
//		}
//		cout << "---------------------------------------" << endl;
//
//
//	};
//
//};
//
//class SingleCircularLinkedList{
//public:
//	Node *tail;
//	int length;
//
//	SingleCircularLinkedList(){
//		tail = 0;
//		length = 0;
//	}
//
//	void addToFront(int number){
//		if (tail == 0){
//			tail = new Node(number);
//			tail->next = tail;
//		}
//		else {
//			tail->next = new Node(number, tail->next);
//		}
//		length++;
//	}
//
//	void addToBack(int number){
//		if (tail == 0){
//			tail = new Node(number);
//			tail->next = tail;
//		}
//		else {
//			tail->next = new Node(number, tail->next);
//			tail = tail->next;
//		}
//		length++;
//	}
//	
//	void showList(){
//		Node *temp = tail->next;
//		for (int i = 0; i <= length; i++){
//			cout << temp->number << endl;
//			temp = temp->next;
//		}
//	}
//
//};
//
//class DoublyCircularLinkedList{
//public:
//	D_Node *tail;
//	int length;
//
//	DoublyCircularLinkedList(){
//		tail = 0;
//		length = 0;
//	}
//
//	void addToFront(int number){
//		if (tail == 0){
//			tail = new D_Node(number);
//			tail->next = tail->prev = tail;
//		}
//		else {
//			tail->next = new D_Node(number, tail->next, tail);
//			tail->next->next->prev = tail->next;
//		}
//		length++;
//	}
//
//	void addToBack(int number){
//		if (tail == 0){
//			tail = new D_Node(number);
//			tail->next = tail->prev = tail;
//		}
//		else {
//			tail->next = new D_Node(number, tail->next, tail);
//			tail->next->next->prev = tail->next;
//			tail = tail->next;
//		}
//		length++;
//	}
//
//	void showList1(){
//		D_Node *temp = tail->next;
//		for (int i = 0; i < length; i++){
//			cout << temp->number << endl;
//			temp = temp->next;
//		}
//		cout << "-------------------------" << endl;
//	}
//	void showList2(){
//		D_Node *temp = tail->prev;
//		cout << temp->number << endl;
//		for (int i = 0; i < length; i++){
//			cout << temp->number << endl;
//			temp = temp->prev;
//		}
//		cout << "-------------------------" << endl;
//	}
//
//};
//int main(){
//
//
//
//		SingleLinkedList *list = new SingleLinkedList();
//
//		list->addToTail(17);
//		list->addToTail(15);
//		list->addToTail(8);
//		list->addToTail(9);
//		list->addToTail(2);
//		list->addToTail(4);
//		list->addToTail(6);
//		//list->addToTail(3);
//		//list->addToTail(8);
//		/*list->addToTail(6);
//		list->addToTail(1);
//		list->addToTail(9);*/
//
//		list->segregateEvenOdds(list->head);
//
//		//list->reverse(list->head, 25);
//		//list->showList();
//
//		/*list->deleteFromHead();
//		list->showList();
//
//		list->deleteFromTail();
//		list->showList();
//
//		list->deleteNode(4);
//		list->showList();*/
//
//	/*DoublyLinkedList *D_List = new DoublyLinkedList();
//
//		D_List->addToTail(1);
//		D_List->addToTail(2);
//		D_List->addToTail(3);
//		D_List->addToTail(4);
//		D_List->addToTail(5);
//		D_List->addToTail(6);
//
//		D_List->showList();
//
//		D_List->deleteFromHead();
//		D_List->showList();
//
//		D_List->deleteFromTail();
//		D_List->showList();
//
//		D_List->deleteNode(4);
//		D_List->showList();*/
//
//	/*SingleCircularLinkedList *S_C_LinkedList = new SingleCircularLinkedList();
//	
//	S_C_LinkedList->addToBack(1);
//	S_C_LinkedList->addToBack(2);
//	S_C_LinkedList->addToBack(3);
//	S_C_LinkedList->addToBack(4);
//	S_C_LinkedList->addToBack(5);
//	S_C_LinkedList->addToBack(6);
//
//	S_C_LinkedList->showList();*/
//
//	/*DoublyCircularLinkedList *D_C_LinkedList = new DoublyCircularLinkedList();
//	D_C_LinkedList->addToBack(1);
//	D_C_LinkedList->addToBack(2);
//	D_C_LinkedList->addToBack(3);
//	D_C_LinkedList->addToBack(4);
//	D_C_LinkedList->addToBack(5);
//	D_C_LinkedList->addToBack(6);
//
//	D_C_LinkedList->showList1();
//	D_C_LinkedList->showList2();*/
//
//}
//
//
//
//
//
//
////struct node *reverse(struct node *head, int k)
////{
////	// Complete this method
////	int current_k = 1;
////	node* NewHead = 0;
////	node** arr = new node*[300];
////	int currentPrevList = 0;
////	node* finalHead = 0;
////	while (true){
////		if (head == 0)
////		{
////			if (currentPrevList - 1 > 0 && finalHead != 0){
////				arr[currentPrevList - 2]->next = NewHead;
////			}
////			if (finalHead == 0){
////				finalHead = NewHead;
////			}
////			return finalHead;
////		}
////		if (current_k <= k){
////			node newTempNode;
////			node* NewNode = &newTempNode;
////			NewNode->data = head->data;
////			if (current_k == 1) {
////				arr[currentPrevList] = NewNode;
////				currentPrevList++;
////			}
////			NewNode->next = NewHead;
////			NewHead = NewNode;
////			current_k++;
////			head = head->next;
////		}
////		else {
////			current_k = 1;
////			if (currentPrevList - 1 > 0){
////				arr[currentPrevList - 2]->next = NewHead;
////			}
////			else {
////				finalHead = NewHead;
////			}
////			NewHead = 0;
////		}
////	}
////}
