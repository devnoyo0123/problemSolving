#include <cstdio>
#include <string>
#include <sstream>



using namespace std;

long long num;


string go(string str, long long num){
    ostringstream ostr;

    if( num < 2){
        ostr<<num;    //ostr에 num 저장
        str += ostr.str(); //ostr을 string으로 바꾸어 val에 저장
        return str;
    }else{
        long long tmp = num % 2;
        ostr<<tmp;    //ostr에 num 저장
        string val = ostr.str(); //ostr을 string으로 바꾸어 val에 저장
        return go(str+val, num/2);
    }

}

int main() {

    scanf("%lld", &num);

    string ret = go("", num);

    for (long long i = ret.size()-1; i >= 0 ; --i) {
        printf("%c",ret[i]);
    }
    printf("\n");
    return 0;
}