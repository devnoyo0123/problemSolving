#include <iostream>
#include <vector>
#include <string>

using namespace std;

string number[]={"빵","일","이","삼","사","오","육","칠","팔","구"};
string arr[6];

string solution(int num){
    string answer= "";

    int inx = -1;
    int temp = num;

    while(temp > 0){
        inx+=1;
       int val = temp % 10;
       temp/=10;

       if(val == 0){

           continue;
       }


       arr[inx] += number[val];


       switch(inx){
           case 1:

               if(val == 1){
                   arr[inx] = "";
               }
               arr[inx] +="십";
               break;
           case 2:
               if(val == 1){
                   arr[inx] = "";
               }
               arr[inx] +="백";
               break;
           case 3:
               if(val == 1){
                   arr[inx] = "";
               }
               arr[inx] +="천";
               break;
           case 4:
               if(val == 1){
                   arr[inx] = "";
               }
               arr[inx] +="만";
               break;
       }
    }

    for(int i = inx; i>=0; i--){
        answer+=arr[i];
    }


    return answer;
}

int main() {

    int num;
    cin >> num;

    string res = solution(num);
    cout<<res<<'\n';

    return 0;
}