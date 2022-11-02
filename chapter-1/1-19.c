#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max_line_len);
int length(char line[]);
void reverse(char line[]);

int main(void)
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
  {
    reverse(line);
    printf("%s", line);
  }

  return 0;
}

int get_line(char line[], int max_line_len)
{
  int c, i;

  i = 0;
  while (i < max_line_len - 1 && (c = getchar()) != EOF && c != '\n')
  {
    line[i] = c;
    ++i;
  }

  if (c == '\n')
  {
    line[i] = '\n';
    ++i;
  }

  line[i] = '\0';

  return i;
}

int length(char line[])
{
  int i;

  for (i = 0; line[i] != '\0'; ++i)
    ;

  return i;
}

void reverse(char line[])
{
  int char_to_write = 0;
  int char_to_read = length(line);
  char current_char;

  char_to_read -= 2;
  while (char_to_read > char_to_write)
  {
    current_char = line[char_to_write];
    line[char_to_write] = line[char_to_read];
    line[char_to_read] = current_char;

    ++char_to_write;
    --char_to_read;
  }
}