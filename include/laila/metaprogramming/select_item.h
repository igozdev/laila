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
		template <class T, std::size_t I, T V, T... VRest>
		struct select_item_helper
		{
			constexpr static T value = select_item_helper<T, I - 1, VRest...>::value;
		};
		template <class T, T V, T VNext, T... VRest>
		struct select_item_helper<T, 0, V, VNext, VRest...>
		{
			constexpr static T value = V;
		};
		template <class T, std::size_t I, T V>
		struct select_item_helper<T, I, V>
		{
			constexpr static T value = V;
		};
	}

	template <class T, std::size_t I, T... Vs>
	struct select_item
	{
		constexpr static T value = detail::select_item_helper<T, I, Vs...>::value;
	};
} }