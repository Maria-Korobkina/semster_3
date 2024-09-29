#include <stdio.h>
int main(void)
{
char s;
int i = 0;
int k = 0;
int flag = 0;
char a[100];
while ((s = getchar()) != '$')
    {
    if ((s >= '0') && (s <= '9'))
        {
        if (flag)
            {
            k++;
            if (k > 2)
                {
                continue;
                };
            }
        else
            {
            k = 1;    
            };
        }
    else
        {
        k = 0;
        flag = 0;
        };
    if (s == '.')
        {
        flag = 1;
        }
    a[i++] = s;
    };
a[i] = '\0';
printf("%s\n", a);
return 0;
}
