#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle) {

    // can I see an example input and output
    // haystack = "sadbutsad", needle = "sad"
    // Output: 0

    // what is the maximum size of the hapystach and needle


    // one point if the needle size is bigger than haystack what do I do?
    if(strlen(needle)> strlen(haystack))
        return -1;

    // what if the needle is an empty string? size of haystack equals zero is handled above
    if(strlen(needle) == 0)
        return -1;

    int indx = -1;
    for( int i = 0; i < strlen(haystack); i++)
    {
        if(haystack[i] == needle[0])
        {
            indx = i;
            int j;
            for(j = 1; j<strlen(needle); j++)
            {
                if (haystack[i+j] != needle[j])
                {
                    indx =-1;
                    break;
                }
            }

            if(j==strlen(needle))
            {
                return indx;
            }
        }
    }

    return indx;
    
}

int main()
{
    char haystack[] = "sadas";
    char needle[] = "";
    int result = strStr(haystack, needle);
    printf("result = %d\n", result);
    return 0;
}