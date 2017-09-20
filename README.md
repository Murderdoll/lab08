## Laboratory work III
Баранов Артём ИУ8-33
Данная лабораторная работа посвещена изучению систем контроля версий на примере **Git**.

```bash
$ open https://git-scm.com
```

## Tasks
	
- [X] 1. Создать публичный репозиторий с названием **lab03** и с лиценцией **MIT**
- [X] 2. Ознакомиться со ссылками учебного материала
- [X] 3. Выполнить инструкцию учебного материала
- [X] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**
	
	## Tutorial
	Устонавливаем значения переменных окружения.
	```ShellSession
	$ export GITHUB_USERNAME=Murderdoll # Устанавливаем значение переменной окружения GITHUB_USERNAME
	$ export GITHUB_EMAIL=artem765@inbox.ru # Устанавливаем значение переменной окружения GITHUB_EMAIL
	$ alias edit=atom # Выбираем текстовый редактор, в котором будем работать
	```
	
	Создаем каталон, инициализируем локальный репозиторий, устанавливаем параметры через утилиту git config,
        Вносим изменения в репозиторий и отправляем на GitHub.
	```ShellSession
	$ mkdir lab03 && cd lab03 # Создаем каталог lab03 и переходим в него
	$ git init # Создаем репозиторий Git в нашем каталоге
	$ git config --global user.name ${GITHUB_USERNAME}
	$ git config --global user.email ${GITHUB_EMAIL} # С помощью утилиты git config устанавливаем ряд параметро для дальнейшей работы              
	$ git config -e --global # Открываем файл конфигураций и проверяем введенные нами параметры
	$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab03 # Добавляем удаленный репозиторий по ссылке
	$ git pull origin master # Копируем содержимое удаленного репозитория в ветку мастер
	$ touch README.md # Создаем файл README.MD
	$ git status # Просматриваем состояние файлов в нашем репозитории
	$ git add README.md # Добавляем файл README.md под версионный контроль
	$ git commit -m"added README.md" # Фиксируем изменения и оставляем комментарий
	$ git push origin master # Отправляем содержимое локального репозиторий в главный репозиторий
	```
	Добавить на сервисе **GitHub** в репозитории **lab03** файл **.gitignore**
	со следующем содержимом:
	
	```ShellSession
	*build*/
	*install*/
	*.swp
	```
	Обновляем локальный репозиторий и выводим историю изменений
	```ShellSession
	$ git pull origin master # Обновляем данные в нашем локальном репозитории
	$ git log # Просматриваем историю всех коммитов
	```
	Создаем каталоги и добавляем в них различные файлы в локальном репозитории
	```ShellSession
	$ mkdir sources
	$ mkdir include
	$ mkdir examples # Создаем каталоги sources, include, examples
	$ cat > sources/print.cpp <<EOF
	#include <print.hpp>
	
	void print(const std::string& text, std::ostream& out) {
	  out << text;
	}
	
	void print(const std::string& text, std::ofstream& out) {
	  out << text;
	}
	EOF  # В каталоге sources создаем файл print.cpp с кодом
	```
	
	```ShellSession
	$ cat > include/print.hpp <<EOF
	#include <string>
	#include <fstream>
	#include <iostream>
	
	void print(const std::string& text, std::ostream& out = std::cout);
	void print(const std::string& text, std::ofstream& out);
	EOF  # В каталоге include создаем файл print.hpp с кодом
	```
	
	```ShellSession
	$ cat > examples/example1.cpp <<EOF
	#include <print.hpp>
	
	int main(int argc, char** argv) {
	  print("hello");
	}
	EOF  # В каталоге examples создаем файл example1.cpp с кодом
	```
	
	```ShellSession
	$ cat > examples/example2.cpp <<EOF
	#include <fstream>
	#include <print.hpp>
	
	int main(int argc, char** argv) {
	  std::ofstream file("log.txt");
	  print(std::string("hello"), file);
	}
	EOF # В каталоге examples создаем файл example2.cpp с кодом
	```
	
	```ShellSession
	$ edit README.md # Редактируем файл README.md
	```
	Фиксируем последние изменения в нашем репозитории и отправляем в ветку мастер на GitHub.
	```ShellSession
	$ git status # Просматриваем состояние файлов в нашем репозитории
	$ git add . # Вносим наши файлы под версионный контроль
	$ git commit -m"added sources" # Фиксируем изменения
	$ git push origin master # Отправляем наш репозиторий на удаленный сервер
	```
	
	## Report
	```ShellSession
	$ cd ~/workspace/labs/
	$ export LAB_NUMBER=03
	$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
	$ mkdir reports/lab${LAB_NUMBER}
	$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
	$ cd reports/lab${LAB_NUMBER}
	$ edit REPORT.md
	$ gistup -m "lab${LAB_NUMBER}"
	```
	
	## Links
	
	- [GitHub](https://github.com)
	- [Bitbucket](https://bitbucket.org)
	- [Gitlab](https://about.gitlab.com)
	- [LearnGitBranching](http://learngitbranching.js.org/)
	
	```
	Copyright (c) 2017 Братья Вершинины
	```
