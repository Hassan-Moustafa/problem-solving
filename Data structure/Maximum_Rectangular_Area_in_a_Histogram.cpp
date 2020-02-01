//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Pair {
//public:
//	long long int level;
//	long long int count;
//	Pair(){
//		level = 0;
//		count = 0;
//	}
//	Pair(long long int level , long long int count){
//		this->level = level;
//		this->count = count;
//	}
//};
//
//class Index {
//public:
//	vector<Pair> supported;
//};
//
//int main() {
//	//code
//
//	long long int testCases;
//	cin >> testCases;
//
//	long long int * results = new long long int[testCases];
//
//	for (long long int i = 0; i < testCases; i++){
//		long int size;
//		cin >> size;
//
//		//cout << size << endl;
//		long long int * arr = new long long int[size];
//		bool isSpecial = true;
//		for (long int j = 0; j < size; j++){
//			long long int num;
//			cin >> num;
//			arr[j] = num;
//			//arr[j] = j + 1;
//			if (j > 0 && (arr[j] - 1) != arr[j - 1]) {
//				isSpecial = false;
//			}
//		}
//
//		/*if (isSpecial) {
//			cout << size % 2 << endl;
//			if (size % 2 == 0) {
//				cout << arr[size / 2] * (size / 2) << endl;
//				return 0;
//			}
//			else {
//				long long int div = size / 2;
//				cout << arr[div] * (div + 1) << endl;
//				return 0;
//			}
//		}*/
//
//		if (isSpecial) {
//
//			long long int divRE = size / 2;
//			if (size % 2 == 0) {
//				results[i] = arr[divRE] * (divRE);
//			}
//			else {
//				results[i] = arr[divRE] * (divRE + 1);
//			}
//		}
//		else {
//
//			unsigned long long int maxArea = 0;
//
//			Pair temp;
//			temp.level = arr[0];
//			temp.count = 1;
//
//			if (temp.count * temp.level > maxArea) {
//				maxArea = temp.count * temp.level;
//			}
//
//			// vector<Index> indexes;
//
//			Index index;
//			index.supported.push_back(temp);
//
//			// indexes.push_back(index);
//
//			for (long long int j = 1; j < size; j++) {
//
//				long long int minLevelGreaterThanMe = 9000000000000000000;
//				long long int minLevelGreaterThanMeIndex = -1;
//			
//				Index tempIndex;
//			
//				for (long long int k = 0; k < index.supported.size(); k++){
//
//					/*Index index;
//					indexes.push_back(index);*/
//
//
//					Pair res = index.supported[k];
//
//					if (arr[j] > res.level){
//
//						Pair temp;
//						temp.level = res.level;
//						temp.count = res.count + 1;
//
//						if (temp.count * temp.level > maxArea) {
//							maxArea = temp.count * temp.level;
//						}
//
//						tempIndex.supported.push_back(temp);
//					}
//					else {
//						if (res.level < minLevelGreaterThanMe){
//							minLevelGreaterThanMeIndex = k;
//							minLevelGreaterThanMe = res.level;
//						}
//					}
//				}
//
//				if (minLevelGreaterThanMeIndex == -1) {
//					Pair temp;
//					temp.level = arr[j];
//					temp.count = 1;
//
//					if (temp.count * temp.level > maxArea) {
//						maxArea = temp.count * temp.level;
//					}
//
//					tempIndex.supported.push_back(temp);
//				}
//				else {
//					Pair temp;
//					temp.level = arr[j];
//					temp.count = index.supported[minLevelGreaterThanMeIndex].count + 1;
//
//					if (temp.count * temp.level > maxArea) {
//						maxArea = temp.count * temp.level;
//					}
//
//					tempIndex.supported.push_back(temp);
//				}
//
//				index = tempIndex;
//			}
//
//			results[i] = maxArea;
//		}
//	}
//	for (long long int i = 0; i < testCases; i++) {
//		cout << results[i] << endl;
//	}
//
//
//
//	return 0;
//}
//
//
