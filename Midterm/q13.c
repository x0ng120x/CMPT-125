#include <stdio.h>
#include <string.h>

int count_string_occurence(char* sentence, char* str) {
  int count = 0;
  char* location = strstr(sentence, str);

  while (location != NULL) {
    count += 1;
    location = strstr(location + 1, str);
  }
  return count;
}

int main() {
  char* sentence = "this is a very very very long sentence!";
  printf("%d", count_string_occurence(sentence, "This"));
}