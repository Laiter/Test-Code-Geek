#include <iostream>
#include <mysql.h>
#include "laiter\draw_folders_tree.h"

void main()
{
	MYSQL *connect;				// ���������� ����������
	connect = mysql_init(0);
	char host[] = "localhost";	// ����
	char user[] = "root";		// ������������
	char passwd[] = "1234";		// ������
	char db[] = "folders";		// �������� ���� ������
	int port = 0;				// ����
	if (!connect)
	{														// ���� ���������� �� �������
		std::cerr << "Error: can't create MySQL-descriptor\n";
	}
	if (!mysql_real_connect(connect, host, user, passwd, db, port, 0, 0))
	{														// ��� ����������� ���������� ���������� � ��������
		std::cerr << "Error: can't connect to database\n" 
			<< mysql_error(connect) << "\n";
	}
	else
	{														// ���������� ������� �����������
		std::cerr << "Connected\n";														
	}
	mysql_set_character_set(connect, "utf8");

	laiter::drawFoldersTree(connect);						// ������� ������ ����� �� �����
	
	mysql_close(connect);									// ��������� ���������� � �������� ���� ������
	system("Pause");
}

