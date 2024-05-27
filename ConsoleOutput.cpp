#include <vector>//���������� ����������� �������
#include "Apartment.h"//����������� HeaderFile � ������� Apartment
#include "ConsoleOutput.h"//����������� HeaderFile � ������� ������ �� �������
#include <iostream>//���������� ����� � ������


void ConsoleOutput(std::vector<Apartment> apartments)
{
	std::cout << "���������� ���������� �������:" << apartments.size() << std::endl;
	std::cout << "������ �������:" << std::endl;
	for (auto i = apartments.begin(); i < apartments.end(); ++i)//������� ������� ������� ��� ������ ��������� https://metanit.com/cpp/tutorial/7.3.php
	{
		std::cout << "��������:" << std::endl;
		std::cout << "	A���� - ";
		i->ShowAdress();//����� ������
		std::cout << "	���� - ";
		i->ShowFloor();//����� �����
		std::cout << "	���������� ������ - ";
		i->ShowRoomCount();//����� ���������� ������
		std::cout << "	������� - ";
		i->ShowArea();//����� �������
	}
}
