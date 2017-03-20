#ifndef DRAW_FOLDERS_TREE_H
#define DRAW_FOLDERS_TREE_H
#include <iostream>
#include <string>
#include <mysql.h>
namespace laiter {
	// —оздание шаблона запроса дл€ drawFoldersTree()
	std::string makeQueryToDrawFoldersTree(const char* table1_id_name = "t1", const char* table2_id_parent_id = "t2",
		const char* id = "id", const char* name = "name", const char* parent_id = "parent_id");
	// ¬вод границы в поток дл€ форматированни€ иерархии
	void inputLvlBorder(std::ostream& stream, size_t lvl = 1);
	// ¬вод древа папок в поток 
	// MYSQL *connect - ƒескриптор соединени€
	// size_t parent_id = 0 -  орнева€ папка
	// size_t lvl = 0 - ”ровень в иерархии, отвечает за вывод границ в inputLvlBorder(... lvl)
	// std::ostream& stream = std::cout - поток ostream, можно выводить в консоль или любые другие потоки класса
	// const char* template_query = makeQueryToDrawFoldersTree().c_str()) - шаблонный запрос, по умолчанию используетс€
	// запрос дл€ тестового задани€ "SELECT t1.id, t1.name FROM t1 INNER JOIN t2 ON t1.id = t2.id AND t2.parent_id = "
	// Example:
	//	// Ex1: default
	//  // laiter::drawFoldersTree(connect);
	//  // Ex2: 
	//  // char my_template_query[] = "SELECT t1.id, t1.name FROM t1 INNER JOIN t2 ON t1.id = t2.id AND t2.parent_id = ";
	//  // laiter::drawFoldersTree(connect, 1, 0, std::cout, my_template_query);
	//  // // будет выведено в консоль древо папки с id = 1, заполнение начнетс€ от кра€ окна, и будет использован
	//  // // шаблон запроса из строки my_template_query
	void drawFoldersTree(MYSQL *connect, size_t parent_id = 0, size_t lvl = 0, std::ostream& stream = std::cout,
		const char* template_query = makeQueryToDrawFoldersTree().c_str());
} // namespace laiter
#endif // !DRAW_FOLDERS_TREE_H

