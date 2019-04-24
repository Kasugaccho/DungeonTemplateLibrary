﻿/*#######################################################################################
	Made by Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_NOISE_SHORE_BOOL
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_NOISE_SHORE_BOOL

/* Character Code : UTF-8 (BOM) */
/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <Random/MersenneTwister32bit.hpp>
#include <Macro/nodiscard.hpp>

//共有データ
namespace dtl {
	inline namespace utility {
		namespace tool {

			//noiseShoreBool関数から取得したマップデータの値を1/2の確率でノイズさせるか判定する
			template<typename Matrix_Int_>
			DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
			constexpr bool isNoise_noiseShoreBool(const Matrix_Int_ value_, const Matrix_Int_ value2_, const Matrix_Int_ value3_) noexcept {

				using dtl::random::mersenne_twister_32bit;

				return (value_ != value2_ || value_ != value3_) && mersenne_twister_32bit.probability();
			}
			//noiseShoreBool関数から取得したマップデータの値を[rbool_]の確率でノイズさせるか判定する
			template<typename Matrix_Int_>
			DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
			constexpr bool isNoise_noiseShoreBool(const Matrix_Int_ value_, const Matrix_Int_ value2_, const Matrix_Int_ value3_, const double rbool_) noexcept {

				using dtl::random::mersenne_twister_32bit;

				return (value_ != value2_ || value_ != value3_) && mersenne_twister_32bit.probability(rbool_);
			}

		} //namespace

		//STLデータ
		namespace stl {

			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBool(Matrix_& matrix_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
					for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row][col], matrix_[row][col - 1], matrix_[row - 1][col])) continue;
						if (matrix_[row][col]) matrix_[row][col] = false;
						else matrix_[row][col] = true;
					}
			}

			//[rbool_]の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBool(Matrix_ & matrix_, const double rbool_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
					for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row][col], matrix_[row][col - 1], matrix_[row - 1][col], rbool_)) continue;
						if (matrix_[row][col]) matrix_[row][col] = false;
						else matrix_[row][col] = true;
					}
			}

			//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
			template<typename Matrix_Int_, typename Matrix_>
			constexpr void noiseShoreBool(Matrix_ & matrix_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
					for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row][col], matrix_[row][col - 1], matrix_[row - 1][col], rbool_)) continue;
						if (matrix_[row][col]) matrix_[row][col] = false_tile_;
						else matrix_[row][col] = true_tile_;
					}
			}

			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBool(Matrix_ & matrix_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ matrix_.size() - 1 }; row >= 1; --row)
					for (std::size_t col{ matrix_[row].size() - 1 }; col >= 1; --col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1], matrix_[row][col - 1], matrix_[row - 1][col])) continue;
						if (matrix_[row - 1][col - 1]) matrix_[row - 1][col - 1] = false;
						else matrix_[row - 1][col - 1] = true;
					}
			}

			//[rbool_]の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBool(Matrix_ & matrix_, const double rbool_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ matrix_.size() - 1 }; row >= 1; --row)
					for (std::size_t col{ matrix_[row].size() - 1 }; col >= 1; --col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1], matrix_[row][col - 1], matrix_[row - 1][col], rbool_)) continue;
						if (matrix_[row - 1][col - 1]) matrix_[row - 1][col - 1] = false;
						else matrix_[row - 1][col - 1] = true;
					}
			}

			//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
			template<typename Matrix_Int_, typename Matrix_>
			constexpr void rnoiseShoreBool(Matrix_ & matrix_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ matrix_.size() - 1 }; row >= 1; --row)
					for (std::size_t col{ matrix_[row].size() - 1 }; col >= 1; --col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1], matrix_[row][col - 1], matrix_[row - 1][col], rbool_)) continue;
						if (matrix_[row - 1][col - 1]) matrix_[row - 1][col - 1] = false_tile_;
						else matrix_[row - 1][col - 1] = true_tile_;
					}
			}

			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBothBool(Matrix_ & matrix_) noexcept {
				dtl::utility::stl::noiseShoreBool(matrix_);
				dtl::utility::stl::rnoiseShoreBool(matrix_);
			}
			//[rbool_]の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBothBool(Matrix_ & matrix_, const double rbool_) noexcept {
				dtl::utility::stl::noiseShoreBool(matrix_, rbool_);
				dtl::utility::stl::rnoiseShoreBool(matrix_, rbool_);
			}
			template<typename Matrix_>
			constexpr void noiseShoreBothBool(Matrix_ & matrix_, const double rbool1_, const double rbool2_) noexcept {
				dtl::utility::stl::noiseShoreBool(matrix_, rbool1_);
				dtl::utility::stl::rnoiseShoreBool(matrix_, rbool2_);
			}
			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBothBool(Matrix_ & matrix_) noexcept {
				dtl::utility::stl::rnoiseShoreBool(matrix_);
				dtl::utility::stl::noiseShoreBool(matrix_);
			}
			//[rbool_]の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBothBool(Matrix_ & matrix_, const double rbool_) noexcept {
				dtl::utility::stl::rnoiseShoreBool(matrix_, rbool_);
				dtl::utility::stl::noiseShoreBool(matrix_, rbool_);
			}
			template<typename Matrix_>
			constexpr void rnoiseShoreBothBool(Matrix_ & matrix_, const double rbool1_, const double rbool2_) noexcept {
				dtl::utility::stl::rnoiseShoreBool(matrix_, rbool1_);
				dtl::utility::stl::noiseShoreBool(matrix_, rbool2_);
			}

		} //namespace

		//通常データ
		namespace normal {

			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBool(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ 1 }; row < y_; ++row)
					for (std::size_t col{ 1 }; col < x_; ++col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row][col], matrix_[row][col - 1], matrix_[row - 1][col])) continue;
						if (matrix_[row][col]) matrix_[row][col] = false;
						else matrix_[row][col] = true;
					}
			}

			//[rbool_]の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ 1 }; row < y_; ++row)
					for (std::size_t col{ 1 }; col < x_; ++col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row][col], matrix_[row][col - 1], matrix_[row - 1][col], rbool_)) continue;
						if (matrix_[row][col]) matrix_[row][col] = false;
						else matrix_[row][col] = true;
					}
			}

			//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
			template<typename Matrix_Int_, typename Matrix_>
			constexpr void noiseShoreBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ 1 }; row < y_; ++row)
					for (std::size_t col{ 1 }; col < x_; ++col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row][col], matrix_[row][col - 1], matrix_[row - 1][col], rbool_)) continue;
						if (matrix_[row][col]) matrix_[row][col] = false_tile_;
						else matrix_[row][col] = true_tile_;
					}
			}

			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ y_ - 1 }; row >= 1; --row)
					for (std::size_t col{ x_ - 1 }; col >= 1; --col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1], matrix_[row][col - 1], matrix_[row - 1][col])) continue;
						if (matrix_[row - 1][col - 1]) matrix_[row - 1][col - 1] = false;
						else matrix_[row - 1][col - 1] = true;
					}
			}

			//[rbool_]の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ y_ - 1 }; row >= 1; --row)
					for (std::size_t col{ x_ - 1 }; col >= 1; --col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1], matrix_[row][col - 1], matrix_[row - 1][col], rbool_)) continue;
						if (matrix_[row - 1][col - 1]) matrix_[row - 1][col - 1] = false;
						else matrix_[row - 1][col - 1] = true;
					}
			}

			//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
			template<typename Matrix_Int_, typename Matrix_>
			constexpr void rnoiseShoreBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ y_ - 1 }; row >= 1; --row)
					for (std::size_t col{ x_ - 1 }; col >= 1; --col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1], matrix_[row][col - 1], matrix_[row - 1][col], rbool_)) continue;
						if (matrix_[row - 1][col - 1]) matrix_[row - 1][col - 1] = false_tile_;
						else matrix_[row - 1][col - 1] = true_tile_;
					}
			}

			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBothBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_) noexcept {
				dtl::utility::normal::noiseShoreBool(matrix_);
				dtl::utility::normal::rnoiseShoreBool(matrix_);
			}
			//[rbool_]の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBothBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {
				dtl::utility::normal::noiseShoreBool(matrix_, rbool_);
				dtl::utility::normal::rnoiseShoreBool(matrix_, rbool_);
			}
			template<typename Matrix_>
			constexpr void noiseShoreBothBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool1_, const double rbool2_) noexcept {
				dtl::utility::normal::noiseShoreBool(matrix_, rbool1_);
				dtl::utility::normal::rnoiseShoreBool(matrix_, rbool2_);
			}
			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBothBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_) noexcept {
				dtl::utility::normal::rnoiseShoreBool(matrix_);
				dtl::utility::normal::noiseShoreBool(matrix_);
			}
			//[rbool_]の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBothBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {
				dtl::utility::normal::rnoiseShoreBool(matrix_, rbool_);
				dtl::utility::normal::noiseShoreBool(matrix_, rbool_);
			}
			template<typename Matrix_>
			constexpr void rnoiseShoreBothBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool1_, const double rbool2_) noexcept {
				dtl::utility::normal::rnoiseShoreBool(matrix_, rbool1_);
				dtl::utility::normal::noiseShoreBool(matrix_, rbool2_);
			}

		} //namespace

		//配列データ
		namespace array {

			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBool(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ 1 }; row < y_; ++row)
					for (std::size_t col{ 1 }; col < x_; ++col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[(row)* x_ + (col)], matrix_[(row)* x_ + (col - 1)], matrix_[(row - 1) * x_ + (col)])) continue;
						if (matrix_[(row)* x_ + (col)]) matrix_[(row)* x_ + (col)] = false;
						else matrix_[(row)* x_ + (col)] = true;
					}
			}

			//[(rbool_)]の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ 1 }; row < y_; ++row)
					for (std::size_t col{ 1 }; col < x_; ++col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[(row)* x_ + (col)], matrix_[(row)* x_ + (col - 1)], matrix_[(row - 1) * x_ + (col)], rbool_)) continue;
						if (matrix_[(row)* x_ + (col)]) matrix_[(row)* x_ + (col)] = false;
						else matrix_[(row)* x_ + (col)] = true;
					}
			}

			//[(rbool_)]の確率でマップデータの値がtrueの場合は[(true_tile_)]、falseの場合は[(false_tile_)]を代入する
			template<typename Matrix_Int_, typename Matrix_>
			constexpr void noiseShoreBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ 1 }; row < y_; ++row)
					for (std::size_t col{ 1 }; col < x_; ++col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[(row)* x_ + (col)], matrix_[(row)* x_ + (col - 1)], matrix_[(row - 1) * x_ + (col)], rbool_)) continue;
						if (matrix_[(row)* x_ + (col)]) matrix_[(row)* x_ + (col)] = false_tile_;
						else matrix_[(row)* x_ + (col)] = true_tile_;
					}
			}

			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ y_ - 1 }; row >= 1; --row)
					for (std::size_t col{ x_ - 1 }; col >= 1; --col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[(row - 1) * x_ + (col - 1)], matrix_[(row)* x_ + (col - 1)], matrix_[(row - 1) * x_ + (col)])) continue;
						if (matrix_[(row - 1) * x_ + (col - 1)]) matrix_[(row - 1) * x_ + (col - 1)] = false;
						else matrix_[(row - 1) * x_ + (col - 1)] = true;
					}
			}

			//[(rbool_)]の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ y_ - 1 }; row >= 1; --row)
					for (std::size_t col{ x_ - 1 }; col >= 1; --col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[(row - 1) * x_ + (col - 1)], matrix_[(row)* x_ + (col - 1)], matrix_[(row - 1) * x_ + (col)], rbool_)) continue;
						if (matrix_[(row - 1) * x_ + (col - 1)]) matrix_[(row - 1) * x_ + (col - 1)] = false;
						else matrix_[(row - 1) * x_ + (col - 1)] = true;
					}
			}

			//[(rbool_)]の確率でマップデータの値がtrueの場合は[(true_tile_)]、falseの場合は[(false_tile_)]を代入する
			template<typename Matrix_Int_, typename Matrix_>
			constexpr void rnoiseShoreBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ y_ - 1 }; row >= 1; --row)
					for (std::size_t col{ x_ - 1 }; col >= 1; --col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[(row - 1) * x_ + (col - 1)], matrix_[(row)* x_ + (col - 1)], matrix_[(row - 1) * x_ + (col)], rbool_)) continue;
						if (matrix_[(row - 1) * x_ + (col - 1)]) matrix_[(row - 1) * x_ + (col - 1)] = false_tile_;
						else matrix_[(row - 1) * x_ + (col - 1)] = true_tile_;
					}
			}

			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBothBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_) noexcept {
				dtl::utility::array::noiseShoreBool(matrix_);
				dtl::utility::array::rnoiseShoreBool(matrix_);
			}
			//[(rbool_)]の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBothBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {
				dtl::utility::array::noiseShoreBool(matrix_, rbool_);
				dtl::utility::array::rnoiseShoreBool(matrix_, rbool_);
			}
			template<typename Matrix_>
			constexpr void noiseShoreBothBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool1_, const double rbool2_) noexcept {
				dtl::utility::array::noiseShoreBool(matrix_, rbool1_);
				dtl::utility::array::rnoiseShoreBool(matrix_, rbool2_);
			}
			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBothBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_) noexcept {
				dtl::utility::array::rnoiseShoreBool(matrix_);
				dtl::utility::array::noiseShoreBool(matrix_);
			}
			//[(rbool_)]の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBothBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {
				dtl::utility::array::rnoiseShoreBool(matrix_, rbool_);
				dtl::utility::array::noiseShoreBool(matrix_, rbool_);
			}
			template<typename Matrix_>
			constexpr void rnoiseShoreBothBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool1_, const double rbool2_) noexcept {
				dtl::utility::array::rnoiseShoreBool(matrix_, rbool1_);
				dtl::utility::array::noiseShoreBool(matrix_, rbool2_);
			}

		} //namespace

		//レイヤーSTLデータ
		namespace layer {
			namespace stl {

				//1/2の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void noiseShoreBool(Matrix_& matrix_, const std::size_t layer_) noexcept {

					using dtl::random::mersenne_twister_32bit;
					using dtl::utility::tool::isNoise_noiseShoreBool;

					for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
						for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
							//ノイズを発生させるか判定する
							if (!isNoise_noiseShoreBool(matrix_[row][col][layer_], matrix_[row][col - 1][layer_], matrix_[row - 1][col][layer_])) continue;
							if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = false;
							else matrix_[row][col][layer_] = true;
						}
				}

				//[rbool_]の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void noiseShoreBool(Matrix_ & matrix_, const std::size_t layer_, const double rbool_) noexcept {

					using dtl::random::mersenne_twister_32bit;
					using dtl::utility::tool::isNoise_noiseShoreBool;

					for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
						for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
							//ノイズを発生させるか判定する
							if (!isNoise_noiseShoreBool(matrix_[row][col][layer_], matrix_[row][col - 1][layer_], matrix_[row - 1][col][layer_], rbool_)) continue;
							if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = false;
							else matrix_[row][col][layer_] = true;
						}
				}

				//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void noiseShoreBool(Matrix_ & matrix_, const std::size_t layer_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

					using dtl::random::mersenne_twister_32bit;
					using dtl::utility::tool::isNoise_noiseShoreBool;

					for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
						for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
							//ノイズを発生させるか判定する
							if (!isNoise_noiseShoreBool(matrix_[row][col][layer_], matrix_[row][col - 1][layer_], matrix_[row - 1][col][layer_], rbool_)) continue;
							if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = false_tile_;
							else matrix_[row][col][layer_] = true_tile_;
						}
				}

				//1/2の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void rnoiseShoreBool(Matrix_ & matrix_, const std::size_t layer_) noexcept {

					using dtl::random::mersenne_twister_32bit;
					using dtl::utility::tool::isNoise_noiseShoreBool;

					for (std::size_t row{ matrix_.size() - 1 }; row >= 1; --row)
						for (std::size_t col{ matrix_[row].size() - 1 }; col >= 1; --col) {
							//ノイズを発生させるか判定する
							if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1][layer_], matrix_[row][col - 1][layer_], matrix_[row - 1][col][layer_])) continue;
							if (matrix_[row - 1][col - 1][layer_]) matrix_[row - 1][col - 1][layer_] = false;
							else matrix_[row - 1][col - 1][layer_] = true;
						}
				}

				//[rbool_]の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void rnoiseShoreBool(Matrix_ & matrix_, const std::size_t layer_, const double rbool_) noexcept {

					using dtl::random::mersenne_twister_32bit;
					using dtl::utility::tool::isNoise_noiseShoreBool;

					for (std::size_t row{ matrix_.size() - 1 }; row >= 1; --row)
						for (std::size_t col{ matrix_[row].size() - 1 }; col >= 1; --col) {
							//ノイズを発生させるか判定する
							if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1][layer_], matrix_[row][col - 1][layer_], matrix_[row - 1][col][layer_], rbool_)) continue;
							if (matrix_[row - 1][col - 1][layer_]) matrix_[row - 1][col - 1][layer_] = false;
							else matrix_[row - 1][col - 1][layer_] = true;
						}
				}

				//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void rnoiseShoreBool(Matrix_ & matrix_, const std::size_t layer_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

					using dtl::random::mersenne_twister_32bit;
					using dtl::utility::tool::isNoise_noiseShoreBool;

					for (std::size_t row{ matrix_.size() - 1 }; row >= 1; --row)
						for (std::size_t col{ matrix_[row].size() - 1 }; col >= 1; --col) {
							//ノイズを発生させるか判定する
							if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1][layer_], matrix_[row][col - 1][layer_], matrix_[row - 1][col][layer_], rbool_)) continue;
							if (matrix_[row - 1][col - 1][layer_]) matrix_[row - 1][col - 1][layer_] = false_tile_;
							else matrix_[row - 1][col - 1][layer_] = true_tile_;
						}
				}

				//1/2の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void noiseShoreBothBool(Matrix_ & matrix_, const std::size_t layer_) noexcept {
					dtl::utility::layer::stl::noiseShoreBool(matrix_, layer_);
					dtl::utility::layer::stl::rnoiseShoreBool(matrix_, layer_);
				}
				//[rbool_]の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void noiseShoreBothBool(Matrix_ & matrix_, const std::size_t layer_, const double rbool_) noexcept {
					dtl::utility::layer::stl::noiseShoreBool(matrix_, layer_, rbool_);
					dtl::utility::layer::stl::rnoiseShoreBool(matrix_, layer_, rbool_);
				}
				template<typename Matrix_>
				constexpr void noiseShoreBothBool(Matrix_ & matrix_, const std::size_t layer_, const double rbool1_, const double rbool2_) noexcept {
					dtl::utility::layer::stl::noiseShoreBool(matrix_, layer_, rbool1_);
					dtl::utility::layer::stl::rnoiseShoreBool(matrix_, layer_, rbool2_);
				}
				//1/2の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void rnoiseShoreBothBool(Matrix_ & matrix_, const std::size_t layer_) noexcept {
					dtl::utility::layer::stl::rnoiseShoreBool(matrix_, layer_);
					dtl::utility::layer::stl::noiseShoreBool(matrix_, layer_);
				}
				//[rbool_]の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void rnoiseShoreBothBool(Matrix_ & matrix_, const std::size_t layer_, const double rbool_) noexcept {
					dtl::utility::layer::stl::rnoiseShoreBool(matrix_, layer_, rbool_);
					dtl::utility::layer::stl::noiseShoreBool(matrix_, layer_, rbool_);
				}
				template<typename Matrix_>
				constexpr void rnoiseShoreBothBool(Matrix_ & matrix_, const std::size_t layer_, const double rbool1_, const double rbool2_) noexcept {
					dtl::utility::layer::stl::rnoiseShoreBool(matrix_, layer_, rbool1_);
					dtl::utility::layer::stl::noiseShoreBool(matrix_, layer_, rbool2_);
				}

			} //namespace
		}

		//レイヤー通常データ
		namespace layer {
			namespace normal {

				//1/2の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void noiseShoreBool(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {

					using dtl::random::mersenne_twister_32bit;
					using dtl::utility::tool::isNoise_noiseShoreBool;

					for (std::size_t row{ 1 }; row < y_; ++row)
						for (std::size_t col{ 1 }; col < x_; ++col) {
							//ノイズを発生させるか判定する
							if (!isNoise_noiseShoreBool(matrix_[row][col][layer_], matrix_[row][col - 1][layer_], matrix_[row - 1][col][layer_])) continue;
							if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = false;
							else matrix_[row][col][layer_] = true;
						}
				}

				//[rbool_]の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void noiseShoreBool(Matrix_ & matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {

					using dtl::random::mersenne_twister_32bit;
					using dtl::utility::tool::isNoise_noiseShoreBool;

					for (std::size_t row{ 1 }; row < y_; ++row)
						for (std::size_t col{ 1 }; col < x_; ++col) {
							//ノイズを発生させるか判定する
							if (!isNoise_noiseShoreBool(matrix_[row][col][layer_], matrix_[row][col - 1][layer_], matrix_[row - 1][col][layer_], rbool_)) continue;
							if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = false;
							else matrix_[row][col][layer_] = true;
						}
				}

				//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void noiseShoreBool(Matrix_ & matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

					using dtl::random::mersenne_twister_32bit;
					using dtl::utility::tool::isNoise_noiseShoreBool;

					for (std::size_t row{ 1 }; row < y_; ++row)
						for (std::size_t col{ 1 }; col < x_; ++col) {
							//ノイズを発生させるか判定する
							if (!isNoise_noiseShoreBool(matrix_[row][col][layer_], matrix_[row][col - 1][layer_], matrix_[row - 1][col][layer_], rbool_)) continue;
							if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = false_tile_;
							else matrix_[row][col][layer_] = true_tile_;
						}
				}

				//1/2の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void rnoiseShoreBool(Matrix_ & matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {

					using dtl::random::mersenne_twister_32bit;
					using dtl::utility::tool::isNoise_noiseShoreBool;

					for (std::size_t row{ y_ - 1 }; row >= 1; --row)
						for (std::size_t col{ x_ - 1 }; col >= 1; --col) {
							//ノイズを発生させるか判定する
							if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1][layer_], matrix_[row][col - 1][layer_], matrix_[row - 1][col][layer_])) continue;
							if (matrix_[row - 1][col - 1][layer_]) matrix_[row - 1][col - 1][layer_] = false;
							else matrix_[row - 1][col - 1][layer_] = true;
						}
				}

				//[rbool_]の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void rnoiseShoreBool(Matrix_ & matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {

					using dtl::random::mersenne_twister_32bit;
					using dtl::utility::tool::isNoise_noiseShoreBool;

					for (std::size_t row{ y_ - 1 }; row >= 1; --row)
						for (std::size_t col{ x_ - 1 }; col >= 1; --col) {
							//ノイズを発生させるか判定する
							if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1][layer_], matrix_[row][col - 1][layer_], matrix_[row - 1][col][layer_], rbool_)) continue;
							if (matrix_[row - 1][col - 1][layer_]) matrix_[row - 1][col - 1][layer_] = false;
							else matrix_[row - 1][col - 1][layer_] = true;
						}
				}

				//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void rnoiseShoreBool(Matrix_ & matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

					using dtl::random::mersenne_twister_32bit;
					using dtl::utility::tool::isNoise_noiseShoreBool;

					for (std::size_t row{ y_ - 1 }; row >= 1; --row)
						for (std::size_t col{ x_ - 1 }; col >= 1; --col) {
							//ノイズを発生させるか判定する
							if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1][layer_], matrix_[row][col - 1][layer_], matrix_[row - 1][col][layer_], rbool_)) continue;
							if (matrix_[row - 1][col - 1][layer_]) matrix_[row - 1][col - 1][layer_] = false_tile_;
							else matrix_[row - 1][col - 1][layer_] = true_tile_;
						}
				}

				//1/2の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void noiseShoreBothBool(Matrix_ & matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
					dtl::utility::layer::normal::noiseShoreBool(matrix_, layer_);
					dtl::utility::layer::normal::rnoiseShoreBool(matrix_, layer_);
				}
				//[rbool_]の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void noiseShoreBothBool(Matrix_ & matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {
					dtl::utility::layer::normal::noiseShoreBool(matrix_, layer_, rbool_);
					dtl::utility::layer::normal::rnoiseShoreBool(matrix_, layer_, rbool_);
				}
				template<typename Matrix_>
				constexpr void noiseShoreBothBool(Matrix_ & matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const double rbool1_, const double rbool2_) noexcept {
					dtl::utility::layer::normal::noiseShoreBool(matrix_, layer_, rbool1_);
					dtl::utility::layer::normal::rnoiseShoreBool(matrix_, layer_, rbool2_);
				}
				//1/2の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void rnoiseShoreBothBool(Matrix_ & matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
					dtl::utility::layer::normal::rnoiseShoreBool(matrix_, layer_);
					dtl::utility::layer::normal::noiseShoreBool(matrix_, layer_);
				}
				//[rbool_]の確率で岸(地形)にノイズを発生させる
				template<typename Matrix_>
				constexpr void rnoiseShoreBothBool(Matrix_ & matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {
					dtl::utility::layer::normal::rnoiseShoreBool(matrix_, layer_, rbool_);
					dtl::utility::layer::normal::noiseShoreBool(matrix_, layer_, rbool_);
				}
				template<typename Matrix_>
				constexpr void rnoiseShoreBothBool(Matrix_ & matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const double rbool1_, const double rbool2_) noexcept {
					dtl::utility::layer::normal::rnoiseShoreBool(matrix_, layer_, rbool1_);
					dtl::utility::layer::normal::noiseShoreBool(matrix_, layer_, rbool2_);
				}

			} //namespace
		}
	}
}

#endif //Included Dungeon Template Library