/** @file STRUKTURY */

#pragma once

/** @brief Typ wyliczeniowy, opisuj¹cy kolor wêz³a.   */
enum class Color
{
	red,
	black
};

/** @brief Szablon typu zmiennej (domyœlnie: double).   */
typedef double T;

/** @brief Struktura wêz³a drzewa czerwono-czarnego.   */
struct TreeNode
{
	Color _Color{};		///< Kolor typu wyliczeniowego, okreœlaj¹cy kolor wêz³a.    
	T value;			///< Wartoœæ typu domyœlnego T, przechowywana w wêŸle.    
	TreeNode* left{};   ///< WskaŸnik na wêze³ lewego poddrzewa.   
	TreeNode* right{};	///< WskaŸnik na wêze³ prawego poddrzewa.  
	TreeNode* parent{}; ///< WskaŸnik na wêze³-rodzic poddrzewa.   
};
