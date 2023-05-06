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
		template <std::size_t C, class... TRest>
		struct type_count_helper
		{
			constexpr static std::size_t value = -1;
		};

		template <std::size_t C, class TDrop, class... TRest>
		struct type_count_helper<C, TDrop, TRest...>
		{
			constexpr static std::size_t value = type_count_helper<C + 1, TRest...>::value;
		};
		template <std::size_t C, class TDrop>
		struct type_count_helper<C, TDrop>
		{
			constexpr static std::size_t value = C + 1;
		};
		template <std::size_t C>
		struct type_count_helper<C>
		{
			constexpr static std::size_t value = C;
		};
	}

	template <class... Ts>
	struct type_count
	{
		constexpr static std::size_t value = detail::type_count_helper<0, Ts...>::value;
	};
} }