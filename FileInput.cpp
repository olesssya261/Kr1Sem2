#include "FileInput.h"//����������� HeaderFile � ������ ������ �� �����
#include <fstream>//���������� ����� � ������ �� �����
#include <iostream>//���������� ����� � ������
#include "CheckExeption.h"//����������� HeaderFile � ���������������� ������� ������ �����
#include "Checks.h"//����������� HeaderFile � ���������� ������ ����������������� �����
#include <filesystem>//����������� ���������� ��� �������� ��������� �����

std::vector<Apartment> FileDataInput()//������� ����� ������ ������� �� �����
{
	std::vector<Apartment> apartments;//���������� ������� �������� apartment
	std::string fileName;//���������� ���������� ����� �����
	std::ifstream file;//�������� ������ ��� ������ �� �����
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	while (true)
	{
		std::cout << "������� ��� ����� (� ���������� .txt): " << std::endl;
		std::cin >> fileName;//���� ���� � �����
		try
		{
			if (fileName.find(".txt") == std::string::npos)//����� � ����� ����� ����� .txt ���� ��������� �� ��������� �� ������� ������ ���������� ��������� ������
			{
				std::cout << "�� ������ ���������� � �����.���������� �������. " << std::endl;
				continue;
			}
			if (std::filesystem::is_regular_file(fileName))//�������� �� ��������� �����
			{
				std::cout << "���� ������ �������. " << std::endl;
				file.open(fileName);//�������� ����� ��� ������
			}
			
		}
		catch (const std::exception&)//��������� ������ ��� ������ �� �����
		{
			std::cout << " ��������� ������ ��� �������� �����.��������� �������:" << std::endl;
			continue;

		}
		std::string adress;//���������� ������
		int floor;//���������� �����
		int roomCount;//���������� ���-�� ������
		double roomArea;//���������� �������
		try {
			int objectCount = CheckLineI(file);//���������� ���������� ��������
			for (int i = 0; i < objectCount; i++) {
				adress = CheckLineS(file);//���� ������
				floor = CheckLineI(file);//���� �����
				roomCount = CheckLineI(file);//���� ���-�� ������
				roomArea = CheckLineD(file);//���� �������
				Apartment apartment(adress, floor, roomCount, roomArea);//�������� ������� ���� apartment
				apartments.push_back(apartment);//���������� ������� � ����� �������
			}

		}
		catch (const std::exception) {//��������� ������
			std::cout << " ��������� ������ ��� ������ ����������. ��������� �������:" << std::endl;
			file.close();
			continue;
		}
		catch (const CheckException err) {//��������� ������ ����������������� �����
			std::cout << err.GetMessage() << std::endl;//����� ��������� �� ������
			file.close();//�������� ������
			continue;
		}
		file.close();//�������� ������
		return  apartments;
	}
}
