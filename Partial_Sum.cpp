//#include <iostream>
//#include <vector>
//
//using namespace std;
//
////Baekjoon 1806번 부분합 풀이
//
//int main()
//{
//	uint32_t numberN = 0;
//	uint32_t numberS = 0;
//	vector<uint32_t> numberSequence;
//	uint32_t answerRange = 100000;
//
//	cin >> numberN >> numberS;
//
//	uint32_t inputNumber = 0;
//	for(uint32_t i = 0; i < numberN; i++){
//		cin >> inputNumber;
//		numberSequence.push_back(inputNumber);
//	}
//
//	uint32_t front = 0;
//	uint32_t end = 0;
//	uint32_t sumValue = 0;
//
//	while(true){
//		
//		if(sumValue >= numberS)	{
//			if(answerRange > (end - front))	{
//				answerRange = end - front;
//			}
//			sumValue -= numberSequence[front++];
//			
//		}
//		else{
//			if(end >= numberN)	{
//				break;
//			}
//			sumValue += numberSequence[end++];
//		}
//	}
//
//	if(answerRange == 100000)	{
//		answerRange = 0;
//	}
//
//	cout << answerRange;
//
//	return 0;
//}
//
//
