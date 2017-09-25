## Laboratory work IV
Баранов Артём ИУ8-33
Данная лабораторная работа посвещена изучению систем автоматизации сборки проекта на примере **CMake**

```ShellSession
$ open https://cmake.org/
```

## Tasks

- [X] 1. Создать публичный репозиторий с названием **lab04** на сервисе **GitHub**
- [X] 2. Ознакомиться со ссылками учебного материала
- [X] 3. Выполнить инструкцию учебного материала
- [X] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=Murderdoll # Устанавливаем значение переменной окружения GITHUB_USERNAME
```

```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab03.git lab04 # Клонируем репозиторий lab03 в каталог lab04
$ cd lab04 # Переходим в каталог lab04
$ git remote remove origin удаляем старый origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab04.git # Добавляем новый удаленный репозиторий под тем же именем origin
```

```ShellSession
$ g++ -I./include -std=c++11 -c sources/print.cpp # С помощью флага -I указываем на заголовочные файлы, подключаем стандарт c++11, указываем путь к выполняемому файлу
$ ls print.o # Просматриваем содержимое файла print.o
$ ar rvs print.a print.o # Создаем архив print.o в print.a
$ file print.a # Узнаем тип файла print.a
$ g++ -I./include -std=c++11 -c examples/example1.cpp # С помощью флага -I указываем на заголовочные файлы, подключаем стандарт c++11, указываем путь к выполняемому файлу
$ ls example1.o # Просматриваем содержимое файла example1.o
$ g++ example1.o print.a -o example1 # Компилируем example1.o и print.a. Задаем имя исполняемого файла (example1.o)
$ ./example1 && echo # Переключаемся на example1 и делаем вывод строки
```

```ShellSession
$ g++ -I./include -std=c++11 -c examples/example2.cpp # С помощью флага -I указываем на заголовочные файлы, подключаем стандарт c++11, указываем путь к выполняемому файлу
$ ls example2.o # Просматриваем содержимое файла example2.o
$ g++ example2.o print.a -o example2 # Компилируем example2.o и print.a. Задаем имя исполняемого файла (example2.o)
$ ./example2 # Переключаемся на example2
$ cat log.txt && echo # Выводим на экран содержимое файла log.txt
```
#Удаляем файлы: example1.o example2.o print.o print.a example1 example2 log.txt
```ShellSession
$ rm -rf example1.o example2.o print.o 
$ rm -rf print.a 
$ rm -rf example1 example2
$ rm -rf log.txt
```
# Создаем CMakeLists.txt и делаем в нём необходимые настройки
```ShellSession
$ cat > CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.0)
project(print)
EOF
```
# Установливаем переменые со списком исходных данный
```ShellSession
$ cat >> CMakeLists.txt <<EOF
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
EOF
```
# Создаем статическую библиотеку с именем print, исполняемый файл print.cpp
```ShellSession
$ cat >> CMakeLists.txt <<EOF
add_library(print STATIC \${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
EOF
```
# Подключение библиотек для поиска заголовков
```ShellSession
$ cat >> CMakeLists.txt <<EOF
include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/include)
EOF
```

```ShellSession
$ cmake -H. -B_build
$ cmake --build _build # Компиляция и сборка проекта
```
# Добавление example1.cpp и example2.cpp как исполняемых файлов
```ShellSession
$ cat >> CMakeLists.txt <<EOF

add_executable(example1 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
EOF
```
## Линковка программы с библиотекой
```ShellSession
$ cat >> CMakeLists.txt <<EOF

target_link_libraries(example1 print)
target_link_libraries(example2 print)
EOF
```

```ShellSession
$ cmake --build _build # Сборка и запись проекта в lab04/_build
$ cmake --build _build --target print # Запускаем сборку, указываем print как цель
$ cmake --build _build --target example1 # Запускаем сборку example1
$ cmake --build _build --target example2 # Запускаем сборку example2
```

```ShellSession
$ ls -la _build/libprint.a # Просматриваем содержимое libprint.a
$ _build/example1 && echo # Запускаем сборку example1 и затем выводим на экран результат
hello
$ _build/example2 # Запускаем сборку example2
$ cat log.txt && echo # Выводим log.txt и 
hello
```

```ShellSession
$ git clone https://github.com/tp-labs/lab04 tmp # Клонируем репозиторий в директорию tmp
$ mv -f tmp/CMakeLists.txt . # Помещаем в tmp CMakeLists.txt
$ rm -rf tmp # Удаляем tmp
```

```ShellSession
$ cat CMakeLists.txt # Выводим содержимое файла на экран
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install # -H. устанавливаем каталог в который сгенерируется файл, -B_build указывает директорию для собираемых файлов, -D - аналог команде set 
$ cmake --build _build --target install # Указываем необходимые для обработки цели, запускаем сборку проекта.
$ tree _install # Визуализируем 
```

```ShellSession
$ git add CMakeLists.txt # Добавляем CMakeLists.txt под версионный контроль
$ git commit -m"added CMakeLists.txt" # делаем коммит
$ git push origin master # Отправляем на удаленный репозиторий
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=04
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [Autotools](http://www.gnu.org/software/automake/manual/html_node/Autotools-Introduction.html)
- [CMake](https://cgold.readthedocs.io/en/latest/index.html)

```
Copyright (c) 2017 Братья Вершинины
```
