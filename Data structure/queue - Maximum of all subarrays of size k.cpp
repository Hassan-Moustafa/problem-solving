//#include <iostream>
//#include <deque>
//using namespace std;
//
//int main() {
//
//	long int testCases;
//	cin >> testCases;
//	long int ** res = new long int *[testCases];
//	long int * arr = 0;
//
//	for (long int z = 0; z < testCases; z++){
//
//		long int arrSize;
//		long int windowSize;
//		cin >> arrSize >> windowSize;
//
//		arr = new long int[arrSize];
//		long int * windowsRes = new long int[arrSize];
//
//		for (long int i = 0; i < arrSize; i++) {
//			long int num;
//			cin >> num;
//			arr[i] = num;
//			windowsRes[i] = -1;
//		}
//
//		long int currentWindow = 0;
//		deque<long int> q;
//
//		for (long int i = 0; i < windowSize; i++) {
//			if (q.empty()) {
//				q.push_back(i);
//			}
//			else if (arr[i] < arr[q.back()]) {
//				q.push_back(i);
//			}
//			else {
//				while (!q.empty() && arr[i] >= arr[q.back()]) {
//					q.pop_back();
//				}
//				q.push_back(i);
//			}
//		}
//
//		windowsRes[currentWindow] = arr[q.front()];
//		currentWindow++;
//
//		long int start = 1;
//		long int end = start + (windowSize - 1);
//
//		if (windowSize != arrSize) {
//			while (true) {
//				if (start > q.front()) {
//					q.pop_front();
//				}
//				if (q.empty() || arr[end] < arr[q.back()]) {
//					q.push_back(end);
//				}
//				else {
//					while (!q.empty() && arr[end] >= arr[q.back()]) {
//						q.pop_back();
//					}
//					q.push_back(end);
//				}
//				windowsRes[currentWindow] = arr[q.front()];
//				currentWindow++;
//				start++;
//				end++;
//				if (end == arrSize) break;
//			}
//		}
//		res[z] = windowsRes;
//
//	}
//
//	for (long int i = 0; i < testCases; i++) {
//		
//		long int x = 0;
//
//		while (res[i][x] > 0)
//		{
//			cout << res[i][x] << " ";
//			x++;
//		}
//		cout << endl;
//	}
//	return 0;
//}