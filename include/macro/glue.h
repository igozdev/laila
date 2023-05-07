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

#define LAILA_GLUE(glue, _1, _2) _1 ## glue ## _2
#define LAILA_GLUE_ALL(glue, ...) LAILA_XCONCAT(LAILA_XCONCAT(LAILA_GLUE_, LAILA_COUNT(__VA_ARGS__)), (glue, __VA_ARGS__))

// /// ############################################################################################################## /// //
// /// ############################################################################################################## /// //
// /// ############################################################################################################## /// //

#define LAILA_GLUE_2(glue, _1, _2) \
	_1 ## glue ## _2
#define LAILA_GLUE_3(glue, _1, _2, _3) \
	_1 ## glue ## _2 ## glue ## _3
#define LAILA_GLUE_4(glue, _1, _2, _3, _4) \
	_1 ## glue ## _2 ## glue ## _3 ## glue ## _4
#define LAILA_GLUE_5(glue, _1, _2, _3, _4, _5) \
	_1 ## glue ## _2 ## glue ## _3 ## glue ## _4 ## glue ## _5
#define LAILA_GLUE_6(glue, _1, _2, _3, _4, _5, _6) \
	_1 ## glue ## _2 ## glue ## _3 ## glue ## _4 ## glue ## _5 ## glue ## _6
#define LAILA_GLUE_7(glue, _1, _2, _3, _4, _5, _6, _7) \
	_1 ## glue ## _2 ## glue ## _3 ## glue ## _4 ## glue ## _5 ## glue ## _6 ## glue ## _7
#define LAILA_GLUE_8(glue, _1, _2, _3, _4, _5, _6, _7, _8) \
	_1 ## glue ## _2 ## glue ## _3 ## glue ## _4 ## glue ## _5 ## glue ## _6 ## glue ## _7 ## glue ## _8