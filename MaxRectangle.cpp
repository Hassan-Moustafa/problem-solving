//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define MAX 100
//
//using namespace std;
//
//int maxArea_ = 0;
//
//class Pair{
//public:
//	int startIndex;
//	int endIndex;
//	int area;
//	Pair() {
//		startIndex = endIndex = area = -1;
//	}
//};
//
//vector<Pair> getRowPairs(int rowIndex, int m, int M[MAX][MAX]) {
//
//	vector<Pair> currentPairs;
//	bool newArea = false;
//
//	Pair temp;
//	for (int i = 0; i < m; i++)
//	{
//
//		if (M[rowIndex][i] == 0 && newArea == false) {
//			if (i - 1 >= 0 && M[rowIndex][i - 1] == 1){
//				temp.endIndex = i - 1;
//				temp.area = temp.endIndex - temp.startIndex + 1;
//
//				maxArea_ = temp.area > maxArea_ ? temp.area : maxArea_;
//
//				currentPairs.push_back(temp);
//
//				temp.startIndex = -1;
//				temp.endIndex = -1;
//			}
//			newArea = true;
//		}
//		else if (M[rowIndex][i] == 1) {
//
//			temp.startIndex = temp.startIndex != -1 ? temp.startIndex : i;
//			newArea = false;
//		}
//	}
//
//	if (temp.startIndex != -1 && temp.endIndex == -1) {
//		temp.endIndex = m - 1;
//		temp.area = temp.endIndex - temp.startIndex + 1;
//		maxArea_ = temp.area > maxArea_ ? temp.area : maxArea_;
//		currentPairs.push_back(temp);
//	}
//
//	return currentPairs;
//}
//
//Pair getSingleIntersection(Pair prev, Pair next) {
//	Pair res;
//
//	res.startIndex = -1;
//	res.endIndex = -1;
//	res.area = -1;
//
//	if (prev.endIndex < next.startIndex || next.endIndex < prev.startIndex) {
//		return res;
//	}
//	else {
//
//		res.startIndex = max(prev.startIndex, next.startIndex);
//		res.endIndex = min(prev.endIndex, next.endIndex);
//
//		res.area = ((res.endIndex - res.startIndex + 1) * (prev.area / (prev.endIndex - prev.startIndex + 1))) + (res.endIndex - res.startIndex + 1);
//		maxArea_ = res.area > maxArea_ ? res.area : maxArea_;
//	}
//
//	return res;
//}
//
//vector<Pair> getPairsIntersection(vector<Pair> prev, vector<Pair> next) {
//
//	vector<Pair> interSections;
//	for (int i = 0; i < next.size(); i++) {
//
//		for (int j = 0; j < prev.size(); j++) {
//
//			Pair temp = getSingleIntersection(prev[j], next[i]);
//			if (temp.area != -1) {
//				interSections.push_back(temp);
//			}
//		}
//	}
//
//	return interSections;
//}
//
//int maxArea(int M[MAX][MAX], int n, int m)
//{
//	vector<Pair> prevPairs = getRowPairs(0, m, M);
//
//	for (int i = 1; i < n; i++)
//	{
//		vector<Pair> currentPairs = getRowPairs(i, m, M);
//		vector<Pair> interSections = getPairsIntersection(prevPairs, currentPairs);
//
//		for (int j = 0; j < interSections.size(); j++) {
//			currentPairs.push_back(interSections[j]);
//		}
//
//		prevPairs = currentPairs;
//
//	}
//
//	return maxArea_;
//
//}
//
//
//int main() {
//	int testCases;
//	cin >> testCases;
//	int Mat[MAX][MAX];
//	for (int i = 0; i < testCases; i++)
//	{
//		int n, m;
//		cin >> n;
//		cin >> m;
//		for (int q = 0; q<n; q++)
//		{
//			for (int j = 0; j<m; j++)
//			{
//				cin >> Mat[q][j];
//			}
//		}
//		cout << maxArea(Mat, n, m) << endl;
//		maxArea_ = 0;
//	}
//}
