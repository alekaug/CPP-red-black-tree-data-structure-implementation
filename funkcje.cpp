/** @file */

///Drzewa Czerwono-Czarne
///Implementacje funkcji

#include <iostream>
#include <string>
#include <fstream>
#include "struktury.h"
using namespace std;

TreeNode* GetParent(TreeNode* node)
{
	return node == nullptr ? nullptr : node->parent;
}
TreeNode* GetSibling(TreeNode* node)
{
	TreeNode* parent = GetParent(node);
	if (!parent)
		return nullptr;
	
	if (node == parent->right)
		return parent->left;
	else
		return parent->right;
}
void ChangeToColor(TreeNode* node, Color color)
{
	if (node)
		node->_Color = color;
}
void rotate_left(TreeNode*& node)
{
	//Je¿eli wêze³ nie ma prawego poddrzewa, rotacja w lewo nie dojdzie do skutku.
	if (!node->right)
	{
		cerr << "\n\nNie mozna wykonac rotacji w prawo! Brak wezla zastepczego z prawej strony.\n";
		return;
	}

	//p - wêze³ po prawo od wêz³a z
	auto p = node->right;
	//tmp - wêze³ przenoszony z wêz³a p na lewe poddrzewo wêz³a g - g³ównego
	auto tmp = p->left;

	//OBRACANIE W LEWO
	if (node->parent)
	{
		p->parent = node->parent;
		if (node->parent->right == node)
			node->parent->right = p;
		else
			node->parent->left = p;
	}
	else
	{
		p->parent = nullptr;
		node->parent = p;
	}
	p->left = node;
	node->parent = p;
	if (tmp)
	{
		tmp->parent = node;
		node->right = tmp;
	}
	else
		node->right = nullptr;
	node = p;
}
void rotate_right(TreeNode*& node)
{
	//Je¿eli wêze³ nie ma lewego poddrzewa, rotacja w prawo nie dojdzie do skutku.
	if (!node->left)
	{
		cerr << "\n\nNie mozna wykonac rotacji w prawo! Brak wezla zastepczego z lewej strony.\n";
		return;
	}

	//p - wêze³ po lewo od wêz³a node
	auto p = node->left;
	//tmp - wêze³ przenoszony z wêz³a p na lewe poddrzewo wêz³a node
	auto tmp = p->right;

	//OBRACANIE W PRAWO
	if (node->parent)
	{
		p->parent = node->parent;
		if (node->parent->right == node)
			node->parent->right = p;
		else
			node->parent->left = p;
	}
	else
	{
		p->parent = nullptr;
		node->parent = p;
	}
	p->right = node;
	node->parent = p;
	if (tmp)
	{
		tmp->parent = node;
		node->left = tmp;
	}
	else
		node->left = nullptr;
	node = p;
}

void Add_Recovery(TreeNode* z)
{
	while (1)
	{
		if (!z->parent)
		{
			ChangeToColor(z, Color::black);
			return;
		}

		if (z->parent and z->parent->_Color != Color::black)
		{
			TreeNode* father = GetParent(z);
			TreeNode* grandfather = GetParent(GetParent(z));
			TreeNode* uncle = GetSibling(GetParent(z));

			if (uncle and uncle->_Color == Color::red)
			{
				ChangeToColor(father, Color::black);
				ChangeToColor(uncle, Color::black);
				ChangeToColor(grandfather, Color::red);
				z = grandfather;
			}
			else if ((uncle and uncle->_Color == Color::black) or !uncle)
			{
				if (father == grandfather->left and z == father->left)
				{
					rotate_right(grandfather);
					grandfather = father->right;
					ChangeToColor(father, grandfather->_Color);
					if (grandfather->_Color == Color::red)
						ChangeToColor(grandfather, Color::black);
					else
						ChangeToColor(grandfather, Color::red);
				}
				else if (father == grandfather->left and z == father->right)
				{
					rotate_left(father);
					father = z->left;
					rotate_right(grandfather);
					grandfather = z->right;
					ChangeToColor(z, grandfather->_Color);
					if (grandfather->_Color == Color::red)
						ChangeToColor(grandfather, Color::black);
					else
						ChangeToColor(grandfather, Color::red);
				}
				else if (father == grandfather->right and z == father->right)
				{
					rotate_left(grandfather);
					grandfather = father->left;
					ChangeToColor(father, grandfather->_Color);
					if (grandfather->_Color == Color::red)
						ChangeToColor(grandfather, Color::black);
					else
						ChangeToColor(grandfather, Color::red);

				}
				else if (father == grandfather->right and z == father->left)
				{
					rotate_right(father);
					father = z->right;
					rotate_left(grandfather);
					grandfather = z->left;
					ChangeToColor(z, grandfather->_Color);
					if (grandfather->_Color == Color::red)
						ChangeToColor(grandfather, Color::black);
					else
						ChangeToColor(grandfather, Color::red);
				}
				return;
			}
		}
		else
			return;
	}

}
void Add(TreeNode*& root, const T& value)
{
	//Je¿eli drzewo nie ma korzenia, zostaje on utworzony.
	if (!root)
	{
		root = new TreeNode{ Color::black, value, nullptr, nullptr, nullptr };
		Add_Recovery(root);
	}
	else
	{
		//p - wskaŸnik pomocniczy, przesuwaj¹cy siê po wêz³ach drzewa.
		auto p = root;
		//parent - wskaŸnik na wêze³ znajduj¹cy siê powy¿ej wêz³a wstawianego / "rodzic"
		auto parent = p;

		//DODAWANIE DO DRZEWA WÊZ£A O PODANEJ WARTOŒCI, PRZYWRACANIE W£AŒCIWOŒCI DRZEWA CZERWONO-CZARNEGO:
		while (p)
		{
			parent = p;
			if (value < p->value)
			{
				if (p->left)
					p = p->left;
				else
				{
					p->left = new TreeNode{ Color::red, value, nullptr, nullptr, parent };
					Add_Recovery(p->left);
					break;
				}
			}
			else if (value >= p->value)
			{
				if (p->right)
					p = p->right;
				else
				{
					p->right = new TreeNode{ Color::red, value, nullptr, nullptr, parent };
					Add_Recovery(p->right);
					break;
				}
			}
		}
		//USTAWIANIE NOWEGO KORZENIA:
		//Pêtla iteracyjna ustawiaj¹ca nowy korzeñ, je¿eli nast¹pi³y rotacje w lewo/prawo.
		while (p->parent)
			p = p->parent;
		root = p;
		//Po ka¿dym wykonaniu
		root->_Color = Color::black;
	}
}
TreeNode* Find(TreeNode* root, const T& value)
{
	while (root)
	{
		if (root->value == value)
			return root;
		value < root->value ? root = root->left : root = root->right;
	}
	return nullptr;
}
TreeNode* Successor(TreeNode* node)
{
	if (!node)
		return nullptr;
	if (node->right)
	{
		node = node->right;
		while (node->left)
			node = node->left;
		return node;
	}
	else if (node->left)
	{
		node = node->left;
		while (node->right)
			node = node->right;
		return node;
	}
	else 
		return nullptr;
}
void StartCase(TreeNode* node, bool& isCase2)
{
	//CASE 2
	if ((node->_Color == Color::black and node->left and node->left->_Color == Color::red)
		or (node->_Color == Color::red and node->left and node->left->_Color == Color::black))
	{
		node->value = node->left->value;
		delete node->left;
		node->left = nullptr;
		isCase2 = true;
		return;
	}
	else if ((node->_Color == Color::black and node->right and node->right->_Color == Color::red)
		or (node->_Color == Color::red and node->right and node->right->_Color == Color::black))
	{
		node->value = node->right->value;
		delete node->right;
		node->right = nullptr;
		isCase2 = true;
		return;
	}
	else if (node->_Color == Color::red and !node->left and !node->right)
	{
		if (node == node->parent->left)
			node->parent->left = nullptr;
		else
			node->parent->right = nullptr;

		delete node;
		node = nullptr;
		isCase2 = true;
		return;
	}

	//CASE 3.1
	if (node and node->left and node->left->_Color == Color::black)
	{
		node->value = node->left->value;
		delete node->left;
		node->left = nullptr;
	}
	else if (node and !node->left and !node->right)
	{
		if (node and node == node->parent->left)
			node->parent->left = nullptr;
		else
			node->parent->right = nullptr;
		delete node;
		node = nullptr;
	}
	else if (node->right and node->right->_Color == Color::black)
	{
		node->value = node->right->value;
		delete node->right;
		node->right = nullptr;
	}
	return;
}
void Delete_Recovery(TreeNode*& node)
{
	bool isCase2 = false;
	TreeNode* sibling = GetSibling(node);
	TreeNode* parent = GetParent(node);
		
	StartCase(node, isCase2);
	if (isCase2)
		return;

	while (1)
	{
		if (!parent)
			return;

		if (sibling == nullptr)
		{
			node = parent;
			parent = GetParent(node);
			sibling = GetSibling(node);
			continue;
		}
		else
		{
			if (sibling->_Color == Color::red)
			{
				parent->_Color = Color::red;
				sibling->_Color = Color::black;
				if (sibling == parent->left)
				{
					rotate_right(parent);
					parent = sibling->right;
					sibling = parent->left;
				}
				else
				{
					rotate_left(parent);
					parent = sibling->left;
					sibling = parent->right;
				}
				continue;
			}
			else
			{
				if (sibling->left and sibling->left->_Color == Color::red or sibling->right and sibling->right->_Color == Color::red)
				{
					if (sibling->left != nullptr and sibling->left->_Color == Color::red)
					{
						if (sibling == parent->left)
						{
							sibling->left->_Color = sibling->_Color;
							sibling->_Color = parent->_Color;
							rotate_right(parent);
							parent = sibling->right;
						}
						else
						{
							sibling->left->_Color = parent->_Color;
							rotate_right(sibling);
							rotate_left(parent);
							parent = parent->left;
						}
					}
					else
					{
						if (sibling == parent->left) {
							sibling->right->_Color = parent->_Color;
							rotate_left(sibling);
							sibling = parent->left;
							rotate_right(parent);
							parent = parent->right;
							sibling = parent->left;
						}
						else
						{
							sibling->right->_Color = sibling->_Color;
							sibling->_Color = parent->_Color;
							rotate_left(parent);
							parent = parent->left;
						}
					}
					parent->_Color = Color::black;
				}
				else
				{
					sibling->_Color = Color::red;
					if (parent->_Color == Color::black)
					{
						node = parent;
						parent = GetParent(node);
						sibling = GetSibling(node);
						continue;
					}
					else
						parent->_Color = Color::black;
				}
			}
		}
		return;
	}
}
void Delete(TreeNode*& root, const T& value)
{
	TreeNode* DeleteNode = Find(root, value);
	if (DeleteNode)
	{
		TreeNode* successor = Successor(DeleteNode);
		if (successor)
		{
			DeleteNode->value = successor->value;
			Delete_Recovery(successor);
			return;
		}
		Delete_Recovery(DeleteNode);
		return;
	}
}
void Print(TreeNode* root)
{
	if (root)
	{
		Print(root->left);
		std::cout << root->value << ' ';
		Print(root->right);
	}
}
void Graph(TreeNode* root, int indent = 0)
{
	if (root)
	{
		
		Graph(root->right, indent + 9);
		for (int i = 0; i < indent; ++i)
			cout << " ";
		if(root->_Color == Color::black)
			cout << '[' << root->value << ']' << "\n";
		else
			cout << '(' << root->value << ')' <<"\n";
		Graph(root->left, indent + 9);
	}
}
void Deallocate(TreeNode*& root)
{
	if (root)
	{
		Deallocate(root->right);
		Deallocate(root->left);
		delete root;
		root = nullptr;
	}
}
void PrintToFile(TreeNode* root, ofstream& file)
{
	if (root)
	{
		PrintToFile(root->left, file);
		file << root->value << ' ';
		PrintToFile(root->right, file);
	}
}
void GraphToFile(TreeNode* root, ofstream& file, int indent = 0)
{
	if (root)
	{
		GraphToFile(root->right, file, indent + 9);
		for (int i = 0; i < indent; ++i)
			file << " ";
		if (root->_Color == Color::black)
			file << '[' << root->value << ']' << "\n";
		else
			file << '(' << root->value << ')' << "\n";
		GraphToFile(root->left, file, indent + 9);
	}
}
size_t lookForSign(const std::string& line, char searched)
{
	size_t found = line.find(searched);
	if (found == std::string::npos)
		return line.length();
	else if (searched == '%' and found>0)
		return found - 1;
	else
		return found;
}
void FilePrint(TreeNode*& root, const std::string& file_name, const bool& toOverwrite)
{
	ofstream file;
	if (toOverwrite)
	{
		file.open(file_name);
		if (file.is_open())
		{
			PrintToFile(root, file);
			file << "\n"; 
			file.close();
		}
		else
			cerr << "\nFile couldn't be written to.\n";
	}
	else
	{
		file.open(file_name, std::ios_base::app);
		if (file.is_open())
		{
			PrintToFile(root, file);
			file << "\n";
			file.close();
		}
		else
			cerr << "\nFile couldn't be written to.\n";
	}
	return;
}
void FileGraph(TreeNode*& root, const std::string& file_name, const bool& toOverwrite)
{
	ofstream file;
	if (toOverwrite)
	{
		file.open(file_name);
		if (file.is_open())
		{
			GraphToFile(root, file);
			file << "\n";
			file.close();
		}
		else
			cerr << "\nFile couldn't be written to.\n";
	}
	else
	{
		file.open(file_name, std::ios_base::app);
		if (file.is_open())
		{
			GraphToFile(root, file);
			file << "\n";
			file.close();
		}
		else
			cerr << "\nFile couldn't be written to.\n";
	}
	return;
}
void ReadFromFile(const std::string& file_name)
{
	string line = "";
	ifstream file(file_name);
	if (file.is_open())
	{
		TreeNode* TREE{};
		while (file)
		{
			while (getline(file, line))
			{
				string command = line.substr(0, line.find(' '));
				line = line.substr(0, lookForSign(line, '%'));
				if (command == "%" or line == "")
					continue;
				if (command == "add")
				{
					line = line.substr(line.find(' ') + 1, line.length());
					string value = "";
					for (char x : line)
					{
						if (x == ' ')
						{
							if (value != "")
							{
								try { T check = (T)stod(value); }
								catch (logic_error) { value = ""; }
								if (value != "")
								{
									Add(TREE, (T)stod(value));
									value = "";
								}
							}
						}
						else
						{
							value = value + x;
						}
					}
					if (value != "")
					{
						try { T check = (T)stod(value); }
						catch (logic_error) { value = ""; }
						if (value != "")
							Add(TREE, (T)stod(value));
					}
					continue;
				}
				if (command == "graph")
				{
					if (line == command)
					{
						Graph(TREE, 0);
						cout << endl;
						continue;
					}
					else
					{
						line = line.substr(line.find(' ') + 1, line.length());
						bool toOverwrite = true;
						string value = "";
						for (char x : line)
						{
							if (x == ' ')
							{
								if (value == "+")
									toOverwrite = false;
								value = "";
							}
							else
							{
								value = value + x;
							}
						}
						if(value!="")
							FileGraph(TREE, value, toOverwrite);
						continue;
					}
				}
				if (command == "remove")
				{
					line = line.substr(line.find(' ') + 1, line.length());
					string value = "";
					for (char x : line)
					{
						if (x == ' ')
						{
							if (value != "")
							{
								try { T check = (T)stod(value); }
								catch (logic_error) { value = ""; }
								if (value != "")
								{
									Delete(TREE, (T)stod(value));
									value = "";
								}
							}
						}
						else
						{
							value = value + x;
						}
					}
					if (value != "")
					{
						try { T check = (T)stod(value); }
						catch (logic_error) { value = ""; }
						if (value != "")
							Delete(TREE, (T)stod(value));
					}
					continue;
				}
				if (command == "print")
				{
					if (line == command)
					{
						Print(TREE);
						cout << endl <<endl;
					}
					else
					{
						line = line.substr(line.find(' ') + 1, line.length());
						bool toOverwrite = true;
						string value = "";
						for (auto x : line)
						{
							if (x == ' ')
							{
								if (value == "+")
									toOverwrite = false;
								value = "";
							}
							else
							{
								value = value + x;
							}
						}
						FilePrint(TREE, value, toOverwrite);
					}
					continue;
				}
			}
			file.close();
			Deallocate(TREE);
			cout << endl;
		}
	}
	else
		cerr << "\nCouldn't read file.\n";
}