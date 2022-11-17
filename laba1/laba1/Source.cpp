#include "My_List.h"

/*��� ��������� ���� input.txt, � ������� �������� ����� �����. ������� ������ �� ��������
�������. ����� ��� ����������������� ���������������������, ������� ��������� ��������
���� ����������������������. ���������� ������������������ �������� � ��������� ����
output.txt. ���� ������� ���������������������� ���, �� ������ ������������������ � ����
�������� ��������������� ���������.*/

void print_txt(LIST& list, bool flag)
{
	std::ofstream print("output.txt");
	ptrNODE p = list.get_head()->next;
	if (list.empty())
		print << "no elem\n";
	while (p)
	{
		print << p->info << ' ';
		p = p->next;
	}
	if (!flag)
		print << "\nno alternation\n";
	print.close();
}

bool task(LIST& list)
{
	ptrNODE p = list.get_head() ->next;
	bool flag = false;
	while (p->next ->next)
	{
		if ((p->info) * (p->next->info) < 0 && (p->next->info) * (p->next->next->info) > 0)
		{
				list.del_after(p);
				flag = true;
		}
		p = p->next;
	}
	if ((p->info) * (p->next->info) < 0)
	{
		list.del_after(p);
		flag = true; 
	}
	return flag;
}

void main()
{
	bool cont = true;
	do
	{
		LIST list;
		std::ifstream file("input.txt");
		if (file)
		{
			int mode;
			std::cout << "Enter mode\n 1)stack\n 2)queue\n 3)order\n";
			std::cin >> mode;
			switch (mode)
			{
			case 1:
			{
				list.create_by_stack(file);
				break;
			}
			case 2:
			{
				list.create_by_queue(file);
				break;
			}
			case 3:
				list.create_by_order(file);
				break;
			default:
			{
				std::cout << "Wrong enter. Create by default queue\n";
				list.create_by_queue(file);
				break;
			}
			}
			file.close();
			list.print();
			std::cout << "\n";
			print_txt(list, task(list));
			list.print();
		}
		std::cout << "continue? (1 - Yes, 0 - No): ";
		std::cin >> cont;
	} while (cont);

	std::cin.ignore();
	std::cin.get();
}