#include "Tree.h"
#include <Windows.h>

void made_copy(Tree& t,Tree& t_res)
{
	if (t!=nullptr)
	{
		if (t->info >= 0)
		{
			t_res = new NODE(t->info);
			made_copy(t->left, t_res->left);
			made_copy(t->right, t_res->right);
		}
	}
}

Tree task(Tree& t)
{
	Tree tmp = nullptr;
	made_copy(t, tmp);
	return tmp;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream file("numbers.txt");
	int count;
	file >> count;
	Tree root = Build_Balans(file, count);
	std::cout << "»сходное дерево\n";
	Print(root, 0);
	std::cout << "\n-----------------------------------------------\n";
	Tree res = task(root);
	if (res)
	{
		std::cout << " опи€ дерева, котора€ содержит элементы до первого отрицательного по каждому пути\n";
		Print(res, 0);
	}
	else
		std::cout << "Ќевозможно построить дерево,которое содержит элементы до первого отрицательного по каждому пути\n";
	Clear(root);
	std::cin.get();
	return 0;
}