## Сборка независимых подпроектов с помощью CMake

### Структура проекта:

* `[my_project]` --- корневая папка проекта
  * `[sub_project_1]` --- папка подпроекта sub_project_1
    * `CMakeLists.txt` --- cmake-файл подпроекта
    * `source_file.cpp` --- cpp файл
    * `header_file.h` --- заголовочный файл
  * `[sub_project_2]` --- папка подпроекта sub_project_2
    * `...` --- файлы подпроекта
  * `CMakeLists.txt` --- корневой cmake-файл всего проекта

##### CMakeLists.txt

```{cmake}
cmake_minimum_required(VERSION 3.8)

# Название проекта и версия
project(my_project_name VERSION 0.0.$ENV{PROJECT_VERSION})

# Устанавливаем версию компилятора
set(CMAKE_CXX_STANDARD 17)
# Чтоб бинарник собирался в директории build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# Добавление подпроектов
add_subdirectory(sub_project1)
add_subdirectory(sub_project2)
```

##### sub_project_1/CMakeLists.txt

```{cmake}
add_executable(helloworld source_file.cpp)
```

##### sub_project_1/source_file.cpp

```{cpp}
#include "header_file.h"

int main() {
  greetings();
  return 0;
}
```

##### sub_project_1/header_file.h

```{cpp}
#pragma once
#include <iostream>

void greetings() {
  std::cout << "Ola, amigo!" << std::endl;
}
```

##### sub_project_2/CMakeLists.txt

```{cmake}
add_executable(new_project source.cpp)
```

---



#### Сборка проекта

Создадим директорию со сборкой.
```{bash}
# В директории [my_project]
mkdir build
cd build
```
Запуск cmake
* На маке
```{bash}
env CC=gcc-9 CXX=g++-9 cmake ..
```
* На линуксе
```{bash}
cmake ..
```

Сборка бинарника подпроекта sub_project_1
```{bash}
make helloworld
```





###Генерация ssh ключей

```{bash}
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
> Generating public/private rsa key pair.

> Enter a file in which to save the key (/Users/you/.ssh/id_rsa): [Press enter]
> Enter passphrase (empty for no passphrase): [Type a passphrase]
> Enter same passphrase again: [Type passphrase again]

eval "$(ssh-agent -s)"
> Agent pid 59566

vim ~/.ssh/config

Host *
  AddKeysToAgent yes
  UseKeychain yes
  IdentityFile ~/.ssh/id_rsa

ssh-add -K ~/.ssh/id_rsa

pbcopy < ~/.ssh/id_rsa.pub
```



