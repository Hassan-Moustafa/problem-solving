//#include<iostream>
//using namespace std;
//
//struct node
//{
//	int data;
//	struct node *next;
//
//};
//
//
//struct node *reverse(struct node *head, int k)
//{
//	// Complete this method
//	int current_k = 1;
//	node *NewHead = 0;
//	node **arr = new node*[300];
//	int currentPrevList = 0;
//	node *finalHead = 0;
//	while (true){
//		if (head == 0)
//		{
//			if (currentPrevList - 1 > 0 && finalHead != 0){
//				arr[currentPrevList - 2]->next = NewHead;
//			}
//			if (finalHead == 0){
//				finalHead = NewHead;
//			}
//			return finalHead;
//		}
//		if (current_k <= k){
//			node *NewNode = new node;
//			NewNode->data = head->data;
//			if (current_k == 1) {
//				arr[currentPrevList] = NewNode;
//				currentPrevList++;
//			}
//			NewNode->next = NewHead;
//			NewHead = NewNode;
//			current_k++;
//			head = head->next;
//		}
//		else {
//			current_k = 1;
//			if (currentPrevList - 1 > 0){
//				arr[currentPrevList - 2]->next = NewHead;
//			}
//			else {
//				finalHead = NewHead;
//			}
//			NewHead = 0;
//		}
//	}
//}
//
//int main(){
//
//	node *head = 0;
//
//	node n2;
//	n2.data = 2;
//	n2.next = 0;
//
//	node n1;
//	n1.data = 1;
//	n1.next = &n2;
//
//	/*node n3;
//	n3.data = 3;
//	n3.next = &n2;
//
//	node n4;
//	n4.data = 4;
//	n4.next = &n3;
//
//	node n5;
//	n5.data = 5;
//	n5.next = &n4;
//
//	node n6;
//	n6.data = 6;
//	n6.next = &n5;*/
//
//	head = &n1;
//	
//	node *nh = reverse(head, 2);
//	/*while (nh != 0){
//		cout << nh->data << endl;
//		nh = nh->next;
//	}*/
//
//}