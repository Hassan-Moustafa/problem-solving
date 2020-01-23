//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//bool canShareCoins = false;
//
//void canShare(int currentCoinIndex, int currentSum, int currentIndex, vector<int> coins, int milaMoney, int gilaMoney, vector<int> choosedCoins) {
//
//	if (currentIndex < coins.size()) {
//		if (currentCoinIndex != currentIndex) {
//			currentSum += coins[currentIndex];
//			choosedCoins.push_back(currentIndex);
//		}
//
//		if (gilaMoney - currentSum > milaMoney + currentSum) {
//
//			canShare(currentCoinIndex, currentSum, currentIndex + 1, coins, milaMoney, gilaMoney, choosedCoins);
//		}
//		else if (gilaMoney - currentSum == milaMoney + currentSum){
//			canShareCoins = true;
//		}
//		else {
//			if (choosedCoins.size() > 0 && choosedCoins.back() < coins.size()) {
//				int oldCoin = coins[choosedCoins.back()];
//				currentSum = currentSum - coins[choosedCoins.back()];
//				currentIndex = choosedCoins.back();
//				choosedCoins.pop_back();
//				if (choosedCoins.size() > 0) {
//					currentSum = currentSum - coins[choosedCoins.back()];
//					//currentIndex = choosedCoins.back();
//					//int oldBack = coins[choosedCoins.back()];
//					choosedCoins.pop_back();
//					/*while (choosedCoins.size() > 0 && coins[choosedCoins.back()] == oldBack) {
//						currentSum = currentSum - coins[choosedCoins.back()];
//						choosedCoins.pop_back();
//					}*/
//				}
//				/*while (currentIndex+1 < coins.size() && coins[currentIndex +1] == oldCoin) {
//					currentIndex++;
//				}*/
//				if(choosedCoins.size() != 0)
//					canShare(currentCoinIndex, currentSum, currentIndex, coins, milaMoney, gilaMoney, choosedCoins);
//			}
//		}
//	}
//	else if (choosedCoins.size() > 1 && choosedCoins.back() < coins.size()) {
//
//		int oldCoin = coins[choosedCoins.back()];
//		currentSum = currentSum - coins[choosedCoins.back()];
//		currentIndex = choosedCoins.back();
//		choosedCoins.pop_back();
//		//currentIndex = choosedCoins.back();
//		if (choosedCoins.size() > 1) {
//			currentSum = currentSum - coins[choosedCoins.back()];
//			currentIndex = choosedCoins.back()+1;
//			choosedCoins.pop_back();
//		}
//
//		/*int oldBack = choosedCoins.back();
//		while (choosedCoins.size() > 1 && coins[choosedCoins.back()] == oldBack) {
//			currentSum = currentSum - coins[choosedCoins.back()];
//			choosedCoins.pop_back();
//		}*/
//		/*hile (currentIndex+1 < coins.size() && coins[currentIndex +1] == oldCoin) {
//			currentIndex++;
//		}*/
//		if (choosedCoins.size() != 0)
//			canShare(currentCoinIndex, currentSum, currentIndex, coins, milaMoney, gilaMoney, choosedCoins);
//	}
//
//}
//
//
//int main() {
//
//	int testCases;
//	cin >> testCases;
//
//
//	for (int i = 0; i < testCases; i++) {
//
//		int GilaNumOfCoins;
//		cin >> GilaNumOfCoins;
//		
//		int MilaMoneyAmount;
//		cin >> MilaMoneyAmount;
//
//		vector<int> GilaCoins;
//		int gilaAmountMoney = 0;
//
//		for (int j = 0; j < GilaNumOfCoins; j++) {
//			int coin;
//			cin >> coin;
//			GilaCoins.push_back(coin);
//			gilaAmountMoney += coin;
//		}
//		sort(GilaCoins.begin(), GilaCoins.end());
//		//GilaCoins.push_back(100000);
//		if (gilaAmountMoney != MilaMoneyAmount) {
//			canShareCoins = false;
//			if ((gilaAmountMoney - MilaMoneyAmount) % 2 == 0) {
//				for (int j = 0; j < GilaCoins.size(); j++) {
//					canShareCoins = false;
//					canShare(j, GilaCoins[j], j, GilaCoins, MilaMoneyAmount, gilaAmountMoney, vector<int> {j});
//					if (canShareCoins) {
//						cout << "1" << endl;
//						break;
//					}
//				}
//			}
//
//			if (!canShareCoins) {
//				cout << "0" << endl;
//			}
//		}
//		else {
//			cout << "1" << endl;
//		}
//	}
//}