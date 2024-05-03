#include <stdio.h>
#include <stdlib.h>

int len(char* s)
{
    int cnt = 0;
    while(s[cnt]!='\0')
        cnt++;
    return cnt;
}

int lengthOfLastWord(char* s) {
    // can I see some examples:
    // Input: s = "Hello World"
    // Output: 5
    // Explanation: The last word is "World" with length 5.

    // can there be more than one spaces between the words in the string
    // Input: s = "   fly me   to   the moon  "
    // Output: 4
    // Explanation: The last word is "moon" with length 4.

    int cnt = 0;
    int flag = 0;
    for(int i = 0; i < len(s); i++)
    {
        if(s[i] != ' ')
        {
            if(flag)
            {
                cnt = 1;
                flag = 0;
            }
            else
            {
                cnt++;
            }
        }
        else
        {
            flag = 1;
        }
    }

    return cnt;
    
}

int main()
{
    char s[] = "   fly me   to   the moon  ";
    int result = lengthOfLastWord(s);
    printf("result = %d\n", result);
    return 0;
}