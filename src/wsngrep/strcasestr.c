/**
FUNCTION
	<<strcasestr>>---case-insensitive character string search
INDEX
	strcasestr
ANSI_SYNOPSIS
	#include <string.h>
	char *strcasestr(const char *<[s]>, const char *<[find]>);
TRAD_SYNOPSIS
	#include <string.h>
	int strcasecmp(<[s]>, <[find]>)
	char *<[s]>;
	char *<[find]>;
DESCRIPTION
	<<strcasestr>> searchs the string <[s]> for
	the first occurrence of the sequence <[find]>.  <<strcasestr>>
	is identical to <<strstr>> except the search is
	case-insensitive.
RETURNS
	A pointer to the first case-insensitive occurrence of the sequence
	<[find]> or <<NULL>> if no match was found.
PORTABILITY
<<strcasestr>> is in the Berkeley Software Distribution.
<<strcasestr>> requires no supporting OS subroutines. It uses
tolower() from elsewhere in this library.
QUICKREF
	strcasestr
*/

/**-
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * The quadratic code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
 /** Linear algorithm Copyright (C) 2008 Eric Blake
  * Permission to use, copy, modify, and distribute the linear portion of
  * software is freely granted, provided that this notice is preserved.
  */

#include "strcasestr.h"


int strncasecmp(const char* s1, const char* s2, size_t n) {
    return _strnicmp(s1, s2, n);
}

char* strcasestr(const char* haystack, const char* needle) {
    if (!*needle) return (char*)haystack;

    // 创建副本
    char* h_lower = strdup(haystack);
    char* n_lower = strdup(needle);

    // 转换为小写
    for (char* p = h_lower; *p; p++) {
        *p = tolower((unsigned char)*p);
    }
    for (char* p = n_lower; *p; p++) {
        *p = tolower((unsigned char)*p);
    }

    // 使用strstr查找
    char* result = strstr(h_lower, n_lower);

    // 清理内存
    free(h_lower);
    free(n_lower);

    return result; // 返回结果（或NULL）
}