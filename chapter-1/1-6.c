#include <stdio.h>

int main()
{
  int value, test;
  printf("please input a character and press return\n");
  value = getchar();
  test = value != EOF;

  printf("test '!= EOF' is %d\n", test);

  printf("value is: %d\n", value);
  return 0;
}