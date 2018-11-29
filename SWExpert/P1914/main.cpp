#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;

int N;



string bigNumAdd(string num1, string num2)

{

    long long sum = 0;

    string result;



    //1의 자리부터 더하기 시작한다

    while (!num1.empty() || !num2.empty() || sum)

    {

        if (!num1.empty())

        {

            sum += num1.back() - '0';

            num1.pop_back();

        }

        if (!num2.empty())

        {

            sum += num2.back() - '0';

            num2.pop_back();

        }

        //다시 string 형태로 만들어 push_back

        result.push_back((sum % 10) + '0');

        sum /= 10;

    }

    //1의 자리부터 result에 넣었으므로 뒤집어줘야한다

    reverse(result.begin(), result.end());

    return result;

}



//2의 n승은 0으로 끝날 수 없으므로

string subtractOne(string num)

{

    vector<int> v;

    int back = num.back() - '0';

    num.pop_back();

    back -= 1;

    num.push_back(back + '0');



    return num;

}


//from 에서 to로 thru기둥을 이용해서 from 탑에 있는 num개의 원판을 이동시킬것이다.
void hanoi(int from, int to, int thru, int num) {

    if (num == 1) {

        cout<<from<<" "<<to<<"\n";

        return;
    } else {

        //from 에서 thru로 num-1개의 원판을 to로 옮긴다.
        hanoi(from, thru, to, num - 1);

        //from 에서 to로 n-1개의 원판을 옮긴다.
        hanoi(from, to, thru, 1);

        //thru에서 to로 n-1개의 원판을 옮긴다.
        hanoi(thru, to, from, num - 1);

    }


}

int main() {

    cin >> N;

    string num = "2";

    for (int i = 0; i < N - 1; i++)

    {

        string temp = bigNumAdd(num, num);

        num = temp;

    }

    cout << subtractOne(num) << "\n";

    if(N<=20)
        hanoi(1, 3, 2, N);




    return 0;
}