/* Compatibility shim for <string.h>
 *
 * Copyright (C) 2016 Reece H. Dunn
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see: <http://www.gnu.org/licenses/>.
 */

#ifndef STRING_H_COMPAT_SHIM
#define STRING_H_COMPAT_SHIM

#ifdef _MSC_VER
#if _MSC_VER >= 1900 // Visual C++ 14 (Visual Studio 2015) and above...
#include <../ucrt/string.h>
#else
#include <../include/string.h>
#endif
#else
#pragma GCC system_header // Silence "warning: #include_next is a GCC extension"
#include_next <string.h>
#endif

#if defined(_WIN32) || defined(_WIN64)
#define strerror_r(errnum, buf, buflen) strerror_s(buf, buflen, errnum)
#endif

#endif
