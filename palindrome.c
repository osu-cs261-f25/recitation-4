/*
 * This file contains two different versions of a function to determine whether
 * a user-typed string is a palindeome, i.e. a string like "tacocat" that
 * reads the same both forwards and backwards.  One version of the function
 * is iterative (i.e. it uses a loop).  You must implement the other version
 * to check for a palindrome recursively.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 256

/*
 * This function prompts the user for input and stores a maximum of `n`
 * characters of the string they enter into `dest`.  Any trailing line ending
 * characters are removed from the input string.  Returns 1 if a string was
 * successfully read from the user or 0 otherwise.
 */
int get_user_str(char* dest, int n) {
  printf("\n== Enter a string, and we'll check whether it's a palindrome (ctrl-d to quit):\n");
  if (fgets(dest, MAX_STR_LEN, stdin) != NULL) {
    /*
     * If a string was successfully read from the user, remove any trailing
     * line ending characters.  Here's some documentation on strcspn() to help
     * understand how this works:
     *
     * https://en.cppreference.com/w/c/string/byte/strcspn
     */
    dest[strcspn(dest, "\r\n")] = '\0';
    return 1;
  } else {
    return 0;
  }
}

/*
 * This function iteratively checks whether a string is a palindrome or not.
 * It returns 1 if the given string is a palindrome and 0 if it is not a
 * palindrome.
 */
int iterative_palindrome(char* str) {
  int left = 0;
  int right = strlen(str) - 1;
  while (left < right) {
    if (str[left] != str[right]) {
      return 0;
    }
    left++;
    right--;
  }
  return 1;
}

/*
 * Implement this function so it *recursively* determines whether a string is
 * a palindrome.  In other words, this function should do the same thing as
 * iterative_palindrome() above, but recursively instead of iteratively.
 *
 * Hint: It may be difficult/impossible to implement a recursive function that
 * only uses the one argument `str` given here.  Feel free to implement a
 * separate recursive function with more arguments and to call that function
 * here.
 */
int recursive_palindrome(char* str) {
  return 0;
}

int main(int argc, char const *argv[]) {
  char* in = malloc(MAX_STR_LEN * sizeof(char));

  while (get_user_str(in, MAX_STR_LEN)) {
    printf("--> Is \"%s\" a palindrome?", in);
    printf("\t%d (iterative)", iterative_palindrome(in));
    printf("\t\t%d (recursive)\n", recursive_palindrome(in));
  }

  free(in);
  return 0;
}
