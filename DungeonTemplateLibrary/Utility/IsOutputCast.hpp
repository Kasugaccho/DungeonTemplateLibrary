﻿/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_IS_OUTPUT_CAST
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_IS_OUTPUT_CAST

/* Character Code : UTF-8 (BOM) */
/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <Macro/nodiscard.hpp>

namespace dtl {
	inline namespace utility {

		template<typename Int_>
		DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
		constexpr bool isOutputCast() noexcept {
			return false;
		}
		template<>
		DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
		constexpr bool isOutputCast<char>() noexcept {
			return true;
		}
		template<>
		DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
		constexpr bool isOutputCast<signed char>() noexcept {
			return true;
		}
		template<>
		DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
		constexpr bool isOutputCast<unsigned char>() noexcept {
			return true;
		}

	}
}

//共有データ
namespace dtl {
	inline namespace utility {
		namespace tool {

			template<typename Matrix_Int_>
			DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
			constexpr auto getOutputNumber(const Matrix_Int_ value_) noexcept {
				return value_;
			}
			template<>
			DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
			constexpr auto getOutputNumber<char>(const char value_) noexcept {
				return static_cast<int>(value_);
			}
			template<>
			DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
			constexpr auto getOutputNumber<signed char>(const signed char value_) noexcept {
				return static_cast<int>(value_);
			}
			template<>
			DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
			constexpr auto getOutputNumber<unsigned char>(const unsigned char value_) noexcept {
				return static_cast<int>(value_);
			}

		}
	}
}

#endif //Included Dungeon Template Library