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

#include <string_view>
#include <laila/predef/compiler.h>
#include <laila/predef/funcsig.h>

namespace laila { namespace mp
{
	template <class T>
	consteval std::string_view nameof()
	{
		constexpr std::string_view s = LAILA_FUNCSIG;

#if defined(_MSC_VER)
		constexpr std::string_view name = s.substr(92, s.length() - 7 - 92);
		if constexpr (name.substr(0, 6) == "class " || name.substr(0, 6) == "union ")
			return name.substr(6);
		else if constexpr (name.substr(0, 6) == "struct ")
			return name.substr(7);
		return name;
#elif defined(LAILA_COMPILER_GCC)
		return s.substr(46, s.length() - 50 - 46);
#elif defined(__clang__)
		return s.substr(31, s.length() - 1 - 31);
#endif
	}

	template <class T>
	consteval std::string_view raw_nameof()
	{
		constexpr std::string_view s = LAILA_FUNCSIG;

#if defined(LAILA_COMPILER_MSVC)
		return s.substr(92, s.length() - 7 - 92);
#elif defined(LAILA_COMPILER_GCC)
		return s.substr(46, s.length() - 50 - 46);
#elif defined(LAILA_COMPILER_CLANG)
		return s.substr(31, s.length() - 1 - 31);
#endif
	}
} }