//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector <int> v{ 4, 3, 5, 2, 1, 7 };
//
//void sort(int j, int limit){
//	if (j < limit) {
//		if (v[j] > v[j + 1])
//			swap(v[j], v[j + 1]);
//
//		sort(j + 1, limit);
//	}
//}
//
//int main() {
//	for (int i = v.size()-1; i >= 0; i--) {
//		sort(0,i);
//	}
//
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << endl;
//	}
//}