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

#include <cstddef>

namespace laila { namespace mp
{
	namespace detail
	{
		template <std::size_t I, class T, class... TRest>
		struct select_type_helper
		{
			using type = select_type_helper<I - 1, TRest...>::type;
		};
		template <class T, class TNext, class... TRest>
		struct select_type_helper<0, T, TNext, TRest...>
		{
			using type = T;
		};
		template <std::size_t I, class T>
		struct select_type_helper<I, T>
		{
			using type = T;
		};
	}

	template <std::size_t I, class... Ts>
	using select_type = detail::select_type_helper<I, Ts...>::type;
} }