/* FIND_TWO_CHARS
 * Finds two characters in a string. If the characters
 * appear next to each other in argument order, returns 0.
 * If the characters appear next to each other in opposite
 * order from argument order, returns 1. Otherwise,
 * returns 2.
 */
int find_two_chars (char* str, char a, char b) {
    while (*str != '\0') {
        char* cur = str++;
        if (*cur == a && *str == b)
            return 0;
        if (*cur == b && *str == a)
            return 1;
    }
    return 2;
}
