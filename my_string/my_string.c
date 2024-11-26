#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Функция memchr ищет первый символ c в первых n байтах строки str.
 */
void *memchr(const void *str, int c, size_t n) {
    const unsigned char *ptr = (unsigned char *)str;
    while (n-- > 0 && *ptr != (unsigned char)c) {
        ptr++;
    }
    return (*ptr == (unsigned char)c) ? (void *)ptr : NULL;
}

/*
 * Функция memcmp сравнивает первые n байт двух строк.
 */
int memcmp(const void *str1, const void *str2, size_t n) {
    const unsigned char *s1 = (const unsigned char *)str1;
    const unsigned char *s2 = (const unsigned char *)str2;
    for (size_t i = 0; i < n; i++) {
        if (s1[i] < s2[i]) {
            return -1;
        } else if (s1[i] > s2[i]) {
            return 1;
        }
    }
    return 0;
}

/*
 * Функция memcpy копирует n байтов из src в dest.
 */
void *memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    while (n--) {
        *d++ = *s++;
    }
    return dest;
}

/*
 * Функция memset заполняет первые n байтов строки символом c.
 */
void *memset(void *str, int c, size_t n) {
    unsigned char *dst = (unsigned char *)str;
    while (n--)
        *dst++ = (unsigned char)c;
    return str;
}

/*
 * Функция strcat добавляет строку src в конец строки dest.
 */
char *strcat(char *dest, const char *src) {
    char *ret = dest;
    while (*dest) {
        dest++;
    }
    while ((*dest++ = *src++)) ;
    return ret;
}

/*
 * Функция strncat добавляет до n символов из строки src в конец строки dest.
 */
char *strncat(char *dest, const char *src, size_t n) {
    char *ret = dest;
    while (*dest) {
        dest++;
    }
    while (*src && n--) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return ret;
}

/*
 * Функция strchr находит первый символ c в строке str.
 */
char *strchr(const char *str, int c) {
    do {
        if (*str == (char)c) {
            return (char *)str;
        }
    } while (*str++);
    return NULL;
}

/*
 * Функция strcmp сравнивает две строки.
 */
int strcmp(const char *str1, const char *str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

/*
 * Функция strncmp сравнивает не более первых n байт двух строк.
 */
int strncmp(const char *str1, const char *str2, size_t n) {
    if (n == 0) {
        return 0;
    }
    do {
        if (*str1 != *str2++) {
            return (*(const unsigned char *)str1 - *(const unsigned char *)(str2 - 1));
        }
        if (*(str1++) == '\0') {
            break;
        }
    } while (--n != 0);
    return 0;
}

/*
 * Функция strcpy копирует строку src в dest.
 */
char *strcpy(char *dest, const char *src) {
    char *tmp = dest;
    while ((*dest++ = *src++) != '\0');
    return tmp;
}

/*
 * Функция strncpy копирует до n символов из src в dest.
 */
char *strncpy(char *dest, const char *src, size_t n) {
    char *temp = dest;
    if (n) {
        while (--n && (*dest++ = *src++)) ;
        *dest = '\0';
    }
    return temp;
}

/*
 * Функция strcspn вычисляет длину начального сегмента str1,
 * который полностью состоит из символов, не входящих в str2.
 */
size_t strcspn(const char *str1, const char *str2) {
    size_t len = 0;
    const char *p1 = str1;
    for (; *p1; p1++) {
        const char *p2 = str2;
        for (; *p2; p2++) {
            if (*p1 == *p2) goto found;
        }
        len++;
    }
found:
    return len;
}

/*
 * Функция strerror возвращает сообщение об ошибке по номеру errnum.
 */
static const char *error_messages[] = {
    "No error",
    "Operation not permitted",
    "No such file or directory",
    "Interrupted system call",
    "I/O error",
    "Connection reset by peer"
};

char *strerror(int errnum) {
    size_t error_count = sizeof(error_messages) / sizeof(error_messages[0]);
    if (errnum < 0 || (size_t)errnum >= error_count) {
        return "Unknown error";
    }
    return (char *)error_messages[errnum];
}

/*
 * Функция strlen вычисляет длину строки str, не считая завершающего нуля.
 */
size_t strlen(const char *str) {
    const char *s;
    for (s = str; *s; ++s) ;
    return s - str;
}

/*
 * Функция strpbrk находит первый символ в строке str1, соответствующий любому символу в str2.
 */
char *strpbrk(const char *str1, const char *str2) {
    while (*str1) {
        if (strchr(str2, *str1))
            return (char *)str1;
        str1++;
    }
    return NULL;
}

/*
 * Функция strrchr находит последнее вхождение символа c в строке str.
 */
char *strrchr(const char *str, int c) {
    char *last = NULL;
    do {
        if (*str == (char)c) last = (char *)str;
    } while (*str++);
    return last;
}

/*
 * Функция strstr находит первое вхождение подстроки needle в строке haystack.
 */
char *strstr(const char *haystack, const char *needle) {
    size_t needle_len = strlen(needle);
    if (!needle_len) return (char *)haystack;
    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && *h == *n) {
            h++;
            n++;
        }
        if (!*n) return (char *)haystack;
        haystack++;
    }
    return NULL;
}

/*
 * Функция strtok разбивает строку str на токены, разделенные delim.
 */
char *strtok(char *str, const char *delim) {
    static char *tok_save;
    char *end;
    if (!str) str = tok_save;

    while (*str && strchr(delim, *str)) str++;
    if (*str == '\0') return NULL;

    end = str + 1;
    while (*end && !strchr(delim, *end)) end++;
    if (*end) {
        *end = '\0';
        tok_save = end + 1;
    }

    return str;
}
