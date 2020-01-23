//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//bool resultsFound = false;
//vector<string> res;
//
//bool findInDict(string word, vector<string> dict) {
//	for (int i = 0; i < dict.size(); i++) {
//		string temp = dict[i];
//		if (word == temp) {
//			return true;
//		}
//	}
//	return false;
//}
//
//void display() {
//	for (int i = 0; i < res.size(); i++) {
//		resultsFound = true;
//		if (i == 0) {
//			cout << "(" << res[i];
//			if (i + 1 == res.size())
//				cout << ")";
//			else
//				cout << " ";
//		}
//		else if (i + 1 == res.size()) {
//			cout << res[i] << ")";
//		}
//		else {
//			cout << res[i] << " ";
//		}
//	}
//}
//
//void findSentences(string word, vector<string> dict) {
//
//	string currentWord = "";
//
//	for (int i = 0; i < word.length(); i++) {
//
//		currentWord += word[i];
//		if (findInDict(currentWord, dict)) {
//			res.push_back(currentWord);
//
//			if (i + 1 < word.length()) {
//				findSentences(word.substr(i + 1, (word.length() - (i + 1))), dict);
//			}
//			else {
//				display();
//			}
//
//			res.pop_back();
//		}
//	}
//}
//
//
//int main()
//{
//	int testCases;
//	cin >> testCases;
//
//	for (int i = 0; i < testCases; i++) {
//
//		int dictSize;
//		cin >> dictSize;
//
//		vector<string> dict;
//
//		for (int j = 0; j < dictSize; j++) {
//			string word;
//			cin >> word;
//			dict.push_back(word);
//		}
//
//		string word;
//		cin >> word;
//		resultsFound = false;
//		findSentences(word, dict);
//		if (!resultsFound) {
//			cout << "Empty";
//		}
//		cout << endl;
//
//	}
//
//	return 0;
//}