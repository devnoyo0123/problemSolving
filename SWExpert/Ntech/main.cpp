#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class AMPM {
public:
    int hour;
    int minute;
    int second;
};

int whichCase(string _start, string _end) {
    int res;

    string stime, etime;
    stime = _start.substr(0, 2);
    etime = _end.substr(0, 2);


    if ("AM" == stime && "AM" == etime) {
        res = 0;
    } else if ("AM" == stime && "PM" == etime) {
        res = 1;
    } else if ("PM" == stime && "AM" == etime) {
        res = 2;
    } else if ("PM" == stime && "PM" == etime) {
        res = 3;
    }
    return res;
}

AMPM change(string &_time) {
    AMPM time;
    if ("AM" == _time.substr(0, 2)) {
        time.hour = atoi(_time.substr(3, 2).c_str());
        time.minute = atoi(_time.substr(6, 2).c_str());
        time.second = atoi(_time.substr(9, 2).c_str());
    } else {
        time.hour = atoi(_time.substr(3, 2).c_str());
        time.minute = atoi(_time.substr(6, 2).c_str());
        time.second = atoi(_time.substr(9, 2).c_str());
    }
    return time;
};

string solution(string _start, string _end) {
    string answer = "";

    int tmp = whichCase(_start, _end);

    AMPM start = change(_start);
    AMPM end = change(_end);
    AMPM ans;
    switch (tmp) {
        case 1:
        case 2:
            end.hour += 12;
            break;
    }
    ans.hour = end.hour - start.hour;
    ans.minute = end.minute - start.minute;
    ans.second = end.second - start.second;
    if( ans.second < 0){
        ans.second += 60;
        ans.minute-=1;
        if( ans.minute < 0){
            ans.minute+=60;
            ans.hour-=1;
        }
    }

    //시간
    if (ans.hour < 10) {
        answer += "0";
        answer += to_string(ans.hour);
    } else {
        answer += to_string(ans.hour);
    }
    answer += ":";

    //분
    if (ans.minute < 10) {
        answer += "0";
        answer += to_string(ans.minute);
    } else {
        answer += to_string(ans.minute);
    }
    answer += ":";
    //분
    if (ans.second < 10) {
        answer += "0";
        answer += to_string(ans.second);
    } else {
        answer += to_string(ans.second);
    }

    return answer;
}

int main() {

    cout << solution("AM 01:00:01", "PM 01:00:00");
    return 0;
}