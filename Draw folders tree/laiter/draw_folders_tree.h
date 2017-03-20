#ifndef DRAW_FOLDERS_TREE_H
#define DRAW_FOLDERS_TREE_H
#include <iostream>
#include <string>
#include <mysql.h>
namespace laiter {
	// �������� ������� ������� ��� drawFoldersTree()
	std::string makeQueryToDrawFoldersTree(const char* table1_id_name = "t1", const char* table2_id_parent_id = "t2",
		const char* id = "id", const char* name = "name", const char* parent_id = "parent_id");
	// ���� ������� � ����� ��� ��������������� ��������
	void inputLvlBorder(std::ostream& stream, size_t lvl = 1);
	// ���� ����� ����� � ����� 
	// MYSQL *connect - ���������� ����������
	// size_t parent_id = 0 - �������� �����
	// size_t lvl = 0 - ������� � ��������, �������� �� ����� ������ � inputLvlBorder(... lvl)
	// std::ostream& stream = std::cout - ����� ostream, ����� �������� � ������� ��� ����� ������ ������ ������
	// const char* template_query = makeQueryToDrawFoldersTree().c_str()) - ��������� ������, �� ��������� ������������
	// ������ ��� ��������� ������� "SELECT t1.id, t1.name FROM t1 INNER JOIN t2 ON t1.id = t2.id AND t2.parent_id = "
	// Example:
	//	// Ex1: default
	//  // laiter::drawFoldersTree(connect);
	//  // Ex2: 
	//  // char my_template_query[] = "SELECT t1.id, t1.name FROM t1 INNER JOIN t2 ON t1.id = t2.id AND t2.parent_id = ";
	//  // laiter::drawFoldersTree(connect, 1, 0, std::cout, my_template_query);
	//  // // ����� �������� � ������� ����� ����� � id = 1, ���������� �������� �� ���� ����, � ����� �����������
	//  // // ������ ������� �� ������ my_template_query
	void drawFoldersTree(MYSQL *connect, size_t parent_id = 0, size_t lvl = 0, std::ostream& stream = std::cout,
		const char* template_query = makeQueryToDrawFoldersTree().c_str());
} // namespace laiter
#endif // !DRAW_FOLDERS_TREE_H

