/* 
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 例如，当字符串为We Are Happy.
 * 则经过替换之后的字符串为We%20Are%20Happy。
*/

#include <stdio.h>
#include <string.h>

void replaceSpace(char *str)
{
    int i = 0;
    int length = strlen(str);
    int new_length = length;
    char *p = str + length;    

    while (length--) {
        if (*p == ' ') {
            int temp = new_length - length;
            for (i = 0; i < temp; i++) {
                p[temp - i + 2] =  p[temp - i];
            }
            p[0] = '%';
            p[1] = '2';
            p[2] = '0';
            new_length += 3; 
        }
        p--;
    }
    printf("------------%s----------\n", p);
}

int main() 
{
    char str[] = "We are happy";

    replaceSpace(str);
    printf("replace:%s\n", str);
    
    return 0;
}
