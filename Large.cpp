#include <iostream>

using namespace std;

struct ALarge
{
	int mWeight = 0;
	int mHeight = 0;
	int mAbove = 0;
	int mRank = 1;
};


int main()
{
	int peopleCount = 0;
	ALarge* lPeople = nullptr;
	cin >> peopleCount;

	lPeople = new ALarge[peopleCount];

	for(int i = 0; i < peopleCount; i++)		{
		cin >> lPeople[i].mWeight >> lPeople[i].mHeight;
		lPeople[i].mAbove = peopleCount;
	}

	for(int i = 0; i < peopleCount - 1; i++)		{
		for(int j = i + 1; j < peopleCount; j++){
			if((lPeople[i].mWeight > lPeople[j].mWeight) and (lPeople[i].mHeight > lPeople[j].mHeight)){
				lPeople[i].mAbove--;
			}
			else if((lPeople[i].mWeight < lPeople[j].mWeight) and (lPeople[i].mHeight < lPeople[j].mHeight)){
				lPeople[j].mAbove--;
			}
			else{
				lPeople[i].mAbove--;
				lPeople[j].mAbove--;
			}
		}
	}

	for(int i = 0; i < peopleCount; i++){
		for(int j = 0; j < peopleCount; j++){
			if(lPeople[i].mAbove > lPeople[j].mAbove){
				lPeople[i].mRank++;
			}
		}
	}
	for(int i = 0; i < peopleCount; i++){
		cout << lPeople[i].mRank << " ";
	}


	delete[] lPeople;

	return 0;
}

