//#include <iostream>
//
//using namespace std;
//
//
//class HeapTree
//{
//public:
//	int size;
//	int maxSize;
//	int* arr;
//
//	HeapTree(int maxSize = 0) {
//		size = 0;
//		this->maxSize = maxSize;
//		arr = new int [maxSize];
//	}
//
//	void insertData(int data) {
//		arr[size] = data;
//		size++;
//		if (size > 1) {
//			restoreHeapTree(size - 1);
//		}
//	}
//
//	void restoreHeapTree(int currentIndex) {
//		int parentIndex = getParentIndex(currentIndex);
//		if (currentIndex != 0 && arr[currentIndex] > arr[parentIndex]) {
//			swap(arr[currentIndex], arr[parentIndex]);
//			restoreHeapTree(parentIndex);
//		}
//	}
//
//	void deleteData() {
//		arr[0] = arr[size - 1];
//		size--;
//		restoreHeapTreeWhenDelete(0);
//	}
//
//	void restoreHeapTreeWhenDelete(int currentIndex) {
//
//		int leftChildIndex = getLeftChildIndex(currentIndex);
//		int rightChildIndex = getRightChildIndex(currentIndex);
//
//		if (leftChildIndex <= size - 1 && rightChildIndex <= size - 1) {
//			if (arr[leftChildIndex] > arr[rightChildIndex] && arr[leftChildIndex] > arr[currentIndex]) {
//				swap(arr[leftChildIndex], arr[currentIndex]);
//				restoreHeapTreeWhenDelete(leftChildIndex);
//			}
//			else if(arr[rightChildIndex] > arr[leftChildIndex] && arr[rightChildIndex] > arr[currentIndex]) {
//				swap(arr[rightChildIndex], arr[currentIndex]);
//				restoreHeapTreeWhenDelete(rightChildIndex);
//			}
//		} else if (leftChildIndex <= size - 1) {
//			if (arr[leftChildIndex] > arr[currentIndex]) {
//				swap(arr[leftChildIndex], arr[currentIndex]);
//				restoreHeapTreeWhenDelete(leftChildIndex);
//			}
//		}
//		else if (rightChildIndex <= size - 1) {
//			if (arr[rightChildIndex] > arr[currentIndex]) {
//				swap(arr[rightChildIndex], arr[currentIndex]);
//				restoreHeapTreeWhenDelete(rightChildIndex);
//			}
//		}
//
//
//	}
//
//	int getParentIndex(int index) {
//		return (index - 1) / 2;
//	}
//
//	int getLeftChildIndex(int index) {
//		return (2 * index) + 1;
//	}
//
//	int getRightChildIndex(int index) {
//		return (2 * index) + 2;
//	}
//
//	void displayTree() {
//		for (int i = 0; i < size; i++) {
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//};
//
//int main() {
//
//	HeapTree *tree = new HeapTree(50);
//	tree->insertData(2);
//	tree->insertData(8);
//	tree->insertData(6);
//	tree->insertData(1);
//	tree->insertData(10);
//	tree->insertData(15);
//	tree->insertData(3);
//	tree->insertData(12);
//	tree->insertData(11);
//
//	tree->displayTree();
//
//	tree->deleteData();
//
//	tree->displayTree();
//
//	tree->deleteData();
//
//	tree->displayTree();
//
//}
