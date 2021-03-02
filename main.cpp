#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef std::function<void(int)> TintCallback;

class Building
{

public:
    Building();
    ~Building();

    void InitBuilding(int buildingNumber, int maxBuildingCount, int buildTime, string** isAvailable);
    void BuildStart();
    void BuildComplete();
    void RequirementsOpen(int openNumer);
    void CallbackRegistration(multimap<string, TintCallback>* callbackMap);

private:
    int mBuildingNumber = 0;
    int mBuildTime        = 0;
    int mAvailableCount = 0;
    int mMaxBuildingCount = 0;
    string** mIsAvailable = nullptr;
    multimap<string, TintCallback>* mCallbackMap = nullptr;
};

Building::Building()
{
}
void Building::BuildStart()
{
    bool impossible = true;

    for(int i = 0; i < mAvailableCount; i++){
        if(mIsAvailable[i][2] == "false"){
            cout << "건물 " + mIsAvailable[i][0] + " 먼저 지어야 합니다. (건물 " + to_string(mBuildingNumber) + "의 조건)\n";
            impossible = false;
        }
    }

    if(impossible == false){
        return;
    }

    cout << "건물 " + to_string(mBuildingNumber) + " 건설을 시작합니다.\n";

    BuildComplete();
}
void Building::BuildComplete()
{
    cout << to_string(mBuildingNumber) + " 번 건설 완료!.\n";
    //mCallbackMap[]();
    for(auto itr = mCallbackMap->begin(); itr != mCallbackMap->end(); itr++){
        if(itr->first == to_string(mBuildingNumber)){
            //cout << itr->first << endl;
            itr->second(mBuildingNumber);
        }
    }
}

void Building::RequirementsOpen(int openNumber)  //openNumber로 넘겨지는 건 거의 자기 자신의 번호 일듯
{
    for(int i = 0; i < mAvailableCount; i++){
        if(mIsAvailable[i][0] == to_string(openNumber)){
            cout << "건물 " + to_string(mBuildingNumber) + "조건 " + mIsAvailable[i][0] + " 해제\n";
            mIsAvailable[i][2] = "true";
        }
    }
}

void Building::CallbackRegistration(multimap<string, TintCallback>* callbackMap)
{
    mCallbackMap = callbackMap;
    map<string, TintCallback> vt;

    for(int i = 0; i < mAvailableCount; i++){
        callbackMap->insert({ mIsAvailable[i][0], [&](int number){RequirementsOpen(number);} });
    }
}

//8 8
//10 20 1 5 8 7 1 43
//1 2 false
//1 3 false
//2 4 false
//2 5 false
//3 6 false
//5 7 false
//6 7 false
//7 8 false
//7  
void Building::InitBuilding(int buildingNumber, int maxBuildingCount, int buildTime, string** isAvailable)
{
    mBuildingNumber        = buildingNumber;
    mBuildTime            = buildTime;
    mMaxBuildingCount    = maxBuildingCount;
    for(int i = 0; i < mMaxBuildingCount; i++){
        if(mBuildingNumber == stoi(isAvailable[i][1])){
            mAvailableCount++;
        }
    }
    mIsAvailable = new string * [mAvailableCount];

    int tempAvailableCount = 0;
    for(int i = 0; i < mMaxBuildingCount; i++){
        if(mBuildingNumber == stoi(isAvailable[i][1])){
            mIsAvailable[tempAvailableCount] = new string[3];
            mIsAvailable[tempAvailableCount][0] = isAvailable[i][0];
            mIsAvailable[tempAvailableCount][1] = isAvailable[i][1];
            mIsAvailable[tempAvailableCount][2] = "false";
            tempAvailableCount++;
        }
    }
}

Building::~Building()
{
}

/*
tree        <- notR
age            <- age + altar
iter        <- tree + altar
altar        <- notR
huntershall    <- tree
lore        <- huntershall + age
protecter    <- huntershall
wind        <- age


war            <- notR
wonder        <- notR
chimera        <- iter
moonWell    <- notR
*/

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

//8 8
//10 20 1 5 8 7 1 43
//1 2
//1 3
//2 4
//2 5
//3 6
//5 7
//6 7
//7 8
//7  

int main()
{
    //int    testCase            = 0;

    int    buildingCount        = 0;
    int    buildingRuleCount    = 0;
    int    targetBuiling        = 0;
    int**    buildRule          = nullptr;
    int*    buildTime           = nullptr;
    
    cout << "input: \n";
    
    cin >> buildingCount;
    cin >> buildingRuleCount;
    buildTime = new int[buildingCount];
    buildRule = new int*[buildingRuleCount];

    for(int i = 0; i < buildingCount; i++){
        cin >> buildTime[i];
    }

    string** rules = new string * [buildingRuleCount];
    for(int i = 0; i < buildingRuleCount; i++){
        *(buildRule + i) = new int[2];
        cin >> buildRule[i][0] >> buildRule[i][1];
        rules[i] = new string[2];
        rules[i][0] = to_string(buildRule[i][0]);
        rules[i][1] = to_string(buildRule[i][1]);
    }
    
    cin >> targetBuiling;

    Building* building = new Building[buildingCount];
    multimap<string, TintCallback> callbackRequire;
    for(int i = 0; i < buildingCount; i++){
        building[i].InitBuilding(i + 1, buildingCount, buildTime[i], rules);
        building[i].CallbackRegistration(&callbackRequire);
        building[i].BuildStart();
    }
    building[0].BuildComplete();
    building[1].BuildComplete();
    building[2].BuildComplete();
    building[3].BuildComplete();
    building[4].BuildComplete();
    building[6].BuildStart();
    building[5].BuildComplete();
    building[6].BuildStart();
    building[6].BuildComplete();
    building[7].BuildComplete();

    /*callbackRequire.insert({ "12", [&](int){} });
    callbackRequire.insert({ "13", [&](int){} });*/

    return 0;
}

//=============================================================================================================================


//#include <iostream>
//#include <string>
//
//using namespace std;
//
//typedef void (*MYFUNC) (int value, void* ctx);
//
////Admin Class 는 일반적으로 다른 소스파일/헤더파일에 정의가 되어 있을 것이다.
//class Admin{
//public:
//    MYFUNC m_userfunc;  // User 측에서 콜백함수 등록을 위한 원형 지정
//    void* m_userctx;   // User 측에서 콜백함수를 사용할 때, static으로 선언된
//                        // 콜백함수 내부에서 멤버변수, 멤버함수를 호출하기 위해
//                        // User Class의 Context를 등록하기 위한 변수
//
//    void print(){
//        m_userfunc(10, m_userctx);           // Admin 측에서, 등록된 유저의 콜백함수를 호출
//        cout << "관리자 함수 부분" << endl;  // Admin 측에서 정의된 함수 구문
//    }
//    void RegisterUserFunc(void* func, void* ctx){ // User가 콜백함수를 등록하기 위해 제공되는 함수
//        m_userfunc = (MYFUNC)func;                  // User의 콜백함수를 Admin에 등록
//        m_userctx = ctx;                            // User의 Context를 저장. 이유는 User 콜백함수 내부에서
//                                                    // 멤버함수, 변수에 접근하기 위함이다.
//    }
//};
//
//class User{
//public:
//    Admin m_admin;      // Admin에 의해 제공받은 객체를 선언
//
//    void init(){        // Admin에 User의 콜백함수를 등록하기 위한 초기화 구문
//        m_admin.RegisterUserFunc(callbackfunc, this);
//    }
//
//    void print(){       // static으로 선언된 콜백함수에서 올바르게 멤버함수 사용이 가능한지 확인하기 위한 함수
//        cout << "멤버함수 사용" << endl;
//    }
//
//    static void callbackfunc(int value, void* ctx){    // Admin에 등록될 콜백함수 정의
//        User* thisObj = (User*)ctx;                    // 멤버함수,변수에 접근하기 위한 Context 설정
//        cout << "유저 함수 :: " << value << endl;       // Admin에서 사용된 value가 올바르게 출력되는지 확인
//        thisObj->print();                               // 멤버함수에 올바르게 접근할 수 있는지 확인
//    }
//
//    void test(){        // Admin의 함수 print()를 사용했을 때,
//                        // 등록된 콜백함수가 올바르게 작동하는지 확인하기 위한 구문
//        m_admin.print();
//    }
//};
//
//int main(void){
//    User tmp;
//    tmp.init();
//    tmp.test();
//}



//=============================================================================================================================




//#include <iostream>
//#include <functional>
//#include <map>
//
//using std::cout; using std::cin;
//using std::endl; using std::map;
//using std::function; using std::string;
//
//int addTwoInts(int i, int j) { return i + j; }
//int subtructTwoInts(int i, int j) { return i - j; }
//
//int main() {
//    auto modOfTwoInts1 = [](int i, int j) { return i % j; };
//    auto subtruct = subtructTwoInts;
//
//    map<string, int(*) (int, int)> op_funcs;
//    op_funcs.insert({ "+", addTwoInts });
//    op_funcs.insert({ "%", modOfTwoInts1 });
//    op_funcs.insert({ "-", subtruct });
//
//    string user_input;
//    cout << "\nType one of the following ops\n"
//        "for integers 10 and 3 to be used:\n"
//        "1) + 2) - 3) % \n";
//
//    cin >> user_input;
//    cout << op_funcs[user_input](10, 3);
//
//    return EXIT_SUCCESS;
//}


//=============================================================================================================================

//#include <functional>
//#include <iostream>
//
//
//class Test
//{
//public:
//    void blah() { std::cout << "BLAH!" << std::endl; }
//};
//
//class Bim
//{
//public:
//    void operator()(){ std::cout << "BIM!" << std::endl; }
//};
//
//void boum() { std::cout << "BOUM!" << std::endl; }
//
//
//int main()
//{
//    // store the member function of an object:
//    Test test;
//    std::function< void() > callback = std::bind(&Test::blah, test);
//    callback();
//
//    // store a callable object (by copy)
//    callback = Bim{};
//    callback();
//
//    // store the address of a static function
//    callback = &boum;
//    callback();
//
//    // store a copy of a lambda (that is a callable object)
//    callback = [&]{ test.blah(); }; // often clearer -and not more expensive- than std::bind()
//    callback();
//}


//=============================================================================================================================


//
//#include <functional>
//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//class Test
//{
//public:
//    Test(int testType) : m_testType(testType) {};
//    void blah() { std::cout << "BLAH! " << m_testType << std::endl; }
//    void blahWithParmeter(string msg) { std::cout << msg << std::endl; }
//    void blahWithParmeter2(string msg) { std::cout << msg << std::endl; }
//
//private:
//    int m_testType;
//};
//class Test2
//{
//public:
//    Test2(int testType) : m_testType(testType) {};
//    void blah() { std::cout << "BLAH! " << m_testType << std::endl; }
//    void blahWithParmeter() { std::cout << "bowwooooooooooooow" << std::endl; }
//    void blahWithParmeter2() { std::cout << "meoooooooooooooooow" << std::endl; }
//
//private:
//    int m_testType;
//};
//
//int main()
//{
//    // store the member function of an object:
//    Test test(1);
//    Test2 test2(2);
//
//    // example of callback with parameter using a vector
//    typedef std::function<void(std::string&)> TstringCallback;
//    typedef std::function<void(std::string&)> TvoidCallback;
//    typedef std::function<void()> TvoidCallback2;
//
//    /*std::vector <TstringCallback> callbackListStringParms;
//    callbackListStringParms.push_back([&](const std::string& tag) { test.blahWithParmeter(tag); });
//    callbackListStringParms.push_back([&](const std::string& tag) { test.blahWithParmeter2(tag); });*/
//
//    map<string, TvoidCallback> callbackMap;
//    map<string, TvoidCallback2> callbackMap2;
//    callbackMap.insert({ "bowwow", [&](const string msg) { test.blahWithParmeter(msg); } });
//    callbackMap.insert({ "meow", [&](const string msg) { test.blahWithParmeter(msg); } });
//    callbackMap.insert({ "peep", [&](const string msg) { test.blahWithParmeter(msg); } });
//    callbackMap.insert({ "roar", [&](const string msg) { test.blahWithParmeter(msg); } });
//
//    callbackMap2.insert({ "bowwow", bind(&Test2::blahWithParmeter, test2) });
//    callbackMap2.insert({ "meow", [&]() { test2.blahWithParmeter2(); } });
//
//
//    callbackMap2["bowwow"]();
//    callbackMap2["meow"]();



    /*std::string parm1 = "p"roar", arm1";
    std::string parm2 = "parm2";
    int i = 0;
    for(auto cb : callbackListStringParms){
        ++i;
        if(i == 1)
            cb(parm1);
        else
            cb(parm2);
    }
}*/
