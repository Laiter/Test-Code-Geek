# Test-Code-Geek
Тестовое задание для Code-Geek

Task: имеется 2 таблицы в MySQL

t1: id, name - имена папок

t2: id, parent_id - дерево папок

Построить и вывести на экран дерево.

t2.parent_id - id родителя (0 - у корневой директории)

c++11, win x64, MySQL Server 5.7, MySQL Connector C++ 1.1.8.

В папке проекта содержится тестовая БД folders.sql, которая может быть применена для демонстрации работы программы.

Необходимо изменить параметры соединения с сервером MySQL (host, user, passwd, db, port), либо использовать другой дескриптор соединения

По умолчанию будет выведено дерево для корневой директории - 0 в поток std::cout

Вывод можно посмотреть в output.txt
