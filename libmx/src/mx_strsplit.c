#include "libmx.h" 

static char *trim_char(const char *str, char c) {
    int i = 0;
    int start = 0;
    int end = mx_strlen(str) - 1;
    char *res = malloc(end - start + 2);
    
    if (!str) return NULL;
    for(; str[start] == c; start++);
    if (start == end + 1)
        return mx_strnew(0);
    for(; str[end] == c; end--);
    for (; start != end + 1; i++, start++)
        res[i] = str[start];
    res[i] = '\0';
    return res;
}

char **mx_strsplit(const char *s, char c) {
    int words = mx_count_words(s, c);
    char **res = malloc((words + 1)*sizeof(char *));
    res[words] = NULL;
    int i = 0;
    int ptr = 0;
    char *word = (char *)s;
    char *tmp = NULL;
    
    if (!s) return NULL;
    while (words--) {
        word = trim_char(word, c);
        tmp = word;
        ptr = mx_get_char_index(word, c);
        res[i]  =  (ptr == -1) ? mx_strdup(word) : mx_strndup(word, ptr);
        i++;
        word += ptr;
        free(tmp);
    }
    return res;
}
