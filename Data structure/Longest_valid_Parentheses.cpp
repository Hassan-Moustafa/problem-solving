////#include <iostream>
////
////#include <stack>
////#include <string>
////#include <vector> 
////
////using namespace std;
////
////int main() {
////	//code
////
////	int testCases;
////	cin >> testCases;
////	for (int i = 0; i < testCases; i++){
////		string text = "()(()(()(()()(((((()((()())())(())()()))";
////		// cin >> text;
////
////		int opened = 0;
////		int closed = 0;
////		int record = 0;
////		int maxRecord = 0;
////
////		for (int j = 0; j <text.size(); j++){
////			if (text[j] == '(') {
////				opened++;
////			}
////			else {
////				if (opened > 0){
////					record++;
////					opened--;
////					// closed--;
////				}
////				else {
////					maxRecord = record > maxRecord ? record : maxRecord;
////					record = 0;
////					opened = 0;
////				}
////			}
////		}
////
////		maxRecord = record > maxRecord ? record : maxRecord;
////		cout << maxRecord * 2 << endl;
////	}
////	return 0;
////}
//
//
//
//
//#include <iostream>
//
//#include <stack>
//#include <string>
//#include <vector> 
//
//using namespace std;
//
//int main() {
//	//code
//
//	int testCases;
//	cin >> testCases;
//	for (int i = 0; i < testCases; i++){
//		//string text = "()(()(()(()()(((((()((()())())(())()()))";
//		//string text = "(((())(()()(()))))()(()))";
//		string text = "(((((())))))()()())";
//		//cin >> text;
//		int record = 0;
//		stack<int> res;
//		
//		int k = text.size() - 1;
//		for (int j = 0; j <text.size(); j++){
//			char x = text[j];
//
//			if (text[j] == '('){
//				res.push(j);
//			}
//			else {
//				if (!res.empty()) {
//					int tempRec = j - res.top() + 1;
//					record = tempRec > record ? tempRec : record;
//					res.pop();
//				}
//			}
//		}
//
//		cout << record << endl;
//	}
//	return 0;
//}