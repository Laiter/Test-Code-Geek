#include "draw_folders_tree.h"

namespace laiter {
	void drawFoldersTree(MYSQL *connect, size_t parent_id, size_t lvl, std::ostream& stream, const char* template_query)
	{
		MYSQL_RES *res;											// Дескриптор результирующей таблицы
		MYSQL_ROW row;											// Массив полей текущей строки
		std::string query = template_query + std::to_string(parent_id);
		mysql_query(connect, query.c_str());					// Делаем запрос к таблице
		if (res = mysql_store_result(connect)) {
			while (row = mysql_fetch_row(res)) {
				for (size_t i = 0; i < mysql_num_fields(res); i++) {
					if (i % 2 == 0)
					{
						parent_id = std::atoi(row[i]);			// Записываем id папки
					}
					else
					{
						inputLvlBorder(std::cout, lvl);
						stream << row[i] << std::endl;			// Выводим все имена в запросе
						drawFoldersTree(connect, parent_id,
							lvl + 1, stream, template_query);	// Рекурсивно вызываем вывод дерева для каждой папки 
					}
				}
			}
		}
		else
		{
			std::cerr << "\n" << mysql_error(connect) << "\n";
		}
	}

	void inputLvlBorder(std::ostream& stream, size_t lvl)
	{
		stream << "| ";
		for (size_t i = 0; i < lvl; i++)
		{
			stream << "  | ";
		}
	}

	std::string makeQueryToDrawFoldersTree(const char* table1_id_name, const char* table2_id_parent_id, const char* id, const char* name, const char* parent_id)
	{
		return std::string("SELECT ") + table1_id_name + "." + id + " , " + table1_id_name + "." + name +
			" FROM " + table1_id_name +
			" INNER JOIN " + table2_id_parent_id +
			" ON " + table1_id_name + "." + id + " = " + table2_id_parent_id + "." + id +
			" AND " + table2_id_parent_id + "." + parent_id + " = ";
	} 
} // namespace laiter
