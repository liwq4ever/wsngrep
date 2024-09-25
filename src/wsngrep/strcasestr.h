#pragma once
#include <ctype.h>
#include <string.h>

int strncasecmp(const char* s1, const char* s2, size_t n);

char* strcasestr(const char s, const char find);