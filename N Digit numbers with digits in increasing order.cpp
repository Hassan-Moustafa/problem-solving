//#include <iostream>
//#include <vector>
//#include <string>
//
//
//
//using namespace std;
//
//bool numberIsValid(string num) {
//	for (int i = 0; i < num.length() - 1; i++) {
//		if (num[i] >= num[i + 1]) {
//			return false;
//		}
//	}
//	return true;
//}
//
//int resetStartNumber(int firstDigit, int length) {
//	int res = 0;
//	int currentDigit = firstDigit;
//	for (int i = 1; i <= length; i++) {
//		res = (res * 10) + currentDigit;
//		currentDigit++;
//	}
//	return res;
//}
//
//int fixNumber(string number) {
//
//	if (number.length() >= 3) {
//		for (int i = number.length() - 3; i >= 0; i--) {
//			char digit = number[i];
//			int ia = digit - '0';
//			string newSubNumber = to_string(resetStartNumber(ia+1, number.length() - i));
//			if (number.length() - i == newSubNumber.length() &&
//				newSubNumber[newSubNumber.length()-1] != '0') {
//
//				for (int j = i, k = 0; j < number.length(); j++, k++) {
//					number[j] = newSubNumber[k];
//				}
//				return (stoi(number, nullptr, 10));
//			}
//
//		}
//	}
//	else {
//		return stoi(number, nullptr, 10);
//	}
//}
//
//bool done = false;
//
//void getNDigitNumbers(long int num, int length) {
//	string numAsString = to_string(num);
//	while (numAsString.length() == length && !done) {
//		if (numberIsValid(numAsString)) {
//			cout << num << " ";
//			num++;
//			numAsString = to_string(num);
//		}
//		else {
//		
//			if (numAsString[numAsString.length() - 1] == '0' && numAsString[numAsString.length() - 2] == '9') {
//				if (numAsString.length() >= 3) {
//					
//
//					int newNumber = fixNumber(numAsString);
//					if (to_string(newNumber).length() == length) {
//						numAsString = to_string(newNumber);
//						num = stoi(numAsString);
//						//getNDigitNumbers(newNumber, length);
//					}
//					else {
//						num = newNumber;
//						numAsString = to_string(num);
//						done = true;
//					};
//				} else {
//					done = true;
//				}
//			}
//			else {
//				char a = numAsString[numAsString.length() - 2];
//				int ia = a - '0';
//				num += ia+1;
//				numAsString = to_string(num);
//				if (numAsString.length() != length) {
//					done = true;
//				}
//			}
//
//		}
//	}
//}
//
//int main() {
//	
//	int testCases;
//	cin >> testCases;
//
//	for (int i = 0; i < testCases; i++) {
//		long int num;
//		int startNumberConverted = 0;
//		
//		cin >> num;
//
//		char* arr = new char[num];
//
//		long int startNumber = 0;
//		for (int j = 1; j <= num; j++) {
//			startNumber = startNumber * 10 + j;
//		}
//
//		getNDigitNumbers(startNumber, num);
//		cout << endl;
//		done = false;
//	}
//}