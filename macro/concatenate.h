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

#include <laila/macro/expand.h>
#include <laila/macro/count.h>

#define LAILA_CONCAT(lhs, rhs) lhs ## rhs
#define LAILA_XCONCAT(lhs, rhs) LAILA_CONCAT(lhs, rhs)

#define LAILA_CONCAT_ALL(...) LAILA_XCONCAT(LAILA_XCONCAT(LAILA_CONCAT_, LAILA_COUNT(__VA_ARGS__)), (__VA_ARGS__))

// /// ############################################################################################################## /// //
// /// ############################################################################################################## /// //
// /// ############################################################################################################## /// //

#define LAILA_CONCAT_1(_1) \
	_1
#define LAILA_CONCAT_2(_1, _2) \
	_1##_2
#define LAILA_CONCAT_3(_1, _2, _3) \
	_1##_2##_3
#define LAILA_CONCAT_4(_1, _2, _3, _4) \
	_1##_2##_3##_4
#define LAILA_CONCAT_5(_1, _2, _3, _4, _5) \
	_1##_2##_3##_4##_5
#define LAILA_CONCAT_6(_1, _2, _3, _4, _5, _6) \
	_1##_2##_3##_4##_5##_6
#define LAILA_CONCAT_7(_1, _2, _3, _4, _5, _6, _7) \
	_1##_2##_3##_4##_5##_6##_7
#define LAILA_CONCAT_8(_1, _2, _3, _4, _5, _6, _7, _8) \
	_1##_2##_3##_4##_5##_6##_7##_8
#define LAILA_CONCAT_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) \
	_1##_2##_3##_4##_5##_6##_7##_8##_9
#define LAILA_CONCAT_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
	_1##_2##_3##_4##_5##_6##_7##_8##_9##_10
#define LAILA_CONCAT_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
	_1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11
#define LAILA_CONCAT_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
	_1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12
#define LAILA_CONCAT_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
	_1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13
#define LAILA_CONCAT_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) \
	_1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14
#define LAILA_CONCAT_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
	_1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15
#define LAILA_CONCAT_16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) \
	_1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16
#define LAILA_CONCAT_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
	_1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17
#define LAILA_CONCAT_18(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) \
	_1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18
#define LAILA_CONCAT_19(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) \
	_1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19
#define LAILA_CONCAT_20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20) \
	_1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20
#define LAILA_CONCAT_21(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21) \
	_1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20##_21