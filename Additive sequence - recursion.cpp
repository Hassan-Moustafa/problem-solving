//#include <iostream>
//#include <string>
//using namespace std;
//
//
//bool result = 0;
//
//string findSum(string str1, string str2)
//{
//	// Before proceeding further, make sure length 
//	// of str2 is larger. 
//	if (str1.length() > str2.length())
//		swap(str1, str2);
//
//	// Take an empty string for storing result 
//	string str = "";
//
//	// Calculate length of both string 
//	int n1 = str1.length(), n2 = str2.length();
//
//	// Reverse both of strings 
//	reverse(str1.begin(), str1.end());
//	reverse(str2.begin(), str2.end());
//
//	int carry = 0;
//	for (int i = 0; i<n1; i++)
//	{
//		// Do school mathematics, compute sum of 
//		// current digits and carry 
//		int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
//		str.push_back(sum % 10 + '0');
//
//		// Calculate carry for next step 
//		carry = sum / 10;
//	}
//
//	// Add remaining digits of larger number 
//	for (int i = n1; i<n2; i++)
//	{
//		int sum = ((str2[i] - '0') + carry);
//		str.push_back(sum % 10 + '0');
//		carry = sum / 10;
//	}
//
//	// Add remaining carry 
//	if (carry)
//		str.push_back(carry + '0');
//
//	// reverse resultant string 
//	reverse(str.begin(), str.end());
//
//	return str;
//}
//
//void isAdditiveSequence(string originalString, string firstNum, int currentIndex, string secondNum, bool appendToSecondNum)
//{
//	if (currentIndex < originalString.length()-1) {
//
//		if (appendToSecondNum)
//			secondNum += originalString[currentIndex];
//
//		string resAsString = findSum(firstNum, secondNum);
//		int j = currentIndex+1;
//		bool isMatched = true;
//		if ((originalString.length() - j) >= resAsString.length()) {
//			for (int i = 0; i < resAsString.length(); i++){
//				if (j < originalString.length() && resAsString[i] != originalString[j]) {
//					isMatched = false;
//					isAdditiveSequence(originalString, firstNum, currentIndex + 1, secondNum, true);
//					break;
//				}
//				j++;
//			}
//			if (isMatched) {
//
//				isAdditiveSequence(originalString, secondNum, currentIndex + resAsString.length(), resAsString, false);
//				if (result == 0){
//					isAdditiveSequence(originalString, firstNum, currentIndex + 1, secondNum, true);
//					//isAdditiveSequence(originalString, firstNum, currentIndex + resAsString.length(), resAsString, false);
//
//				}
//			}
//
//		}
//	}
//	else if (currentIndex == originalString.length() - 1 && firstNum.length() < originalString.length()/2) {
//		result = 1;
//	}
//	/*else {
//		if (firstNum.size() <= originalString.length()/2){
//			firstNum += originalString[firstNum.size()];
//			isAdditiveSequence(originalString, firstNum, firstNum.size(), "", true);
//		}
//	}*/
//
//}
//
//string _firstNum = "";
//
//int main() {
//
//
//	int testCases;
//	cin >> testCases;
//	for (int i = 0; i < testCases; i++){
//		string s;
//		cin >> s;
//
//		string start = "";
//		start += s[0];
//		
//		result = 0;
//		while (_firstNum.size() <= s.length() / 2) {
//			_firstNum += s[_firstNum.size()];
//			isAdditiveSequence(s, _firstNum, _firstNum.size(), "", true);
//		}
//		cout << result << endl;
//		_firstNum = "";
//	}
//}