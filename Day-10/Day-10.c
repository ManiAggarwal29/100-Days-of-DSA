/*
Read a string and check if it is a palindrome using two-pointer comparison.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int start, end, flag = 1;

    // Input
    scanf("%s", s);

    start = 0;
    end = strlen(s) - 1;

    // Two-pointer comparison
    while (start < end)
    {
        if (s[start] != s[end])
        {
            flag = 0;
            break;
        }
        start++;
        end--;
    }

    // Output
    if (flag == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}
