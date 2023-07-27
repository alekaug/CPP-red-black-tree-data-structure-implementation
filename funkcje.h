/** @file Drzewo Czerwono-Czarne.
@ � Aleksander Augustyniak
*/


#pragma once
#include <string>
#include "struktury.h"


/** \brief Funkcja dodaj�ca do drzewa w�ze� o podanej warto�ci.	
@param root wska�nik na korze� drzewa.
@param T warto��.
*/
void Add(TreeNode*& root, const T& value);

/** \brief Funkcja przywracaj�ca w�asno�ci drzewa Czerwono-Czarnego po wykonaniu operacji dodawania nowego w�z�a do drzewa.
@param z wska�nik na w�ze� drzewa.
*/
void Add_Recovery(TreeNode* z);

/** \brief Lokalna zmiana struktury poddrzewa (w lewo).
@param node wska�nik na w�ze� drzewa.
@warning prawe poddrzewo w�z�a musi istnie�!
*/
void rotate_left(TreeNode*& node);

/** \brief Lokalna zmiana struktury poddrzewa (w lewo).
@param node wska�nik na w�ze� drzewa.
@warning lewe poddrzewo w�z�a musi istnie�!
*/
void rotate_right(TreeNode*& node);

/** \brief Funkcja szukaj�ca w drzewie w�z�a o podanej warto�ci. Je�eli w�ze� zostanie odnaleziony funkcja zwraca wska�nik na niego - w przeciwnym wypadku zwracany jest nullptr.
@param root wska�nik na korze� drzewa.
@param value wartosc.
@return w�ze� o podanej warto�ci lub nullptr.
*/
TreeNode* Find(TreeNode* root, const T& value);

/** \brief Funkcja obejmuj�ca przestawienie odpowiednich wska�nik�w i dealokowanie odpowiedniej pami�ci - pami�ci w�z�a y.
@param node wska�nik na w�ze� drzewa.
@param isCase2 sprawdzenie, czy istnieje potrzeba dalszego przywracania w�asno�ci drzewa czerwono-czarnego.
*/
void StartCase(TreeNode* node, bool& isCase2);

/** \brief Funkcja odnajduj�ca nast�pc� danego w�z�a. Je�eli w�ze� zostanie odnaleziony, funkcja zwraca wska�nik na niego, w przeciwnym wypadku zwracany jest nullptr.
@param node wska�nik na w�ze� drzewa.
@return nast�pca w�z�a.
*/
TreeNode* Successor(TreeNode* node);

/** \brief Funkcja odnajduje w�ze� o podanej warto�ci, usuwa go i dealokuje zaalokowan� wcze�niej pami��.
@param root wska�nik na korze� drzewa.
@param value warto�� w�z�a do usuni�cia.
*/
void Delete(TreeNode*& root, const T& value);

/** \brief Funkcja znajduj�ca i zwracaj�ca rodzica podanego w�z�a.
@param node wska�nik na odpowiedni w�ze� drzewa.
@return rodzic podanego w�z�a lub nullptr.
*/
TreeNode* GetParent(TreeNode* node);

/** \brief Funkcja znajduj�ca i zwracaj�ca rodze�stwo podanego w�z�a.
@param node wska�nik na odpowiedni w�ze� drzewa.
@return rodze�stwo w�z�a lub nullptr.
*/
TreeNode* GetSibling(TreeNode* node);

/** \brief Funkcja zmieniaj�ca kolor w�z�a na podany.
@param node wska�nik na w�ze� drzewa, kt�rego kolor b�dzie zmieniony.
@param color kolor, na jaki w�ze� powinien by� zmieniony (o ile w�ze� istnieje).
*/
void ChangeToColor(TreeNode* node, Color color);

/** \brief Funkcja ca�kowicie usuwa drzewo i dealokuje zaj�t� przeze� pami��.
@param root wska�nik na korze� drzewa.
*/
void Deallocate(TreeNode*& root);

/** \brief Funkcja przywracaj�ca w�asno�ci drzewa czerwono-czarnego z widoku usuni�tego wcze�niej w�z�a-nast�pcy w�z�a przeznaczonego do usuni�cia.
@param node w�ze� drzewa czerwono-czarnego.
*/
void Delete_Recovery(TreeNode*& node);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Funkcja przyjmuj�ca jako parametr korze� drzewa. Wypisuje warto�ci wszystkich w�z��w drzewa w kolejno�ci in-order.
@param root wska�nik na korze� drzewa.
*/
void Print(TreeNode* root);

/** \brief Funkcja wypisuje warto�ci wszystkich w�z��w drzewa w kolejno�ci rosn�cej z uwzgl�dnieniem wysoko�ci drzewa i kolor�w poszczeg�lnych w�z��w.
@param root wska�nik na korze� drzewa.
@param indent wci�cie - wyra�ane w ilo�ci znak�w bia�ych.
*/
void Graph(TreeNode* root, int indent = 0);

/** \brief Funkcja odczytuj�ca plik "linia po linii" i wykonuj�ca odpowiednie polecenia.
@param file_name pe�na nazwa pliku.
*/
void ReadFromFile(const std::string& file_name);

/** \brief Funkcja wypisuj�ca do pliku o podanej nazwie warto�ci wszystich w�z��w drzewa w porz�dku rosn�cym.
@param root wska�nik na korze� drzewa.
@param file_name pe�na nazwa pliku, do kt�rego maj� by� wypisywane wszystkie warto�ci w�z��w drzewa.
@param toOverwrite parametr okre�laj�cy czy warto�ci w pliku maj� by� nadpisane.
*/
void FilePrint(TreeNode*& root, const std::string& file_name, const bool& toOverwrite);

/** \brief Funkcja wypisuj�ca do pliku o podanej nazwie wizualizacj� wszystkich w�z��w znajduj�cych si� w drzewie, z uwzgl�dnieniem ich koloru, np: [33] - w�ze� czarny o warto�ci 33, (13) - w�ze� czerwony o  warto�ci 13.
@param root wska�nik na korze� drzewa.
@param file_name pe�na nazwa pliku, do kt�rego maj� by� wypisywane wszystkie warto�ci w�z��w drzewa.
@param toOverwrite parametr okre�laj�cy czy warto�ci w pliku maj� by� nadpisane.
*/
void FileGraph(TreeNode*& root, const std::string& file_name, const bool& toOverwrite);

/** \brief G��wny algorytm s�u��cy wypisywaniu do pliku wszystkich warto�ci w�z��w drzewa w kolejno�ci rosn�cej.
@param root wska�nik na korze� drzewa.
@param file strumie� plikowy.
*/
void PrintToFile(TreeNode* root, std::ofstream& file);

/** \brief G��wny algorytm s�u��cy wypisywaniu do pliku wizualizacji pozycji wszystkich w�z��w w drzewie czerwono-czarnym.
@param root wska�nik na korze� drzewa.
@param file strumie� plikowy.
@param indent wci�cie - wyra�ane w ilo�ci znak�w bia�ych.
*/
void GraphToFile(TreeNode* root, std::ofstream& file, int indent = 0);

/** \brief Funkcja odnajduj�ca pozycj� podanego znaku w �a�cuchu znakowym. U�ywana jest w funkcji ReadFromFile, by usun�� z pliku wszystkie komentarze, puste linie ora linie, kt�re zawieraj� niepoprawnie wprowadzone komendy.
@param line �a�cuch znakowy.
@param searched znak, kt�rego pozycja ma zosta� odnaleziona.
@return pozycj� odnalezionego znaku (je�eli nie wyst�pi� - zwracana jest d�ugo�� podanego �a�cucha znakowego).
*/
size_t lookForSign(const std::string& line, char searched);