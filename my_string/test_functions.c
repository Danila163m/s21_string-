#include "my_string.h"
#include <stdio.h>
#include <assert.h>

void test_memchr() {
    char str[] = "hello world";
    void *result = memchr(str, 'w', 11);
    assert(result == (void *)&str[6]);
    printf("Test memchr passed.\n");
}

void test_memcmp() {
    char str1[] = "abc";
    char str2[] = "abd";
    int result = memcmp(str1, str2, 3);
    assert(result < 0);
    printf("Test memcmp passed.\n");
}

void test_memcpy() {
    char src[] = "12345";
    char dest[6];
    memcpy(dest, src, 5);
    dest[5] = '\0';
    assert(strcmp(src, dest) == 0);
    printf("Test memcpy passed.\n");
}

void test_memset() {
    char str[10] = "abcdefghi";
    memset(str, '*', 6);
    str[6] = '\0';
    assert(memcmp(str, "******", 6) == 0);
    printf("Test memset passed.\n");
}

void test_strcat() {
    char dst[20] = "Hello";
    strcat(dst, " World!");
    assert(strcmp(dst, "Hello World!") == 0);
    printf("Test strcat passed.\n");
}

void test_strncat() {
    char dst[20] = "Hi";
    strncat(dst, ", there!", 5);
    dst[8] = '\0';
    assert(strcmp(dst, "Hi, ther") == 0);
    printf("Test strncat passed.\n");
}

void test_strchr() {
    const char *str = "abcdefg";
    const char *result = strchr(str, 'd');
    assert(*result == 'd' && result == &str[3]);
    printf("Test strchr passed.\n");
}

void test_strcmp() {
    assert(strcmp("abc", "abcd") < 0);
    printf("Test strcmp passed.\n");
}

void test_strncmp() {
    assert(strncmp("abcde", "abcdf", 5) < 0);
    printf("Test strncmp passed.\n");
}

void test_strcpy() {
    char dest[10];
    strcpy(dest, "copy this");
    assert(strcmp(dest, "copy this") == 0);
    printf("Test strcpy passed.\n");
}

void test_strncpy() {
    char source[] = "0123456789";
    char target[10]; 
    strncpy(target, source, 5); 
    target[5] = '\0';
    assert(strcmp(target, "01234") == 0); 
    printf("Test strncpy passed.\n"); 
}

void test_strcspn() {
    const char *s1 = "hello world";
    const char *s2 = "xyz";
    size_t result = strcspn(s1, s2);
    assert(result == 11);
    printf("Test strcspn passed.\n");
}

void test_strlen() {
    size_t length = strlen("testing");
    assert(length == 7);
    printf("Test strlen passed.\n");
}

void test_strpbrk() {
    char *res = strpbrk("sample string", "aeiou");
    assert(res == &"sample string"[1]);
    printf("Test strpbrk passed.\n");
}

void test_strrchr() {
    const char *source = "mississippi";
    char ch = 'p';
    const char *target = strrchr(source, ch);
    assert(target == &source[8]);
    printf("Test strrchr passed.\n");
}

void test_strstr() {
    char haystack[] = "Twas brillig, and the slithy toves";
    char needle[] = "slithy";
    char *p = strstr(haystack, needle);
    if (p) {
        assert(p == &haystack[17]);
    }
    printf("Test strstr passed.\n");
}

void test_sprintf() {
    char buffer[100];
    sprintf(buffer, "The number is %d.", 42);
    assert(strcmp(buffer, "The number is 42.") == 0);
    printf("Test sprintf passed.\n");
}

void test_sscanf() {
    int num;
    char str[50];
    int res = sscanf("42 is the answer", "%d is the %s", &num, str);
    char expectedStr[] = "the answer";
    assert(num == 42 && strcmp(str, expectedStr) == 0 && res == 2);
    printf("Test sscanf passed.\n");
}

void run_tests() {
    test_memchr();
    test_memcmp();
    test_memcpy();
    test_memset();
    test_strcat();
    test_strncat();
    test_strchr();
    test_strcmp();
    test_strncmp();
    test_strcpy();
    test_strncpy();
    test_strcspn();
    test_strlen();
    test_strpbrk();
    test_strrchr();
    test_strstr();
    test_sprintf();
    test_sscanf();
}

int main() {
    run_tests();
    return 0;
}