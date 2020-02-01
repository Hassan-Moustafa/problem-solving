//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//
//vector<vector<int>> res;
//
//int calSum(vector<int> v, vector<int> arr) {
//	int sum = 0; 
//	for (int i = 0; i < v.size(); i++) {
//		sum += arr[v[i]];
//	}
//	return sum;
//}
//
//
//bool findBulk(vector<int> v) {
//
//	for (int i = 0; i < res.size(); i++){
//
//		if (v.front() == res[i].front() && v.back() == res[i].back() && v.size() == res[i].size()) {
//			bool isMatched = true;
//			for (int j = 0; j < v.size(); j++) {
//				if (v[j] != res[i][j]) {
//					isMatched = false;
//					break;
//				}
//			}
//
//			if (isMatched)
//				return true;
//
//		}
//	}
//
//	return false;
//}
//
//void display(vector<int> v, vector<int> arr) {
//	vector<int> temp;
//	for (int i = 0; i < v.size(); i++) {
//		temp.push_back(arr[v[i]]);
//	}
//
//	if (!findBulk(temp)){
//		res.push_back(temp);
//	}
//	
//}
//
//void findArrays(int start,int currentIndex, int currentSum, vector<int> currentBulk, int intendedSum, vector<int> arr ) {
//
//	if (currentBulk.size() != 0 && (currentIndex+ 1) < arr.size()) {
//		if (currentSum + arr[currentIndex + 1] <= intendedSum) {
//			bool sumSatisfied = false;
//			if (currentSum + arr[currentIndex + 1] == intendedSum){
//				sumSatisfied = true;
//			}
//			currentBulk.push_back(currentIndex + 1);
//			if (sumSatisfied) {
//				display(currentBulk, arr);
//			}
//			currentSum += arr[currentIndex + 1];
//			currentIndex++;
//			findArrays(start, currentIndex, currentSum, currentBulk, intendedSum, arr);
//		}
//		else {
//			currentIndex = currentBulk.back();
//			currentBulk.pop_back();
//			currentSum = calSum(currentBulk, arr);
//			findArrays(start, currentIndex, currentSum, currentBulk, intendedSum, arr);
//		}
//
//	}
//}
//
//int main() {
//
//	int testCases;
//	cin >> testCases;
//
//	for (int k = 0; k < testCases; k++) {
//		
//		int arrSize;
//		int intendedSum;
//
//		cin >> arrSize;
//
//		vector<int> v;
//		vector<int> arr;
//
//		for (int i = 0; i < arrSize; i++){
//			int num;
//			cin >> num;
//			arr.push_back(num);
//		}
//		arr.push_back(10000000);
//
//		cin >> intendedSum;
//
//		sort(arr.begin(), arr.end());
//
//		for (int i = 0; i < arr.size(); i++) {
//			v.push_back(i);
//			if (arr[i] == intendedSum) {
//				display(vector<int> {i}, arr);
//			}
//			findArrays(i, i, arr[i], v, intendedSum, arr);
//			v.clear();
//		}
//
//		for (int i = 0; i < res.size(); i++){
//			for (int j = 0; j < res[i].size(); j++){
//				if (j == 0) {
//					cout << "(" <<res[i][j];
//					if (j + 1 < res[i].size()){
//						cout << " ";
//					}
//				}
//				if (j == 0 && j + 1 == res[i].size())
//					cout << ")";
//				if (j != 0 && j + 1 == res[i].size()){
//					cout << res[i][j] << ")";
//				}
//				if (j != 0 && j + 1 != res[i].size())
//					cout << res[i][j] << " ";
//			}
//		}
//
//		if (res.size() == 0) {
//			cout << "Empty";
//		}
//		cout << endl;
//
//		res.clear();
//	}
//
//
//
//}