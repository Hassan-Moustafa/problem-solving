//#include <iostream>
//#include <stack>
//#include <string>
//
//using namespace std;
//
//class Pair {
//
//public:
//	char c;
//	int index;
//};
//
//
//int main()
//{
//	int testCases;
//	cin >> testCases;
//
//	int * res = new int[testCases];
//
//	for (int i = 0; i < testCases; i++) {
//		string text;
//		cin >> text;
//
//		stack<Pair> s;
//		int * indexes = new int[text.size()];
//
//		int maxLength = 0;
//
//		int length = 0;
//
//		for (int j = 0; j < text.size(); j++) {
//			if (text[j] == '(') {
//				
//				Pair temp;
//				temp.c = '(';
//				temp.index = j;
//				s.push(temp);
//
//			}
//			else if (!s.empty() && s.top().c == '(') {
//				
//				indexes[j] = 1;
//				indexes[s.top().index] = 1;
//				s.pop();
//
//			}
//
//		}
//
//		for (int j = 0; j < text.size(); j++){
//			if (indexes[j] != 1) {
//				
//				maxLength = length > maxLength ? length : maxLength;
//				length = 0;
//			}
//			else {
//				length++;
//			}
//		}
//
//		if (length != 0) {
//			maxLength = length > maxLength ? length : maxLength;
//		}
//
//
//		res[i] = maxLength;
//	}
//
//	for (int i = 0; i < testCases; i++) {
//		cout << res[i] << endl;
//	}
//
//	return 0;
//}
//
