#include <iostream>
 
using namespace std;
 
enum { BLANK = 0, N = 1, S = 2 };
 
int K;              //한변의 길이
int map[100][100];  //맵
int Answer;         //정답
 
void Init()
{
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            map[i][j] = BLANK;
}
 
void solve(int cur_y)
{
    for (int i = 0; i < K; i++)
        if (map[i][cur_y] == N) {
            for (int j = i + 1; j < K; j++) {
                if (map[j][cur_y] == S) {
                    Answer++;
                    break;
                }
                else if (map[j][cur_y] == N)
                    break;
            }
        }
}
 
int main()
{
    int T = 10;     //테케
    for (int test_case = 1; test_case <= T; test_case++) {
        Answer = 0;         //정답초기화
        cin >> K;         //K입력받기
        Init();             //초기화
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++)
                cin >> map[i][j];
        for (int j = 0; j < K; j++)
            solve(j);
        cout << "#" << test_case << " " << Answer << endl;    //정답출력
    }
 
    return 0;
}