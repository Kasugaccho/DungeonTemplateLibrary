﻿/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_FIND_HIGHEST_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_FIND_HIGHEST_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::find::Highest-(発見クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/NumericLimits.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Range/RectBaseWithValue.hpp>
#include <DTL/Utility/DrawJagged.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace find { //"dtl::find"名前空間に属する

/*#######################################################################################
	[概要] Highestとは "Matrixの描画範囲に描画値を設置する" 機能を持つクラスである。
	[Summary] Highest is a class that sets drawing values in the drawing range of Matrix.
#######################################################################################*/
		template<typename Matrix_Var_>
		class Highest : public ::dtl::range::RectBaseWithValue<Highest<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJagged<Highest<Matrix_Var_>, Matrix_Var_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseWithValue<Highest, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJagged<Highest, Matrix_Var_>;

			friend DrawBase_t;


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				typename DTL_TYPE_ENABLE_IF<Matrix_::is_jagged::value, bool>::DTL_TYPE_EITYPE
				drawNormal(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };
				Matrix_Var_ highest_value{ (DTL_TYPE_NUMERIC_LIMITS<Matrix_Var_>::DTL_TYPE_NUMERIC_LIMITS_MIN)() };

				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					const Index_Size end_x_{ this->calcEndX(matrix_.getX(row)) };
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						if (highest_value < matrix_.get(col, row)) highest_value = matrix_.get(col, row);
				}
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					const Index_Size end_x_{ this->calcEndX(matrix_.getX(row)) };
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						if (highest_value == matrix_.get(col, row)) matrix_.set(col, row, this->draw_value, args_...);
				}
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				typename DTL_TYPE_ENABLE_IF<!Matrix_::is_jagged::value, bool>::DTL_TYPE_EITYPE
				drawNormal(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				const Index_Size end_x_{ this->calcEndX(matrix_.getX()) };
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };
				Matrix_Var_ highest_value{ (DTL_TYPE_NUMERIC_LIMITS<Matrix_Var_>::DTL_TYPE_NUMERIC_LIMITS_MIN)() };

				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						if (highest_value < matrix_.get(col, row)) highest_value = matrix_.get(col, row);
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						if (highest_value == matrix_.get(col, row)) matrix_.set(col, row, this->draw_value, args_...);
				return true;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
