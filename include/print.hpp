/*!
	\file
	\brief Заголовочный файл print.hpp
	Декларация
*/
#include <string>
#include <fstream>
#include <iostream>

/*!
Функция print (1)
\param[in] text переменная, для записи текста
\param[in] out переменная класса ostream для вывода
*/
void print(const std::string& text, std::ostream& out = std::cout);
/*!
Функция print (2)
\param[in] text переменная, для записи текста
\param[in]  out переменная ostream для вывода
*/
void print(const std::string& text, std::ofstream& out);
