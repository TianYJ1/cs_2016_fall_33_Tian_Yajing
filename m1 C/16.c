/* strncpy(s, t, n)*/
char *strncpy(char *s, const char *t, unsigned int n)
{
    char    *ptr = 0;
    unsigned int i;

    ptr = s;
    for (i = 0; i < n && (*s++ = *t++); ++i)
        ;
    if (i == n && *--t)
        *s  = '\0';
    return ptr;
}

/* strcat(s, t, n) */
char *strncat(char *s, const char *t, unsigned int n)
{
    char *ptr = 0;
    unsigned int i;

    ptr = s;
    while (*s)
        ++s;
    for (i = 0; i < n && (*s++ = *t++); ++i)
        ;
    if (i == n && *--t)
        *s  = '\0';
    return ptr;
}

/* strncmp(s1, s2, n) */
int strncmp(const char *s1, const char *s2, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n && (*s1++ == *s2++); ++i)
        ;
    if (i == n)
        return 0;
    else
        return (*--s1 - *--s2);
}

#include <stdio.h>
/* §±§в§а§д§Ц§г§д§Ъ§в */
int main()
{
    char s[100];
    char t[]    = "hello world and...";
    char r[]    = "hello";
    printf("%s\n", strncpy(s, t, 11));
    printf("%s\n", strncat(s, t, 11));
    printf("%d\n", strncmp(s, r, 3));
    return 0;
}
