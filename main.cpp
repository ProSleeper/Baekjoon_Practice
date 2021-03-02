#include <iostream>
#include <functional>
#include <string>

using namespace std;

//class Building
//{
//public:
//	Building(int buildTime, int requireCount, int* requireBuilding);
//	~Building();
//
//private:
//	int		mBuildTime			= 0;
//	int		mRequireCount		= 0;
//	int*	mRequireBuilding	= nullptr;
//};
//
//Building::Building(int buildTime, int requireCount, int* requireBuilding)
//	:mBuildTime(buildTime), mRequireCount(requireCount), mRequireBuilding(requireBuilding)
//{
//}
//
//Building::~Building()
//{
//}



/*
1. �ʿ� ����
2. ���� �ð�(���۰� ���� �޼��� ���)



sdfsdf
sdfsdf


*/


class Building
{

public:
	Building();
	~Building();

	void InitBuilding(int buildingNumber, int maxBuildingCount, int buildTime, string** isAvailable);
	void BuildStart();
	void BuildComplete();
	void RequirementsOpen();

private:
	int mBuildingNumber = 0;
	int mBuildTime		= 0;
	int mAvailableCount = 0;
	int mMaxBuildingCount = 0;
	string** mIsAvailable = nullptr;
};

Building::Building()
{
}
void Building::BuildStart()
{
	bool impossible = true;

	for(int i = 0; i < mAvailableCount; i++){
		if(mIsAvailable[i][2] == "false"){
			cout << "�ǹ� " + mIsAvailable[i][0] + " ���� ����� �մϴ�. (�ǹ� " + to_string(mBuildingNumber) + "�� ����)\n";
			impossible = false;
		}
	}

	if(impossible == false){
		return;
	}


	cout << "�ǹ� " + to_string(mBuildingNumber) + " �Ǽ��� �����մϴ�.\n";
}
void Building::BuildComplete()
{

}

void Building::RequirementsOpen()
{
}

void Building::InitBuilding(int buildingNumber, int maxBuildingCount, int buildTime, string** isAvailable)
{
	mBuildingNumber		= buildingNumber;
	mBuildTime			= buildTime;
	mMaxBuildingCount	= maxBuildingCount;
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
tree		<- notR	 
age			<- age + altar
iter		<- tree + altar
altar		<- notR
huntershall	<- tree
lore		<- huntershall + age
protecter	<- huntershall
wind		<- age


war			<- notR
wonder		<- notR
chimera		<- iter
moonWell	<- notR
*/

//8 8 �ǹ� ����, �ǹ����� �Ǽ����� ��Ģ ����
//10 20 1 5 8 7 1 43 �Ǽ� �ð�
//1 2	�Ǽ����� ��Ģ1
//1 3	�Ǽ����� ��Ģ2
//2 4	�Ǽ����� ��Ģ3
//2 5	�Ǽ����� ��Ģ4
//3 6	�Ǽ����� ��Ģ5
//5 7	�Ǽ����� ��Ģ6
//6 7	�Ǽ����� ��Ģ7
//7 8	�Ǽ����� ��Ģ8
//7		��ǥ �ǹ�

int main()
{
	//int	testCase			= 0;

	int	buildingCount		= 0;
	int	buildingRuleCount	= 0;
	int	targetBuiling		= 0;
	int**	buildRule		= nullptr;
	int*	buildTime		= nullptr;


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
	for(int i = 0; i < buildingCount; i++){
		building[i].InitBuilding(i + 1, buildingCount, buildTime[i], rules);
		building[i].BuildStart();
	}

	

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
////Admin Class �� �Ϲ������� �ٸ� �ҽ�����/������Ͽ� ���ǰ� �Ǿ� ���� ���̴�.
//class Admin{
//public:
//    MYFUNC m_userfunc;  // User ������ �ݹ��Լ� ����� ���� ���� ����
//    void* m_userctx;   // User ������ �ݹ��Լ��� ����� ��, static���� �����
//                        // �ݹ��Լ� ���ο��� �������, ����Լ��� ȣ���ϱ� ����
//                        // User Class�� Context�� ����ϱ� ���� ����
//
//    void print(){
//        m_userfunc(10, m_userctx);           // Admin ������, ��ϵ� ������ �ݹ��Լ��� ȣ��
//        cout << "������ �Լ� �κ�" << endl;  // Admin ������ ���ǵ� �Լ� ����
//    }
//    void RegisterUserFunc(void* func, void* ctx){ // User�� �ݹ��Լ��� ����ϱ� ���� �����Ǵ� �Լ�
//        m_userfunc = (MYFUNC)func;                  // User�� �ݹ��Լ��� Admin�� ���
//        m_userctx = ctx;                            // User�� Context�� ����. ������ User �ݹ��Լ� ���ο���
//                                                    // ����Լ�, ������ �����ϱ� �����̴�.
//    }
//};
//
//class User{
//public:
//    Admin m_admin;      // Admin�� ���� �������� ��ü�� ����
//
//    void init(){        // Admin�� User�� �ݹ��Լ��� ����ϱ� ���� �ʱ�ȭ ����
//        m_admin.RegisterUserFunc(callbackfunc, this);
//    }
//
//    void print(){       // static���� ����� �ݹ��Լ����� �ùٸ��� ����Լ� ����� �������� Ȯ���ϱ� ���� �Լ�
//        cout << "����Լ� ���" << endl;
//    }
//
//    static void callbackfunc(int value, void* ctx){    // Admin�� ��ϵ� �ݹ��Լ� ����
//        User* thisObj = (User*)ctx;                    // ����Լ�,������ �����ϱ� ���� Context ����
//        cout << "���� �Լ� :: " << value << endl;       // Admin���� ���� value�� �ùٸ��� ��µǴ��� Ȯ��
//        thisObj->print();                               // ����Լ��� �ùٸ��� ������ �� �ִ��� Ȯ��
//    }
//
//    void test(){        // Admin�� �Լ� print()�� ������� ��,
//                        // ��ϵ� �ݹ��Լ��� �ùٸ��� �۵��ϴ��� Ȯ���ϱ� ���� ����
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