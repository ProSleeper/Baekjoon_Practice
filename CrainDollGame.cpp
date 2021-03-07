#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<vector<int>> stackBoard(board.size(), vector<int>());
    vector<int> basket;

    for(int i = board.size() - 1; i >= 0; i--)		{
        for(int j = 0; j < board.size(); j++){
            if(board[i][j] != 0)	{
                stackBoard[j].push_back(board[i][j]);
            }
        }
    }

    for(int item : moves)		{
        if(stackBoard[item - 1].size() == 0)	{
            continue;
        }
        basket.push_back(stackBoard[item - 1].back());
        stackBoard[item - 1].pop_back();
        if(basket.size() > 1 and (basket[basket.size() - 1] == basket[basket.size() - 2]))	{
            basket.pop_back();
            basket.pop_back();
            answer+=2;
        }
    }
    return answer;
}

int main()
{

    //result 8
    /*vector<vector<int>> inputData{  {0, 0, 0, 0, 0},
                                    {0, 0, 1, 0, 3},
                                    {0, 2, 5, 0, 1},
                                    {4, 2, 4, 4, 2},
                                    {3, 5, 1, 3, 1} };
    vector<int> moveData{ 1, 5, 3, 5, 1, 2, 1, 4 };*/

    vector<vector<int>> inputData{{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};
    vector<int> moveData{ 1, 5, 3, 5, 1, 2, 5, 1, 4, 3 };

    solution(inputData, moveData);

    return 0;
}