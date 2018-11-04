#include <stdio.h>	//printf
#include <string.h>	//strpbrk

int main( )
{
    char string[] = "f(x) = a+b-(c*d⁄e)";
    char strSeparate[] = "()=+-*⁄";
    char *strPos = string;

    do
    {
        strPos = strpbrk( strPos, strSeparate );

        if( strPos != 0 )
        {
            printf( "%s\n", strPos );
            ++strPos;
        }
    }
    while( strPos != 0 );

    return 0;
}