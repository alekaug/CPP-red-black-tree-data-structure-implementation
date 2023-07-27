/** @file Drzewo Czerwono-Czarne.
@ © Aleksander Augustyniak
*/


#pragma once
#include <string>
#include "struktury.h"


/** \brief Funkcja dodaj¹ca do drzewa wêze³ o podanej wartoœci.	
@param root wskaŸnik na korzeñ drzewa.
@param T wartoœæ.
*/
void Add(TreeNode*& root, const T& value);

/** \brief Funkcja przywracaj¹ca w³asnoœci drzewa Czerwono-Czarnego po wykonaniu operacji dodawania nowego wêz³a do drzewa.
@param z wskaŸnik na wêze³ drzewa.
*/
void Add_Recovery(TreeNode* z);

/** \brief Lokalna zmiana struktury poddrzewa (w lewo).
@param node wskaŸnik na wêze³ drzewa.
@warning prawe poddrzewo wêz³a musi istnieæ!
*/
void rotate_left(TreeNode*& node);

/** \brief Lokalna zmiana struktury poddrzewa (w lewo).
@param node wskaŸnik na wêze³ drzewa.
@warning lewe poddrzewo wêz³a musi istnieæ!
*/
void rotate_right(TreeNode*& node);

/** \brief Funkcja szukaj¹ca w drzewie wêz³a o podanej wartoœci. Je¿eli wêze³ zostanie odnaleziony funkcja zwraca wskaŸnik na niego - w przeciwnym wypadku zwracany jest nullptr.
@param root wskaŸnik na korzeñ drzewa.
@param value wartosc.
@return wêze³ o podanej wartoœci lub nullptr.
*/
TreeNode* Find(TreeNode* root, const T& value);

/** \brief Funkcja obejmuj¹ca przestawienie odpowiednich wskaŸników i dealokowanie odpowiedniej pamiêci - pamiêci wêz³a y.
@param node wskaŸnik na wêze³ drzewa.
@param isCase2 sprawdzenie, czy istnieje potrzeba dalszego przywracania w³asnoœci drzewa czerwono-czarnego.
*/
void StartCase(TreeNode* node, bool& isCase2);

/** \brief Funkcja odnajduj¹ca nastêpcê danego wêz³a. Je¿eli wêze³ zostanie odnaleziony, funkcja zwraca wskaŸnik na niego, w przeciwnym wypadku zwracany jest nullptr.
@param node wskaŸnik na wêze³ drzewa.
@return nastêpca wêz³a.
*/
TreeNode* Successor(TreeNode* node);

/** \brief Funkcja odnajduje wêze³ o podanej wartoœci, usuwa go i dealokuje zaalokowan¹ wczeœniej pamiêæ.
@param root wskaŸnik na korzeñ drzewa.
@param value wartoœæ wêz³a do usuniêcia.
*/
void Delete(TreeNode*& root, const T& value);

/** \brief Funkcja znajduj¹ca i zwracaj¹ca rodzica podanego wêz³a.
@param node wskaŸnik na odpowiedni wêze³ drzewa.
@return rodzic podanego wêz³a lub nullptr.
*/
TreeNode* GetParent(TreeNode* node);

/** \brief Funkcja znajduj¹ca i zwracaj¹ca rodzeñstwo podanego wêz³a.
@param node wskaŸnik na odpowiedni wêze³ drzewa.
@return rodzeñstwo wêz³a lub nullptr.
*/
TreeNode* GetSibling(TreeNode* node);

/** \brief Funkcja zmieniaj¹ca kolor wêz³a na podany.
@param node wskaŸnik na wêze³ drzewa, którego kolor bêdzie zmieniony.
@param color kolor, na jaki wêze³ powinien byæ zmieniony (o ile wêze³ istnieje).
*/
void ChangeToColor(TreeNode* node, Color color);

/** \brief Funkcja ca³kowicie usuwa drzewo i dealokuje zajêt¹ przezeñ pamiêæ.
@param root wskaŸnik na korzeñ drzewa.
*/
void Deallocate(TreeNode*& root);

/** \brief Funkcja przywracaj¹ca w³asnoœci drzewa czerwono-czarnego z widoku usuniêtego wczeœniej wêz³a-nastêpcy wêz³a przeznaczonego do usuniêcia.
@param node wêze³ drzewa czerwono-czarnego.
*/
void Delete_Recovery(TreeNode*& node);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Funkcja przyjmuj¹ca jako parametr korzeñ drzewa. Wypisuje wartoœci wszystkich wêz³ów drzewa w kolejnoœci in-order.
@param root wskaŸnik na korzeñ drzewa.
*/
void Print(TreeNode* root);

/** \brief Funkcja wypisuje wartoœci wszystkich wêz³ów drzewa w kolejnoœci rosn¹cej z uwzglêdnieniem wysokoœci drzewa i kolorów poszczególnych wêz³ów.
@param root wskaŸnik na korzeñ drzewa.
@param indent wciêcie - wyra¿ane w iloœci znaków bia³ych.
*/
void Graph(TreeNode* root, int indent = 0);

/** \brief Funkcja odczytuj¹ca plik "linia po linii" i wykonuj¹ca odpowiednie polecenia.
@param file_name pe³na nazwa pliku.
*/
void ReadFromFile(const std::string& file_name);

/** \brief Funkcja wypisuj¹ca do pliku o podanej nazwie wartoœci wszystich wêz³ów drzewa w porz¹dku rosn¹cym.
@param root wskaŸnik na korzeñ drzewa.
@param file_name pe³na nazwa pliku, do którego maj¹ byæ wypisywane wszystkie wartoœci wêz³ów drzewa.
@param toOverwrite parametr okreœlaj¹cy czy wartoœci w pliku maj¹ byæ nadpisane.
*/
void FilePrint(TreeNode*& root, const std::string& file_name, const bool& toOverwrite);

/** \brief Funkcja wypisuj¹ca do pliku o podanej nazwie wizualizacjê wszystkich wêz³ów znajduj¹cych siê w drzewie, z uwzglêdnieniem ich koloru, np: [33] - wêze³ czarny o wartoœci 33, (13) - wêze³ czerwony o  wartoœci 13.
@param root wskaŸnik na korzeñ drzewa.
@param file_name pe³na nazwa pliku, do którego maj¹ byæ wypisywane wszystkie wartoœci wêz³ów drzewa.
@param toOverwrite parametr okreœlaj¹cy czy wartoœci w pliku maj¹ byæ nadpisane.
*/
void FileGraph(TreeNode*& root, const std::string& file_name, const bool& toOverwrite);

/** \brief G³ówny algorytm s³u¿¹cy wypisywaniu do pliku wszystkich wartoœci wêz³ów drzewa w kolejnoœci rosn¹cej.
@param root wskaŸnik na korzeñ drzewa.
@param file strumieñ plikowy.
*/
void PrintToFile(TreeNode* root, std::ofstream& file);

/** \brief G³ówny algorytm s³u¿¹cy wypisywaniu do pliku wizualizacji pozycji wszystkich wêz³ów w drzewie czerwono-czarnym.
@param root wskaŸnik na korzeñ drzewa.
@param file strumieñ plikowy.
@param indent wciêcie - wyra¿ane w iloœci znaków bia³ych.
*/
void GraphToFile(TreeNode* root, std::ofstream& file, int indent = 0);

/** \brief Funkcja odnajduj¹ca pozycjê podanego znaku w ³añcuchu znakowym. U¿ywana jest w funkcji ReadFromFile, by usun¹æ z pliku wszystkie komentarze, puste linie ora linie, które zawieraj¹ niepoprawnie wprowadzone komendy.
@param line ³añcuch znakowy.
@param searched znak, którego pozycja ma zostaæ odnaleziona.
@return pozycjê odnalezionego znaku (je¿eli nie wyst¹pi³ - zwracana jest d³ugoœæ podanego ³añcucha znakowego).
*/
size_t lookForSign(const std::string& line, char searched);