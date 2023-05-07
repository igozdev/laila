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
#include <laila/macro/count.h>
#include <laila/macro/expand.h>

#define LAILA_SWIZZLE(constructor, ...) LAILA_XCONCAT(LAILA_XCONCAT(LAILA_SWIZZLE_, LAILA_COUNT(__VA_ARGS__)), (constructor, __VA_ARGS__))

// /// ############################################################################################################## /// //
// /// ############################################################################################################## /// //
// /// ############################################################################################################## /// //

#define LAILA_SWIZZLE_2(constructor, _1, _2) \
	inline auto _1##_2() { return constructor(_1, _2); }	\
	inline auto _2##_1() { return constructor(_2, _1); }

#define LAILA_SWIZZLE_3(constructor, _1, _2, _3) \
	inline auto _1##_2() { return constructor(_1, _2); }			\
	inline auto _1##_3() { return constructor(_1, _3); }			\
	inline auto _2##_1() { return constructor(_2, _1); }			\
	inline auto _2##_3() { return constructor(_2, _3); }			\
	inline auto _3##_1() { return constructor(_3, _1); }			\
	inline auto _3##_2() { return constructor(_3, _2); }			\
	inline auto _1##_2##_3() { return constructor(_1, _2, _3); }	\
	inline auto _1##_3##_2() { return constructor(_1, _3, _2); }	\
	inline auto _2##_1##_3() { return constructor(_2, _1, _3); }	\
	inline auto _2##_3##_1() { return constructor(_2, _3, _1); }	\
	inline auto _3##_1##_2() { return constructor(_3, _1, _2); }	\
	inline auto _3##_2##_1() { return constructor(_3, _2, _1); }