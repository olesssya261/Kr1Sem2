#include "FileOutput.h"//����������� HeaderFile � ������� ������ � ����
#include <fstream>//���������� ����� � ������ �� �����
#include <iostream>//���������� ����� � ������
#include "Checks.h"//����������� HeaderFile � ���������� ������ ����������������� �����
#include "MainMenu.h"//����������� HeaderFile � Enum menu
#include "PersonalInterface.h"//����������� HeaderFile � ���������������� �����������
#include <filesystem>//����������� ���������� ��� �������� ��������� �����
class FileWriteException//���������������� ����� ������ ��������� ��������������
{
public:
	FileWriteException(std::string message) : message{ message } {}//����������� ������ 
	std::string getMessage() const { return message; }//������� ��������� �� ������
private:
	std::string message;//���� �������� ��������� �� ������
};

void WriteApartments(std::vector<Apartment> apartments,std::string fileName)//������� ������ ������ ������� � ����
{
	std::ofstream  out;//�������� ������ ������ � ����
	out.exceptions(std::ofstream::badbit | std::ofstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	try {
		out.open(fileName);//�������� ����� ��� ������
		//������ ������
		out << apartments.size() << std::endl;//������ ���-�� �������� � �������
		for (auto i = apartments.begin(); i < apartments.end(); ++i)//������� ������� ������� ��� ������ ���������
		{
			out << i->GetAdress() << std::endl;//������ � ���� ������
			out << i->GetFloor() << std::endl;//������ � ���� �����
			out << i->GetRoomCount() << std::endl;//������ � ���� ���-�� ������
			out << i->GetArea() << std::endl;//������ � ���� ������� ��������
		}
		out.close();//�������� ������
		std::cout << "������ ������� ���������" << std::endl;
	}
	catch(const std::exception&)//��������� ������
	{
		throw FileWriteException("���������� �������� ������ � ����.��������� �������.");//������ ���������������� ������ ��������� ������
	}
}
void FileOutput(std::vector<Apartment> apartments)
{
	std::ifstream out2;//�������� ������ ������ �� �����
	std::string fileName;//���������� ����� ��� ���� �����
	out2.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	int userChoice = 0;//���������� ����������������� �����
	while (true) {
		std::cout << "������� ��� ����� (� ���������� .txt): ";
		std::cin >> fileName;//���� ���� � �����
		try {
			if(fileName.find(".txt") == std::string::npos)//����� � ����� ����� ����� .txt ���� ��������� �� ��������� �� ������� ������ ���������� ��������� ������
			{
				std::cout << "�� ������ ���������� � �����. ���������� �������. "<<std::endl;
				continue;
			}
			try
			{
				if (std::filesystem::is_regular_file(fileName))//�������� �� ��������� �����
				{
					std::cout << "���� � ����� ������ ��� ����������" << std::endl;
				}
			}
			catch (const std::exception&)
			{
				throw FileWriteException("���������� �������� ������ � ����. ��������� �������.");//������ ���������������� ������ ��������� ������

			}
			out2.open(fileName);//������� �������� �����
			ShowOutputChoise();//������� ������ �� ������� ������ �����
			userChoice = GetChoise();//���� ����������������� ������
			if (userChoice == Yes) {
				
				out2.close();//�������� ������ ������ �� �����
				WriteApartments(apartments, fileName);//������� ������ � ����
			}
			else {
				out2.close();//�������� ������ ������ �� �����
				continue;
			}
			break;
		}
		catch (const std::exception&) {
			try {
				WriteApartments(apartments, fileName);//������� ������ � ����
				break;
			}
			catch ( FileWriteException err) {//��������� ������ �������������� � ������
				std::cout << err.getMessage() << std::endl;//����� ��������� �� ������
			}
		}
		catch (FileWriteException err) {//��������� ������ �������������� � ������
			std::cout << err.getMessage() << std::endl;//����� ��������� �� ������
		}

	}
}
