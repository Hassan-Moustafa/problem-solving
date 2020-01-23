//#include<iostream>
//#include <vector>
//using namespace std;
//
//
//int getCatalanNumber(int C) {
//	if (C == 0 || C == 1)
//		return 1;
//	else {
//		int num = C - 1;
//		int sum = 0;
//		for (int i = 0; i <= num; i++) {
//			sum += getCatalanNumber(i)* getCatalanNumber(num - i);
//		}
//		return sum;
//	}
//}
//
//int main() {
//	
//
//	int testCases;
//	cin >> testCases;
//
//	for (int i = 0; i < testCases; i++) {
//		
//		int personsNum;
//		cin >> personsNum;
//
//		cout << getCatalanNumber(personsNum/2) << endl;
//
//	}
//}