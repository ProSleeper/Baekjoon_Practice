#include <iostream>
#include <vector>

using namespace std;

//8 8 건물 갯수, 건물간의 건설순서 규칙 갯수
//10 20 1 5 8 7 1 43 건설 시간
//1 2    건설순서 규칙1
//1 3    건설순서 규칙2
//2 4    건설순서 규칙3
//2 5    건설순서 규칙4
//3 6    건설순서 규칙5
//5 7    건설순서 규칙6
//6 7    건설순서 규칙7
//7 8    건설순서 규칙8
//7        목표 건물

struct Building {
    int     BuildingNumber      = 0;
    int     BuildTime           = 0;
    vector<int*>    RequireCondition;
};

int TargetTotalBuildTime(Building* building, int targetBuilding)
{
    int tempTime = 0;
    for (int* require : building[targetBuilding].RequireCondition) {
        if (tempTime < TargetTotalBuildTime(building, require[0] - 1)) {
            tempTime = TargetTotalBuildTime(building, require[0] - 1);
        }
    }
    //아직 2개이상의 조건은 처리 안함
    return tempTime + building[targetBuilding].BuildTime;
}



int main()
{
    int     testCase            = 0;
    
    int     buildingCount       = 0;
    int     buildingRuleCount   = 0;
    int     targetBuilding      = 0;
    int     answerCount         = 0;
    int*    answer              = nullptr;
    int**   buildRules          = nullptr;
    Building* building          = nullptr;
    
    
    cin >> testCase;
    
    answer  = new int[testCase];
    answerCount = testCase;
    
    while (testCase > 0) {
        
        cin >> buildingCount >> buildingRuleCount;
        building = new Building[buildingCount];
        
        for (int i = 0; i < buildingCount; i++) {
            building[i].BuildingNumber = i + 1;
            cin >> building[i].BuildTime;
        }
        
        buildRules = new int*[buildingRuleCount];
        for (int i = 0; i < buildingRuleCount; i++) {
            buildRules[i] = new int[2];
            cin >> buildRules[i][0] >> buildRules[i][1];
        }
        
        for (int i = 0; i < buildingRuleCount; i++) {
            building[buildRules[i][1] - 1].RequireCondition.push_back(buildRules[i]);
        }
        
        cin >> targetBuilding;
        
        answer[answerCount - testCase] = TargetTotalBuildTime(building, targetBuilding - 1);
        
        delete[] building;
        
        for (int i = 0; i < buildingRuleCount; i++) {
            delete[] buildRules[i];
        }
        delete[] buildRules;
        
        testCase--;
    }
    
    for (int i = 0; i < answerCount; i++) {
        cout << answer[i] << endl;
    }
    
    delete[] answer;
    
    return 0;
}
