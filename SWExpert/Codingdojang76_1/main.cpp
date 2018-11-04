#include <stdio.h>

#define DEBUG    // DEBUG 매크로 정의

int main()
{
#ifdef DEBUG     // DEBUG 매크로가 정의되어 있다면 #ifdef, #endif 사이의 코드를 컴파일
    printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif

    return 0;
}

//printf안에서 사용한 __DATE__, __TIME__, __FILE__, __LINE__는 컴파일러에서 제공하는 매크로이며 디버그 코드를 작성할 때 유용합니다.
//
//__DATE__: 컴파일한 날짜(실행 시점의 현재 날짜가 아님)
//__TIME__: 컴파일한 시간(실행 시점의 현재 시간이 아님)
//__FILE__: __FILE__ 매크로가 사용된 헤더, 소스 파일
//__LINE__: __LINE__ 매크로가 사용된 줄 번호
//#ifdef, #endif가 전처리기 과정을 거치면 코드는 다음과 같이 바뀝니다.