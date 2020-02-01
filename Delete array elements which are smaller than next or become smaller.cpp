//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//int main() {
//
//	int testCases;
//	cin >> testCases;
//
//	int ** res = new int *[testCases];
//	int * sizes = new int[testCases];
//
//	for (int i = 0; i < testCases; i++) {
//		
//		int size;
//		int k;
//		cin >> size;
//
//		int * arr = new int[size];
//
//		for (int j = 0; j < size; j++){
//			int num;
//			cin >> num;
//			arr[j] = num;
//		}
//
//		cin >> k;
//		stack<int> s;
//		bool K_is_ended = false;
//
//		for (int j = 0; j < size; j++) {
//			if (s.empty()) {
//				s.push(arr[j]);
//			}
//			else {
//				while (!s.empty() && arr[j] > s.top()) {
//					if (k > 0) {
//						s.pop();
//						k--;
//					}
//					else break;
//				}
//				s.push(arr[j]);
//			}
//		}
//
//		res[i] = new int[s.size()];
//		sizes[i] = s.size();
//
//		int cs = s.size();
//		while (!s.empty()) {
//			res[i][cs - 1] = s.top();
//			cs--;
//			s.pop();
//		}
//	}
//
//	for (int i = 0; i < testCases; i++) {
//		for (int j = 0; j < sizes[i]; j++) {
//			cout << res[i][j] << " ";
//		}
//		cout << endl;
//	}
//}