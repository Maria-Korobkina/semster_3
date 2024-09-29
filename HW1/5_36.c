#include <stdio.h>

void func(char *a)
  {
  int i =0;
  int k = 0;
  while (a[k] != '\0') 
    {
    k++;
    };
  char b[k+1];
  for (i=0;i<((k/2)+1);i++)
    {
    b[i] = a[i*2];
    };
  i = 0;
  for (i=0;i<((k/2)+1);i++)
    {
    b[(k/2) + 1 +i] = a[1 + i*2];
    };
  b[k] = '\0';
  int c = 0;
  for (int c = 0; c <= k; c++) 
    {
        a[c] = b[c];
    };
  };

int main(void)
{
char a[10];
fgets(a, sizeof(a), stdin);
int i = 0;
for (int i = 0; i < 100; i++)
  {
  if (a[i] == '\n')
    {
    a[i] = '\0';
    break;
    };
  };
func(a);
printf("%s\n", a);
return 0;
}
// эта программа выдаёт не то, что нужно, к сожалению, у меня не получалась эта задача 
