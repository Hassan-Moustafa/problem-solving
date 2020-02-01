//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Pair{
//public:
//	int petrol;
//	int distance;
//	bool visited;
//};
//
//int main() {
//
//	int testCases;
//	cin >> testCases;
//
//	for (int i = 0; i < testCases; i++) {
//
//		int size;
//		cin >> size;
//
//		vector<Pair> v;
//
//		for (int j = 0; j < size; j++) {
//			int petrol, distance;
//			cin >> petrol >> distance;
//			Pair temp;
//			temp.petrol = petrol;
//			temp.distance = distance;
//			temp.visited = false;
//			v.push_back(temp);
//		}
//
//		int i = 0;
//		int positiveCount = 0;
//		int acc = 0;
//		int steps = 0;
//		while (true) {
//
//			Pair temp = v[i];
//			int diff = temp.petrol - temp.distance + acc;
//			if (diff > -1) {
//				positiveCount++;
//				acc = diff;
//				v[i].visited = true;
//				if (positiveCount == size){
//					cout << steps - size + 1 << endl;
//					break;
//				}
//			}
//			else {
//				if (v[i].visited){
//					cout << -1 << endl;
//					break;
//				}
//				else {
//					v[i].visited = true;
//					positiveCount = 0;
//					acc = 0;
//				}
//			}
//
//			i++;
//			if (i == size) {
//				i = 0;
//			}
//			steps++;
//
//		}
//	}
//
//}