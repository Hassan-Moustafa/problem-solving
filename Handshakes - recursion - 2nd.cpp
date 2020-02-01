//#include<iostream>
//#include <vector>
//using namespace std;
//
//class Pair {
//public:
//	int first;
//	int second;
//};
//
//vector<vector<Pair>> res;
//vector<Pair> possiblePairs;
//vector<Pair> tempPairs;
//
//
//bool canConnect(int firstNum, int secondNum) {
//	if ((secondNum - firstNum - 1) % 2 != 0) {
//		return false;
//	}
//	for (int i = 0; i < possiblePairs.size(); i++) {
//		if (possiblePairs[i].first == firstNum && possiblePairs[i].second == secondNum ||
//			possiblePairs[i].first == secondNum && possiblePairs[i].second == firstNum) {
//			return false;
//		}
//	}
//	return true;
//}
//
//bool canJoin(Pair p, vector<Pair> arr) {
//
//	for (int i = 0; i < arr.size(); i++) {
//		if (p.first == arr[i].first || p.first == arr[i].second || p.second == arr[i].first || p.second == arr[i].second) {
//			return false;
//		}
//		if ((p.first > arr[i].first && p.first < arr[i].second && p.second > arr[i].second) || 
//			(arr[i].first > p.first && arr[i].first < p.second && arr[i].second > p.second)) {
//			return false;
//		}
//	}
//	return true;
//}
//
//
//bool isEqual(vector<Pair> v1 , vector<Pair> v2) {
//	if (v1.size() != v2.size()) {
//		return false;
//	}
//	else {
//		for (int i = 0; i < v1.size(); i++) {
//			bool isFound = false;
//			for (int j = 0; j < v2.size(); j++) {
//				if ((v1[i].first == v2[j].first && v1[i].second == v2[j].second) ||
//					(v1[i].first == v2[j].second && v1[i].second == v2[j].first)) {
//					isFound = true;
//				}
//			}
//
//			if (isFound == false) {
//				return false;
//			}
//		}
//		return true;	
//	}
//}
//
//vector<vector<Pair>> removeDuplicates() {
//
//	vector<vector<Pair>> finalResult;
//	finalResult.push_back(res[0]);
//
//	for (int i = 1; i < res.size(); i++) {
//		
//		int size = finalResult.size();
//		bool isFound = false;
//		for (int j = 0; j < size; j++) {
//			if (isEqual(finalResult[j], res[i])) {
//				isFound = true;
//				break;
//			}
//		}
//
//		if (!isFound) {
//			finalResult.push_back(res[i]);
//		}
//	}
//
//	return finalResult;
//}
//
//
//
//
////void findPossibleWays(int currentIndex, vector<int> firstGroup, vector<int> secondGroup) {
////
////	if (firstGroup.size() >= 0) {
////		for (int i = 0; i < firstGroup.size(); i++) {
////			int nextIndex = (i + 1) == firstGroup.size() ? 0 : i + 1;
////			for (int j = nextIndex; j < firstGroup.size(); j++) {
////
////				int firstNum = firstGroup[i];
////				int secondNum = firstGroup[j];
////
////				if (canConnect(firstNum, secondNum)) {
////					Pair temp;
////					temp.first = firstNum;
////					temp.second = secondNum;
////					res.push_back(temp);
////
////					vector<int> newFirstGroup, newSecondGroup;
////					for (int q = i + 1; q < j; q++) {
////						newFirstGroup.push_back(firstGroup[q]);
////					}
////					for (int q = j + 1; q < firstGroup.size(); q++) {
////						newSecondGroup.push_back(firstGroup[q]);
////					}
////
////					findPossibleWays(0, newFirstGroup, newSecondGroup);
////				}
////
////			}
////		}
////	}
////	if (secondGroup.size() >= 0) {
////		for (int i = 0; i < secondGroup.size(); i++) {
////			int nextIndex = (i + 1) == secondGroup.size() ? 0 : i + 1;
////			for (int j = nextIndex; j < secondGroup.size(); j++) {
////
////				int firstNum = secondGroup[i];
////				int secondNum = secondGroup[j];
////
////				if (canConnect(firstNum, secondNum)) {
////					Pair temp;
////					temp.first = firstNum;
////					temp.second = secondNum;
////					res.push_back(temp);
////
////					vector<int> newFirstGroup, newSecondGroup;
////					for (int q = i + 1; q < j; q++) {
////						newFirstGroup.push_back(secondGroup[q]);
////					}
////					for (int q = j + 1; q < secondGroup.size(); q++) {
////						newSecondGroup.push_back(secondGroup[q]);
////					}
////
////					findPossibleWays(0, newFirstGroup, newSecondGroup);
////				}
////
////			}
////		}
////	}
////
////}
//
//
//void getAllPossiblePairs(int personsNum) {
//	for (int i = 1; i <= personsNum; i++) {
//		for (int j = i + 1; j <= personsNum; j++) {
//			if (canConnect(i, j)) {
//				Pair temp;
//				temp.first = i;
//				temp.second = j;
//				possiblePairs.push_back(temp);
//			}
//		}
//	}
//}
//
//vector<Pair> removePair(Pair p, vector<Pair> arr) {
//	vector<Pair> newPairs;
//
//	for (int i = 0; i < arr.size(); i++) {
//		if (p.first == arr[i].first && p.second == arr[i].second ||
//			p.first == arr[i].second && p.second == arr[i].first) {
//			continue;
//		}
//		else {
//			newPairs.push_back(arr[i]);
//		}
//
//	}
//	return newPairs;
//}
//
//
//void getAllPossibleWays(int currentIndex, int startIndex, int personsNum, vector<Pair> possiblePairsReduced) {
//	if (tempPairs.size() != (personsNum / 2) && startIndex < possiblePairsReduced.size()) {
//
//		if (tempPairs.size() == 0) {
//			tempPairs.push_back(possiblePairs[currentIndex]);
//			getAllPossibleWays(currentIndex, startIndex, personsNum, possiblePairsReduced);
//		}
//		else {
//			if (canJoin(possiblePairsReduced[startIndex], tempPairs)) {
//				tempPairs.push_back(possiblePairsReduced[startIndex]);
//				getAllPossibleWays(currentIndex, startIndex + 1, personsNum, possiblePairsReduced);
//			}
//			else {
//				getAllPossibleWays(currentIndex, startIndex + 1, personsNum, possiblePairsReduced);
//			}
//		}
//	}
//	else {
//
//		bool isFound = false;
//		for (int i = 0; i < res.size(); i++) {
//			if (isEqual(res[i], tempPairs)) {
//				isFound = true;
//				break;
//			}
//		}
//
//		if (isFound) {
//			
//			
//			int tempPairsSize = tempPairs.size();
//			vector<Pair> subTempPairs;
//
//			for (int i = 1; i < tempPairs.size(); i++) {
//				subTempPairs.push_back(tempPairs[i]);
//			}
//
//			vector<Pair> tempPairs2{ tempPairs[0] };
//			int oldResSize = res.size();
//			for (int i = 0; i < subTempPairs.size(); i++) {
//				for (int j = 0; j < subTempPairs.size(); j++) {
//					if (j != i) {
//						possiblePairsReduced = removePair(subTempPairs[j], possiblePairsReduced);
//					}
//					else {
//						if (tempPairs2.size() > 1) {
//							tempPairs2.pop_back();
//						}
//						possiblePairsReduced.insert(possiblePairsReduced.begin(), subTempPairs[j]);
//						tempPairs2.push_back(subTempPairs[j]);
//					}
//				}
//
//				
//				tempPairs = tempPairs2;
//				
//				getAllPossibleWays(currentIndex, 0, personsNum, possiblePairsReduced);
//				if (oldResSize < res.size()) {
//					break;
//				}
//				
//			}
//			tempPairs.clear();
//			tempPairs.push_back(tempPairs2[0]);
//			for (int i = 0; i < subTempPairs.size(); i++) {
//				possiblePairsReduced = removePair(subTempPairs[i], possiblePairsReduced);
//			}
//			if (subTempPairs.size() != 0) {
//				getAllPossibleWays(currentIndex, 0, personsNum, possiblePairsReduced);
//			}
//			
//		}
//		else {
//			if (tempPairs.size() == personsNum / 2) {
//				res.push_back(tempPairs);
//			}
//			else {
//				int oldSize = tempPairs.size();
//				if (tempPairs.size() > 1) {
//
//					int tempPairsSize = tempPairs.size();
//					vector<Pair> subTempPairs;
//
//					for (int i = 1; i < tempPairs.size(); i++) {
//						subTempPairs.push_back(tempPairs[i]);
//					}
//
//					vector<Pair> tempPairs2{ tempPairs[0] };
//					int oldResSize = res.size();
//					for (int i = 0; i < subTempPairs.size(); i++) {
//						for (int j = 0; j < subTempPairs.size(); j++) {
//							if (j != i) {
//								possiblePairsReduced = removePair(subTempPairs[j], possiblePairsReduced);
//							}
//							else {
//								if (tempPairs2.size() > 1) {
//									tempPairs2.pop_back();
//								}
//								possiblePairsReduced.insert(possiblePairsReduced.begin(), subTempPairs[j]);
//								tempPairs2.push_back(subTempPairs[j]);
//							}
//						}
//
//						if (!isEqual(tempPairs, tempPairs2)) {
//							tempPairs = tempPairs2;
//
//							getAllPossibleWays(currentIndex, 0, personsNum, possiblePairsReduced);
//							if (oldResSize == res.size()) {
//								while (tempPairs.size() > 1)
//								{
//									possiblePairsReduced = removePair(tempPairs.back(), possiblePairsReduced);
//									tempPairs.pop_back();
//								}
//								int oldREsSize = res.size();
//								getAllPossibleWays(currentIndex, 0, personsNum, possiblePairsReduced);
//							}
//							else break;
//						}
//						else {
//							while (tempPairs.size() > 1)
//							{
//								possiblePairsReduced = removePair(tempPairs.back(), possiblePairsReduced);
//								tempPairs.pop_back();
//							}
//							int oldREsSize = res.size();
//							getAllPossibleWays(currentIndex, 0, personsNum, possiblePairsReduced);
//						}
//
//					}
//				}
//				
//			}
//			tempPairs.clear();
//		}
//
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
//		vector<int> arr;
//		getAllPossiblePairs(personsNum);
//
//		for (int i = 1; i <= personsNum; i++) {
//			arr.push_back(i);
//		}
//
//		for (int j = 0; j < possiblePairs.size(); j++) {
//			getAllPossibleWays(j,0, personsNum, possiblePairs);
//		}
//
//		cout<< res.size() << endl;
//		
//	}
//}