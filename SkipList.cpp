//#include <iostream>
//#include "math.h"
//using namespace std;
//
//class Node{
//public:
//	int number;
//	Node **next;
//	Node **prev;
//	int nextsNumber = 0;
//
//	Node(){
//		next = 0;
//		prev = 0;
//	}
//	Node(int data){
//		number = data;
//		//next = nextNode;
//	}
//};
//
//class ActiveNext{
//public:
//	int nextPointerindex;
//	Node *parentNode;
//
//	ActiveNext(){
//		nextPointerindex = -1;
//		parentNode = 0;
//	}
//
//	ActiveNext(int nextPointerindex, Node *parentNode){
//		this->nextPointerindex = nextPointerindex;
//		this->parentNode = parentNode;
//	}
//};
//
//
//class SkipList{
//public:
//	Node *NEG_INF, *POS_INF;
//	int length;
//	int maxLevel = 6;
//
//	SkipList(){
//		NEG_INF = new Node(-10000);
//		POS_INF = new Node(10000);
//
//		NEG_INF->next = new Node*[maxLevel];
//		POS_INF->prev = new Node*[maxLevel];
//
//		NEG_INF->nextsNumber = maxLevel;
//		POS_INF->nextsNumber = maxLevel;
//		for (int i = 0; i < maxLevel; i++){
//			NEG_INF->next[i] = POS_INF;
//			POS_INF->prev[i] = NEG_INF;
//		}
//		length = 0;
//	}
//
//	void insert(int newNumber, int level){
//		Node *temp = NEG_INF;
//		ActiveNext *activeNexts = new ActiveNext[maxLevel];
//		int currentActiveNext = 0;
//		Node *newNode = new Node(newNumber);
//
//		for (int i = 0; i < maxLevel; i++){
//			if (temp->nextsNumber == maxLevel && temp->next[i]->number < newNumber){
//				
//					temp = temp->next[i];
//					i--;
//			}
//			else if (temp->next[i - maxLevel + temp->nextsNumber]->number < newNumber){
//				temp = temp->next[i - maxLevel + temp->nextsNumber];
//				i--;
//			}
//			else if (i == maxLevel-1){
//				activeNexts[currentActiveNext].parentNode = temp;
//				if (temp->nextsNumber == maxLevel)
//					activeNexts[currentActiveNext].nextPointerindex = i;
//				else
//					activeNexts[currentActiveNext].nextPointerindex = (i - maxLevel + temp->nextsNumber);
//				currentActiveNext++;
//				
//				newNode->nextsNumber = level;
//				newNode->next = new Node*[level];
//				
//				newNode->prev = new Node*[level];
//
//				int iterator = currentActiveNext - 1;
//				for (int k = 0; k < currentActiveNext; k++){
//					cout<< activeNexts[k].parentNode->number<< "   ";
//				}
//				cout <<" " << endl;
//
//				for (int i = level-1; i >= 0; i--){
//
//					int parentNodeHeight = activeNexts[iterator].parentNode->nextsNumber;
//					int oldTargetNodeHeight = activeNexts[iterator].parentNode->next[activeNexts[iterator].nextPointerindex]->nextsNumber;
//					int difference = abs(parentNodeHeight - oldTargetNodeHeight);
//
//
//					Node *t = activeNexts[iterator].parentNode->next[activeNexts[iterator].nextPointerindex];
//					newNode->next[i] = t;
//					activeNexts[iterator].parentNode->next[activeNexts[iterator].nextPointerindex] = newNode;
//
//					if (parentNodeHeight < oldTargetNodeHeight){
//						newNode->next[i]->prev[activeNexts[iterator].nextPointerindex + difference] = newNode;
//						newNode->prev[i] = activeNexts[iterator].parentNode;
//					}
//					else{
//						newNode->next[i]->prev[activeNexts[iterator].nextPointerindex - difference] = newNode;
//						newNode->prev[i] = activeNexts[iterator].parentNode;
//					}
//
//					iterator--;
//				}
//				
//			}
//			else{
//				activeNexts[currentActiveNext].parentNode = temp;
//				if (temp->nextsNumber == maxLevel)
//					activeNexts[currentActiveNext].nextPointerindex = i;
//				else
//					activeNexts[currentActiveNext].nextPointerindex = (i - maxLevel + temp->nextsNumber);
//
//				currentActiveNext++;
//			}
//		}
//
//		//delete[] activeNexts;
//
//		/*for (int i = 0; i < newNode->nextsNumber; i++){
//			cout << newNode->next[i]->number << endl;
//		}*/
//
//		
//
//	}
//
//	void show(){
//
//		Node *temp = NEG_INF;
//		for (int i = 0; i < maxLevel; i++){
//			while (true)
//			{
//				cout << temp->number << "    ";
//				if (temp->next == 0)
//				{
//					cout << "" << endl;
//					break;
//				}
//				if (temp->nextsNumber == maxLevel)
//					temp = temp->next[i];
//				else
//					temp = temp->next[i - maxLevel + temp->nextsNumber];
//			}
//			temp = NEG_INF;
//		}
//	}
//
//	void show2(){
//
//		Node *temp = POS_INF;
//		for (int i = 0; i < maxLevel; i++){
//			while (true)
//			{
//				cout << temp->number << "    ";
//				if (temp->prev == 0)
//				{
//					cout << "" << endl;
//					break;
//				}
//				if (temp->nextsNumber == maxLevel)
//					temp = temp->prev[i];
//				else
//					temp = temp->prev[i - maxLevel + temp->nextsNumber];
//			}
//			temp = POS_INF;
//		}
//	}
//
//	void remove(int number){
//
//		Node *temp = NEG_INF;
//		for (int i = 0; i < maxLevel; i++){
//			
//				if (temp->next == 0)
//				{
//					cout << "" << endl;
//					break;
//				}
//				if (temp->nextsNumber == maxLevel && temp->next[i]->number <= number){
//
//					temp = temp->next[i];
//					i--;
//				}
//				else if (temp->next[i - maxLevel + temp->nextsNumber]->number <= number){
//					temp = temp->next[i - maxLevel + temp->nextsNumber];
//					i--;
//				}
//				else if (temp->number == number){
//					for (int i = 0; i < temp->nextsNumber; i++){
//
//						int prevNodeHeight = temp->prev[i]->nextsNumber;
//						int currentNodeHeight = temp->nextsNumber;
//						int nextNodeHeight = temp->next[i]->nextsNumber;
//
//						int difference1 = abs(prevNodeHeight - currentNodeHeight);
//						int difference2 = abs(nextNodeHeight - currentNodeHeight);
//
//						if (prevNodeHeight < currentNodeHeight){
//							
//							temp->prev[i]->next[i - difference1] = temp->next[i];
//						}
//						else{
//							temp->prev[i]->next[i + difference2] = temp->next[i];
//						}
//
//						if (nextNodeHeight < currentNodeHeight){
//							temp->next[i]->prev[i - difference2] = temp->prev[i];
//						}
//						else {
//							temp->next[i]->prev[i + difference2] = temp->prev[i];
//						}
//
//					}
//					delete temp;
//					break;
//				}
//		}
//
//	}
//	
//};
//
//int main(){
//
//	SkipList *list = new SkipList();
//	list->insert(7, 2);
//	list->insert(35, 3);
//	list->insert(12, 1);
//	list->insert(8, 1);
//	list->insert(10, 3);
//	list->insert(33, 1);
//	list->insert(28, 1);
//	list->insert(31, 2);
//	list->insert(19, 1);
//	list->insert(19, 2);
//	list->insert(19, 3);
//	list->insert(22, 4);
//	list->insert(17, 2);
//	list->insert(5, 1);
//
//	list->show();
//	//list->show2();
//
//	list->remove(17);
//
//	list->show2();
//
//
//
//	/****************************************/
//
//	/*list->insert(19, 1);
//	list->insert(8, 3);
//	list->insert(31, 1);
//	list->insert(10, 2);
//	list->insert(35, 1);
//	list->insert(33, 2);
//	list->insert(17, 3);
//	list->insert(28, 4);
//	list->insert(7, 1);
//	list->insert(12, 1);
//	list->insert(22, 2);
//	list->insert(5, 1);
//
//
//	list->show();
//	list->remove(28);
//	list->show();*/
//
//	return 0;
//
//}