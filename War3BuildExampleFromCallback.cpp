////8 8 건물 갯수, 건물간의 건설순서 규칙 갯수
////10 20 1 5 8 7 1 43 건설 시간
////1 2    건설순서 규칙1
////1 3    건설순서 규칙2
////2 4    건설순서 규칙3
////2 5    건설순서 규칙4
////3 6    건설순서 규칙5
////5 7    건설순서 규칙6
////6 7    건설순서 규칙7
////7 8    건설순서 규칙8
////7        목표 건물
////
////
/////* 21/03/03
////위의 숫자를 입력해서 해당 건물을 지을 수 있는지 조건이 무엇인지 알려주는 코드
////쉽게 설명하자면 워3에서 헌터스 홀과 에이지가 있어야 로어를 지을 수 있는 것을 구현한 코드
////원래는 백준 ACM craft문제 푸는 용도 였는데 어쩌다보니 그냥 게임을 구현하는 게 되어버렸음
////*/
////
////
//#include <iostream>
//#include <functional>
//#include <string>
//#include <map>
//
//
//using namespace std;
//
//typedef function<void(int)> TintCallback;
//
//class Building
//{
//
//public:
//    Building();
//    ~Building();
//
//    void InitBuilding(int buildingNumber, int maxRulesCount, int buildTime, string** isAvailable);
//    void BuildStart();
//    void CallbackRegistration(multimap<string, TintCallback>* callbackMap);
//
//private:
//    void BuildComplete();
//    void RequirementsOpen(int openNumer);
//
//private:
//    int mBuildingNumber = 0;
//    int mBuildTime        = 0;
//    int mAvailableCount = 0;
//    int mMaxRulesCount = 0;
//    string** mIsAvailable = nullptr;
//    multimap<string, TintCallback>* mCallbackMap = nullptr;
//};
//
//Building::Building()
//{
//}
//
//void Building::BuildStart()
//{
//    bool impossible = true;
//
//    for(int i = 0; i < mAvailableCount; i++){
//        if(mIsAvailable[i][2] == "false"){
//            cout << "건물 " + mIsAvailable[i][0] + " 필요.\n";
//            impossible = false;
//        }
//    }
//
//    if(impossible == false){
//        return;
//    }
//
//    cout << "건물 " + to_string(mBuildingNumber) + " 건설 시작~.\n";
//
//    BuildComplete();
//}
//
//void Building::BuildComplete()
//{
//    cout << to_string(mBuildingNumber) + " 번 건설 완료!.\n";
//    //mCallbackMap[]();
//    for(auto itr = mCallbackMap->begin(); itr != mCallbackMap->end(); itr++){
//        if(itr->first == to_string(mBuildingNumber)){
//            //cout << itr->first << endl;
//            itr->second(mBuildingNumber);
//        }
//    }
//}
//
//void Building::RequirementsOpen(int openNumber)  //openNumber로 넘겨지는 건 거의 자기 자신의 번호 일듯
//{
//    for(int i = 0; i < mAvailableCount; i++){
//        if(mIsAvailable[i][0] == to_string(openNumber)){
//            cout << "건물 " + to_string(mBuildingNumber) + "조건 " + mIsAvailable[i][0] + " 해제\n";
//            mIsAvailable[i][2] = "true";
//        }
//    }
//}
//
//void Building::CallbackRegistration(multimap<string, TintCallback>* callbackMap)
//{
//    mCallbackMap = callbackMap;
//    map<string, TintCallback> vt;
//
//    for(int i = 0; i < mAvailableCount; i++){
//        callbackMap->insert({ mIsAvailable[i][0], [&](int number){RequirementsOpen(number);} });
//    }
//}
//
//void Building::InitBuilding(int buildingNumber, int maxRulesCount, int buildTime, string** isAvailable)
//{
//    mBuildingNumber        = buildingNumber;
//    mBuildTime            = buildTime;
//    mMaxRulesCount    = maxRulesCount;
//
//    for(int i = 0; i < mMaxRulesCount; i++){
//        if(mBuildingNumber == stoi(isAvailable[i][1])){
//            mAvailableCount++;
//        }
//    }
//    mIsAvailable = new string * [mAvailableCount];
//
//    int tempAvailableCount = 0;
//    for(int i = 0; i < mMaxRulesCount; i++){
//        if(mBuildingNumber == stoi(isAvailable[i][1])){
//            mIsAvailable[tempAvailableCount] = new string[3];
//            mIsAvailable[tempAvailableCount][0] = isAvailable[i][0];
//            mIsAvailable[tempAvailableCount][1] = isAvailable[i][1];
//            mIsAvailable[tempAvailableCount][2] = "false";
//            tempAvailableCount++;
//        }
//    }
//}
//
//Building::~Building()
//{
//    //동적할당 해제
//    for (int i = 0; i < mAvailableCount; i++) {
//        delete[] mIsAvailable[i];
//    }
//    delete[] mIsAvailable;
//}
//
//int prevMain() //이 부분 int main() 바꿔서 실행하면 됨
//{
//
//    int     buildingCount           = 0;
//    int     buildingRuleCount       = 0;
//    int     targetBuiling           = 0;
//    int     userInput               = 0;
//    int**   buildRule           = nullptr;
//    int*    buildTime           = nullptr;
//    string** rules              = nullptr;
//    Building* building          = nullptr;
//    multimap<string, TintCallback> callbackRequire;
//
//    cout << "input\n";
//
//    cin >> buildingCount;
//    cin >> buildingRuleCount;
//
//    buildTime = new int[buildingCount];
//    buildRule = new int*[buildingRuleCount];
//
//    for(int i = 0; i < buildingCount; i++){
//        cin >> buildTime[i];
//    }
//
//    rules = new string * [buildingRuleCount];
//    for(int i = 0; i < buildingRuleCount; i++){
//        *(buildRule + i) = new int[2];
//        cin >> buildRule[i][0] >> buildRule[i][1];
//        rules[i] = new string[2];
//        rules[i][0] = to_string(buildRule[i][0]);
//        rules[i][1] = to_string(buildRule[i][1]);
//    }
//
//    cin >> targetBuiling;
//
//    building = new Building[buildingCount];
//
//    for(int i = 0; i < buildingCount; i++){
//        building[i].InitBuilding(i + 1, buildingRuleCount, buildTime[i], rules);
//        building[i].CallbackRegistration(&callbackRequire);
//    }
//
//    while(true){
//        cout << "건설 할 건물 번호를 입력하세요: ";
//        cin >> userInput;
//
//        if(userInput > buildingCount or userInput < 0){
//            break;
//        }
//        building[userInput - 1].BuildStart();
//    }
//
//    //동적할당 해제
//    for (int i = 0; i < 2; i++) {
//        delete[] buildRule[i];
//        delete[] rules[i];
//    }
//    delete[] buildRule;
//    delete[] buildTime;
//    delete[] rules;
//    delete[] building;
//
//    return 0;
//}
