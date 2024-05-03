char carryOver = '0';

int len(char* a)
{
    int cnt = 0;
    while(a[cnt]!='\0')
        cnt++;
    return cnt;
}

int max(int a, int b)
{
    return a>=b ? a : b;
}

int cahrToInt(char a)
{
    return a == '1' ? 1 : 0;
}

char intToChar(int a)
{
    return a == 1 ? '1' : '0';
}

char halfAdder(char a, char b)
{
    int res = charToInt(a) + charToInt(b) + charToInt(carryOver);
    carryOver = res > 1? '1' : '0';
    return intToChar(res % 2); 
}

char* addBinary(char* a, char* b) {
    
    // can I see an example of the input and output
    // Input: a = "11", b = "1"
    // Output: "100"

    // is length of a always bigger or equal than b?
    // no

    // can we convert the number from string to int add and back to string
    // no because the max length is 10^4 which covers 2^(10000) which doesn't fit in even a long int

    int maxLen = max(len(a), len(b));

    char* res = (char*) malloc( (maxLen +1) * sizeof(char));

    int cnt = 1;
    for(int i = maxLen; i >= 0 ; i--)
    {
        char x = (len(a)-cnt) >= 0 ? a[len(a)-cnt] : '0';
        char y = (len(b)-cnt) >= 0 ? b[len(b)-cnt] : '0';
        *(res + maxLen) = halfAdder(x, y);
        cnt++;
    }
    if(carryOver == '1')
    {
        
    }
}