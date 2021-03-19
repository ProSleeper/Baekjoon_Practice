//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//int main()
//{
//	int numberN = 0;
//	int numberM = 0;
//	vector<int> numberSequence;
//
//	cin >> numberN >> numberM;
//
//	int inputNumber = 0;
//	for(int i = 0; i < numberN; i++){
//		cin >> inputNumber;
//		numberSequence.push_back(inputNumber);
//	}
//
//	int front = 0;
//	int end = 0;
//	int sumValue = 0;
//	int answerCount = 0;
//
//	while(end < numberN){
//		for(int i = front; i <= end; i++){
//			sumValue += numberSequence[i];
//		}
//
//		if(sumValue < numberM){
//			end++;
//		}
//		else if(sumValue > numberM){
//			front++;
//		}
//		else{
//			answerCount++;
//			end++;
//		}
//		sumValue = 0;
//	}
//
//
//	cout << answerCount;
//
//	return 0;
//}