## Laboratory work VI


Данная лабораторная работа посвящена изучению фреймворков для тестирования на примере **Catch**

Баранов Артём ИУ8-33
[![Build Status](https://travis-ci.org/Murderdoll/lab08.svg?branch=master)](https://travis-ci.org/Murderdoll/lab08)

```ShellSession
$ open https://github.com/philsquared/Catch
```
## Tasks

- [X] 1. Создать публичный репозиторий с названием **lab08** на сервисе **GitHub**
- [X] 2. Выполнить инструкцию учебного материала
- [X] 3. Ознакомиться со ссылками учебного материала
- [X] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial
Устанавливаем значение переменной окружения
```ShellSession
$ export GITHUB_USERNAME=Murderdoll
```
Проводим первоначальные настройки для соединения с репозиторием шестой лабораторной работы
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab05 lab07 # Клонируем репозиторий lab05 в каталог lab07
$ cd lab07 # Переходим в каталог lab07
$ git remote remove origin # отключаемся от ветки из lab05
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab07 # Переходим в ветку репозитория для шестой лабораторной
```

```ShellSession
$ mkdir tests #Создаем каталог tests
$ wget https://github.com/philsquared/Catch/releases/download/v1.9.3/catch.hpp -O tests/catch.hpp #Устанавливаем библиотеку для модульного тестирования на языке С++ catch.hpp
# Подключаем к main.cpp catch.hpp
$ cat > tests/main.cpp <<EOF
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
EOF
```
Редактируем CMakeLists.txt
```ShellSession
$ sed -i '' '/option(BUILD_EXAMPLES "Build examples" OFF)/a\ # Добавляем новую опцию в CMakeLists.txt
option(BUILD_TESTS "Build tests" OFF)
' CMakeLists.txt
# Делаем ряд дополнительных настроек
$ cat >> CMakeLists.txt <<EOF

if(BUILD_TESTS)
	enable_testing()
	file(GLOB \${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
	add_executable(check \${\${PROJECT_NAME}_TEST_SOURCES})
	target_link_libraries(check \${PROJECT_NAME} \${DEPENDS_LIBRARIES})
	add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes")
endif()
EOF  
```
Изменяем test1.cpp
```ShellSession
#Вносим изменения в test1.cpp
$ cat >> tests/test1.cpp <<EOF
#include "catch.hpp"
#include <print.hpp>

TEST_CASE("output values should match input values", "[file]") {
  std::string text = "hello";
  std::ofstream out("file.txt");

  print(text, out);
  out.close();

  std::string result;
  std::ifstream in("file.txt");
  in >> result;

  REQUIRE(result == text);
}
EOF
```
Работа с CMake
```ShellSession
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install -DBUILD_TESTS=ON
#-H. устанавливаем каталог в который сгенерируется файл CMakeLists.txt
#-B_build указывает директорию для собираемых файлов
#-D - аналог команды set
$ cmake --build _build
$ cmake --build _build --target test # Устанавливаем цели для обработки и создаем бинарное дерево проекта
```
Работа с Travis
```ShellSession
$ sed -i '' 's/lab05/lab07/g' README.md # Меняем содержимое файла README.md
$ sed -i '' 's/\(DCMAKE_INSTALL_PREFIX=_install\)/\1 -DBUILD_TESTS=ON/' .travis.yml # Меняем содержимое файла .travis.yml
#Вносим изменения в файле .travis.yml
$ sed -i '' '/cmake --build _build --target install/a\
- cmake --build _build --target test
' .travis.yml
```
Отображаем предупреждения или ошибки в файле .travis.yml
```ShellSession
$ travis lint # Проверяем файл .travis.yml на ошибки
```
Подготавливаем содержимое к отправке на удаленный репозиторий
```ShellSession
$ git add . # включаем все файлы под версионный контроль
$ git commit -m"added tests" # Делаем коммит
$ git push origin master #Выгружаем локальную репозиторий в удаленный репозиторий шестой лабораторной
```
Работа с Travis
```ShellSession
$ travis login --auto #Авторизуемся своим GITHUB аккаунтом
$ travis enable #Включаем репозиторий в Travis
```
Завершение
```ShellSession
$ mkdir artifacts #Создаем каталог artifacts
$ screencapture -T 20 artifacts/screenshot.jpg #Делаем снимок экрана и помещаем его в каталог artifacts
<Command>-T
$ open https://github.com/${GITHUB_USERNAME}/lab07 #Открываем репозиторий шестой лабораторной на GitHub
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=06
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [Boost.Tests](http://www.boost.org/doc/libs/1_63_0/libs/test/doc/html/)
- [Google Test](https://github.com/google/googletest)

```
Copyright (c) 2017 Братья Вершинины
```
