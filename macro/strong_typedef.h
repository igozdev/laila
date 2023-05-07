// MIT License
// 
// Copyright(c) 2023 igozdev
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this softwareand associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright noticeand this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <laila/macro/concatenate.h>
#include <laila/macro/dnoexcept.h>
#include <laila/metaprogramming/fake_value.h>

#if defined(LAILA_FLAG_NODEFAULT) || defined(LAILA_FLAG_ALLIMPLICIT) || defined(LAILA_FLAG_ALLEXPLICIT) ||defined(LAILA_FLAG_ALLCONSTEXPR)
    #error LAILA_STRONG_TYPEDEF flags may not be defined!
#endif

#define LAILA_STRONG_TYPEDEF(type, name) \
	struct name																		\
	{																				\
		inline name() dnoexcept(type())												\
			: value() {}															\
		inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))		\
			: value(v) {}															\
		inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))	\
			: value(v.value) {}														\
																					\
		inline name& operator=(const name& v)										\
			{ value = v.value; return *this; }										\
		inline name& operator=(const type& v)										\
			{ value = v; return *this; }											\
																					\
		inline explicit operator const type&() const								\
			{ return value; }														\
		inline explicit operator type&()											\
			{ return value; }														\
																					\
		type value;																	\
	};
#define LAILA_SPEC_STRONG_TYPEDEF(type, name, ...) LAILA_XEXPAND(LAILA_XCONCAT(LAILA_XCONCAT(LAILA_CONCAT_ALL(LAILA_SPEC_STRONG_TYPEDEF), LAILA_CONCAT_ALL(__VA_ARGS__)), (type, name)))

// /// ############################################################################################################## /// //
// /// ############################################################################################################## /// //
// /// ############################################################################################################## /// //

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLCONSTEXPR(type, name)\
struct name\
{\
constexpr inline name() dnoexcept(type())\
        : value() {}\
constexpr inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
constexpr inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
constexpr explicit inline operator const type&() const\
        { return value; }\
constexpr explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLEXPLICIT(type, name)\
struct name\
{\
explicit inline name() dnoexcept(type())\
        : value() {}\
explicit inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
explicit inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
\
explicit inline operator const type&() const\
        { return value; }\
explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLIMPLICIT(type, name)\
struct name\
{\
inline name() dnoexcept(type())\
        : value() {}\
inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
inline operator const type&() const\
        { return value; }\
inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_NODEFAULT(type, name)\
struct name\
{\
inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
explicit inline operator const type&() const\
        { return value; }\
explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLCONSTEXPRLAILA_FLAG_ALLEXPLICIT(type, name)\
struct name\
{\
constexpr explicit inline name() dnoexcept(type())\
        : value() {}\
constexpr explicit inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr explicit inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
\
constexpr explicit inline operator const type&() const\
        { return value; }\
constexpr explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLCONSTEXPRLAILA_FLAG_ALLIMPLICIT(type, name)\
struct name\
{\
constexpr inline name() dnoexcept(type())\
        : value() {}\
constexpr inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
constexpr inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
constexpr inline operator const type&() const\
        { return value; }\
constexpr inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLCONSTEXPRLAILA_FLAG_NODEFAULT(type, name)\
struct name\
{\
constexpr inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
constexpr inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
constexpr explicit inline operator const type&() const\
        { return value; }\
constexpr explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLEXPLICITLAILA_FLAG_ALLCONSTEXPR(type, name)\
struct name\
{\
constexpr explicit inline name() dnoexcept(type())\
        : value() {}\
constexpr explicit inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr explicit inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
\
constexpr explicit inline operator const type&() const\
        { return value; }\
constexpr explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLEXPLICITLAILA_FLAG_NODEFAULT(type, name)\
struct name\
{\
explicit inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
explicit inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
\
explicit inline operator const type&() const\
        { return value; }\
explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLIMPLICITLAILA_FLAG_ALLCONSTEXPR(type, name)\
struct name\
{\
constexpr inline name() dnoexcept(type())\
        : value() {}\
constexpr inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
constexpr inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
constexpr inline operator const type&() const\
        { return value; }\
constexpr inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLIMPLICITLAILA_FLAG_NODEFAULT(type, name)\
struct name\
{\
inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
inline operator const type&() const\
        { return value; }\
inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_NODEFAULTLAILA_FLAG_ALLCONSTEXPR(type, name)\
struct name\
{\
constexpr inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
constexpr inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
constexpr explicit inline operator const type&() const\
        { return value; }\
constexpr explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_NODEFAULTLAILA_FLAG_ALLEXPLICIT(type, name)\
struct name\
{\
explicit inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
explicit inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
\
explicit inline operator const type&() const\
        { return value; }\
explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_NODEFAULTLAILA_FLAG_ALLIMPLICIT(type, name)\
struct name\
{\
inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
inline operator const type&() const\
        { return value; }\
inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLCONSTEXPRLAILA_FLAG_ALLEXPLICITLAILA_FLAG_NODEFAULT(type, name)\
struct name\
{\
constexpr explicit inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr explicit inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
\
constexpr explicit inline operator const type&() const\
        { return value; }\
constexpr explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLCONSTEXPRLAILA_FLAG_ALLIMPLICITLAILA_FLAG_NODEFAULT(type, name)\
struct name\
{\
constexpr inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
constexpr inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
constexpr inline operator const type&() const\
        { return value; }\
constexpr inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLCONSTEXPRLAILA_FLAG_NODEFAULTLAILA_FLAG_ALLEXPLICIT(type, name)\
struct name\
{\
constexpr explicit inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr explicit inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
\
constexpr explicit inline operator const type&() const\
        { return value; }\
constexpr explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLCONSTEXPRLAILA_FLAG_NODEFAULTLAILA_FLAG_ALLIMPLICIT(type, name)\
struct name\
{\
constexpr inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
constexpr inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
constexpr inline operator const type&() const\
        { return value; }\
constexpr inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLEXPLICITLAILA_FLAG_ALLCONSTEXPRLAILA_FLAG_NODEFAULT(type, name)\
struct name\
{\
constexpr explicit inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr explicit inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
\
constexpr explicit inline operator const type&() const\
        { return value; }\
constexpr explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLEXPLICITLAILA_FLAG_NODEFAULTLAILA_FLAG_ALLCONSTEXPR(type, name)\
struct name\
{\
constexpr explicit inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr explicit inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
\
constexpr explicit inline operator const type&() const\
        { return value; }\
constexpr explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLIMPLICITLAILA_FLAG_ALLCONSTEXPRLAILA_FLAG_NODEFAULT(type, name)\
struct name\
{\
constexpr inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
constexpr inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
constexpr inline operator const type&() const\
        { return value; }\
constexpr inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_ALLIMPLICITLAILA_FLAG_NODEFAULTLAILA_FLAG_ALLCONSTEXPR(type, name)\
struct name\
{\
constexpr inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
constexpr inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
constexpr inline operator const type&() const\
        { return value; }\
constexpr inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_NODEFAULTLAILA_FLAG_ALLCONSTEXPRLAILA_FLAG_ALLEXPLICIT(type, name)\
struct name\
{\
constexpr explicit inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr explicit inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
\
constexpr explicit inline operator const type&() const\
        { return value; }\
constexpr explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_NODEFAULTLAILA_FLAG_ALLCONSTEXPRLAILA_FLAG_ALLIMPLICIT(type, name)\
struct name\
{\
constexpr inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
constexpr inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
constexpr inline operator const type&() const\
        { return value; }\
constexpr inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_NODEFAULTLAILA_FLAG_ALLEXPLICITLAILA_FLAG_ALLCONSTEXPR(type, name)\
struct name\
{\
constexpr explicit inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr explicit inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
\
constexpr explicit inline operator const type&() const\
        { return value; }\
constexpr explicit inline operator type&()\
        { return value; }\
\
type value;   \
};

#define LAILA_SPEC_STRONG_TYPEDEFLAILA_FLAG_NODEFAULTLAILA_FLAG_ALLIMPLICITLAILA_FLAG_ALLCONSTEXPR(type, name)\
struct name\
{\
constexpr inline name(type v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v) {}\
constexpr inline name(const name& v) dnoexcept(type(::laila::mp::fake_value<type>()))\
        : value(v.value) {}\
\
constexpr inline name& operator=(const name& v)\
        { value = v.value; return *this; }\
constexpr inline name& operator=(const type& v)\
        { value = v; return *this; }\
\
constexpr inline operator const type&() const\
        { return value; }\
constexpr inline operator type&()\
        { return value; }\
\
type value;   \
};