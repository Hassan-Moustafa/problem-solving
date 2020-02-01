//#include<iostream>
//#include "math.h";
//#define MAX 20;
//using namespace std;
//
//
//struct Node
//{
//	int data;
//	Node* right, *down;
//};
//
//Node* constructLinkedMatrix(int **mat, int n)
//{
//	// code here
//	Node ** topNodes = new Node*[n];
//	Node* head = 0;
//	for (int i = 0; i< n; i++){
//		Node* prevRightNode = 0;
//
//		for (int j = 0; j< n; j++){
//			Node* temp = new Node();
//			if (j == 0){
//				topNodes[i] = temp;
//				if (i == 0) head = temp;
//			}
//			temp->data = mat[i][j];
//			if (prevRightNode != 0){
//				prevRightNode->right = temp;
//			}
//			if (i != 0){
//				topNodes[i - 1]->down = temp;
//				topNodes[i - 1] = topNodes[i - 1]->right;
//				if (i == (n - 1)){
//					topNodes[i]->down = 0;
//				}
//
//			}
//			prevRightNode = temp;
//
//		}
//		prevRightNode->right = 0;
//
//	}
//	return head;
//}
//
//int main() {
//
//	int x = 5;
//	int * p = &x;
//	int ** p2 = &p;
//	cout << p << endl;
//	cout << *p << endl;
//	cout << p2 << endl;
//	cout << *p2 << endl;
//
//	/*int testcases;
//	cin >> testcases;
//
//	for (int i = 0; i < testcases; i++){
//		int matrixSize;
//		cin >> matrixSize;
//
//		int** arr = new int* [matrixSize];
//
//		for (int j = 0; j < matrixSize; j++){
//				
//			arr[j] = new int[matrixSize];
//			for (int k = 0; k < matrixSize; k++){
//				int number;
//				cin >> number;
//				arr[j][k] = number;
//			}
//		}
//		constructLinkedMatrix(arr, 3);
//	}
//*/
//
//
//
//}