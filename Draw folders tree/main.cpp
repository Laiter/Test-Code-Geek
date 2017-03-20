#include <iostream>
#include <mysql.h>
#include "laiter\draw_folders_tree.h"

void main()
{
	MYSQL *connect;				// Дескриптор соединения
	connect = mysql_init(0);
	char host[] = "localhost";	// хост
	char user[] = "root";		// пользователь
	char passwd[] = "1234";		// пароль
	char db[] = "folders";		// название базы данных
	int port = 0;				// порт
	if (!connect)
	{														// Если дескриптор не получен
		std::cerr << "Error: can't create MySQL-descriptor\n";
	}
	if (!mysql_real_connect(connect, host, user, passwd, db, port, 0, 0))
	{														// Нет возможности установить соединение с сервером
		std::cerr << "Error: can't connect to database\n" 
			<< mysql_error(connect) << "\n";
	}
	else
	{														// Соединение успешно установлено
		std::cerr << "Connected\n";														
	}
	mysql_set_character_set(connect, "utf8");

	laiter::drawFoldersTree(connect);						// Выводим дерево папок на экран
	
	mysql_close(connect);									// Закрываем соединение с сервером базы данных
	system("Pause");
}

