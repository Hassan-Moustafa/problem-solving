//#include <iostream>
//#include <string>
//using namespace std;
//
//class Pair {
//public:
//	char ch;
//	int count;
//};
//
//int main() {
//
//	int testCases;
//	cin >> testCases;
//
//	int base = 97;
//
//	string ** allRes = new string *[testCases];
//	int * stringsSizes = new int[testCases];
//
//	for (int i = 0; i < testCases; i++) {
//
//		int strSize;
//		cin >> strSize;
//
//		stringsSizes[i] = strSize;
//
//		char * arr = new char[strSize];
//		
//		string * res = new string[strSize];
//
//		Pair * pre = new Pair[strSize];
//
//		int * chCounts = new int[26];
//
//		for (int j = 0; j < 26; j++){
//			chCounts[j] = -1;
//		}
//
//		for (int j = 0; j < strSize; j++) {
//			
//			char t;
//			cin >> t;
//			arr[j] = t;
//		}
//
//		int currentSlot = 0;
//
//		for (int j = 0; j < strSize; j++) {
//			if (j == 0) {
//
//				Pair temp;
//				temp.ch = arr[j];
//				temp.count = 1;
//
//				pre[currentSlot] = temp;
//
//				chCounts[temp.ch - base] = currentSlot;
//				currentSlot++;
//
//				res[j] = temp.ch;
//			}
//			else {
//
//				if (chCounts[arr[j] - base] == -1) {
//					
//					Pair temp;
//					temp.ch = arr[j];
//					temp.count = 1;
//
//					pre[currentSlot] = temp;
//					chCounts[arr[j] - base] = currentSlot;
//
//					currentSlot++;
//
//					bool chFound = false;
//					for (int k = 0; k < currentSlot; k++) {
//						if (pre[k].count == 1){
//							res[j] = pre[k].ch;
//							chFound = true;
//							break;
//						}
//					}
//					if (!chFound) {
//						res[j] = "-1";
//					}
//
//
//				}
//				else {
//					pre[chCounts[arr[j] - base]].count++;
//					bool chFound = false;
//					for (int k = 0; k < currentSlot; k++) {
//						if (pre[k].count == 1){
//							res[j] = pre[k].ch;
//							chFound = true;
//							break;
//						}
//					}
//					if (!chFound) {
//						res[j] = "-1";
//					}
//				}
//
//			}
//		}
//
//		allRes[i] = res;
//
//		/*for (int j = 0; j < strSize; j++) {
//			cout << res[j] << " ";
//		}
//		cout << endl;*/
//
//	}
//
//	for (int i = 0; i < testCases; i++){
//
//		for (int j = 0; j < stringsSizes[i]; j++) {
//			cout << allRes[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//
//	return 0;
//}