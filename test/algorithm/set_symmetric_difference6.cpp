// Range v3 library
//
//  Copyright Eric Niebler 2014
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// Project home: https://github.com/ericniebler/range-v3
//

#include "set_symmetric_difference.hpp"
#include <nanorange/algorithm/lexicographical_compare.hpp>

TEST_CASE("alg.set_symmetric_difference6")
{
	// Test projections
	{
		S ia[] = {S{1}, S{2}, S{2}, S{3}, S{3}, S{3}, S{4}, S{4}, S{4}, S{4}};
		T ib[] = {T{2}, T{4}, T{4}, T{6}};
		U ic[20];
		int ir[] = {1, 2, 3, 3, 3, 4, 4, 6};
		const int sr = sizeof(ir)/sizeof(ir[0]);

		std::tuple<S *, T *, U *> res1 =
			stl2::set_symmetric_difference(ia, ib, ic, std::less<int>(), &S::i, &T::j);
		CHECK((std::get<2>(res1) - ic) == sr);
		CHECK_FALSE(stl2::lexicographical_compare(ic, std::get<2>(res1), ir, ir+sr, std::less<int>(), &U::k));
		stl2::fill(ic, U{0});

		std::tuple<T *, S *, U *> res2 =
			stl2::set_symmetric_difference(ib, ia, ic, std::less<int>(), &T::j, &S::i);
		CHECK((std::get<2>(res2) - ic) == sr);
		CHECK_FALSE(stl2::lexicographical_compare(ic, std::get<2>(res2), ir, ir+sr, std::less<int>(), &U::k));
	}

	// Test rvalue ranges
	{
		S ia[] = {S{1}, S{2}, S{2}, S{3}, S{3}, S{3}, S{4}, S{4}, S{4}, S{4}};
		T ib[] = {T{2}, T{4}, T{4}, T{6}};
		U ic[20];
		int ir[] = {1, 2, 3, 3, 3, 4, 4, 6};
		const int sr = sizeof(ir)/sizeof(ir[0]);

		auto res1 =
			stl2::set_symmetric_difference(std::move(ia), std::move(ib), ic, std::less<int>(), &S::i, &T::j);
#ifndef _MSC_VER
		CHECK(std::get<0>(res1).get_unsafe() == stl2::end(ia));
		CHECK(std::get<1>(res1).get_unsafe() == stl2::end(ib));
#else
		CHECK(std::get<0>(res1) == stl2::end(ia));
		CHECK(std::get<1>(res1) == stl2::end(ib));
#endif
		CHECK((std::get<2>(res1) - ic) == sr);
		CHECK_FALSE(stl2::lexicographical_compare(ic, std::get<2>(res1), ir, ir+sr, std::less<int>(), &U::k));
		stl2::fill(ic, U{0});

		auto res2 =
			stl2::set_symmetric_difference(std::move(ib), std::move(ia), ic, std::less<int>(), &T::j, &S::i);
		// FIXME: MSVC
#ifndef _MSC_VER
		CHECK(std::get<0>(res2).get_unsafe() == stl2::end(ib));
		CHECK(std::get<1>(res2).get_unsafe() == stl2::end(ia));
#else
		CHECK(std::get<0>(res2) == stl2::end(ib));
		CHECK(std::get<1>(res2) == stl2::end(ia));
#endif
		CHECK((std::get<2>(res2) - ic) == sr);
		CHECK_FALSE(stl2::lexicographical_compare(ic, std::get<2>(res2), ir, ir+sr, std::less<int>(), &U::k));
	}
}
