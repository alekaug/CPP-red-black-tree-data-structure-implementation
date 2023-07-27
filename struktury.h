/** @file STRUKTURY */

#pragma once

/** @brief Typ wyliczeniowy, opisuj�cy kolor w�z�a.   */
enum class Color
{
	red,
	black
};

/** @brief Szablon typu zmiennej (domy�lnie: double).   */
typedef double T;

/** @brief Struktura w�z�a drzewa czerwono-czarnego.   */
struct TreeNode
{
	Color _Color{};		///< Kolor typu wyliczeniowego, okre�laj�cy kolor w�z�a.    
	T value;			///< Warto�� typu domy�lnego T, przechowywana w w�le.    
	TreeNode* left{};   ///< Wska�nik na w�ze� lewego poddrzewa.   
	TreeNode* right{};	///< Wska�nik na w�ze� prawego poddrzewa.  
	TreeNode* parent{}; ///< Wska�nik na w�ze�-rodzic poddrzewa.   
};
