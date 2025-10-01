/* inih -- simple .INI file parser
   SPDX-License-Identifier: BSD-3-Clause
   Copyright (C) 2009-2020, Ben Hoyt
   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Ben Hoyt nor the names of its contributors
      may be used to endorse or promote products derived from this
      software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __INI_H__
#define __INI_H__

/* Make this header file easier to include in C++ code */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

/* Non-zero if ini_handler callback should accept null values for value. */
#ifndef INI_ALLOW_NULL_VALUES
#define INI_ALLOW_NULL_VALUES 0
#endif

/* Non-zero if ini_handler callback should accept inline comments
   (for example, key=value ; comment). Set to 0 to turn off inline comments. */
#ifndef INI_ALLOW_INLINE_COMMENTS
#define INI_ALLOW_INLINE_COMMENTS 1
#endif

/* Non-zero if INI_ALLOW_INLINE_COMMENTS is enabled, and spaces are allowed
   between equals sign and value. Set to 0 to disallow. */
#ifndef INI_ALLOW_SPACES_AFTER_EQUALS
#define INI_ALLOW_SPACES_AFTER_EQUALS 1
#endif

/* Non-zero if inih should allow lines with no section. This is implemented by
   calling the handler with a null section name. */
#ifndef INI_ALLOW_NO_SECTION
#define INI_ALLOW_NO_SECTION 1
#endif

/* Non-zero if inih should allow a UTF-8 BOM. See
   https://github.com/benhoyt/inih/issues/21 */
#ifndef INI_ALLOW_BOM
#define INI_ALLOW_BOM 1
#endif

/* Chars that begin a start-of-line comment. Per Python configparser, allow
   both ; and # comments at the start of a line. */
#ifndef INI_START_COMMENT_PREFIXES
#define INI_START_COMMENT_PREFIXES ";#"
#endif

/* Chars that begin an inline comment. Per Python configparser, allow both
   ; and # comments at the start of a line. */
#ifndef INI_INLINE_COMMENT_PREFIXES
#define INI_INLINE_COMMENT_PREFIXES ";"
#endif

/* Non-zero if inih should allow multi-line values, supported by leading
   whitespace instead of specific continuation characters. See
   https://github.com/benhoyt/inih/issues/20 */
#ifndef INI_ALLOW_MULTILINE
#define INI_ALLOW_MULTILINE 1
#endif

/* Non-zero if inih should allow a value to be completely empty. */
#ifndef INI_ALLOW_EMPTY_VALUES
#define INI_ALLOW_EMPTY_VALUES 1
#endif

/* Non-zero if inih should support combining multiple INI files. */
#ifndef INI_SUPPORT_REALLOC
#define INI_SUPPORT_REALLOC 0
#endif

/* Maximum line length for any line in INI file. */
#ifndef INI_MAX_LINE
#define INI_MAX_LINE 200
#endif

/* Size of read buffer. Affects how many characters are read each time from
   the given stream. */
#ifndef INI_INITIAL_ALLOC
#define INI_INITIAL_ALLOC 200
#endif

/* Typedef for prototype of handler function. */
typedef int (*ini_handler)(void* user, const char* section,
                           const char* name, const char* value);

/* Typedef for prototype of fgets-style reader function. */
typedef char* (*ini_reader)(char* str, int num, void* stream);

/* Parse given INI-style file. May have [section]s, name=value pairs
   (or name/value), and comments starting with ';' (or '#'). Section is ""
   if name=value pair parsed before any section heading. name:value mapping
   is handled as if it is name=value.
   For each name=value pair parsed, call handler function with given user
   pointer as the first argument, section name as the second argument,
   name as the third argument, and value as the fourth argument. Handler
   should return non-zero on success, zero on error.
   Returns 0 on success, line number of first error on parse error, or -1 on
   file open error.
*/
int ini_parse(const char* filename, ini_handler handler, void* user);

/* Same as ini_parse(), but takes a FILE* instead of filename. This doesn't
   close the file when it's finished -- the caller must do that. */
int ini_parse_file(FILE* file, ini_handler handler, void* user);

/* Same as ini_parse(), but takes an ini_reader function pointer instead of
   filename. Used for implementing custom or string-based readers. */
int ini_parse_stream(ini_reader reader, void* stream, ini_handler handler,
                     void* user);

#ifdef __cplusplus
}
#endif

#endif /* __INI_H__ */