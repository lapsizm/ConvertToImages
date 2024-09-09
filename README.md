# Архиватор файлов

## Описание

Этот проект представляет собой простую утилиту для архивации и разархивации файлов. Он включает функции для архивации содержимого директории в бинарный файл и восстановления файлов из этого архива. Кроме того, он предоставляет функции для печати всех файлов и их имен в директории.

## Функции

### `print_all_files(const std::string &path)`

Печатает полный путь к каждому файлу в указанной директории и всех ее поддиректориях.

**Параметры:**

- `path`: Путь к директории, содержимое которой нужно вывести.

### `get_filename(const std::string &path)`

Печатает имена всех файлов (без полного пути) в указанной директории и всех ее поддиректориях.

**Параметры:**

- `path`: Путь к директории, содержимое которой нужно вывести.

### `archive(const std::string &path)`

Создает бинарный архив из файлов в указанной директории и всех ее поддиректориях.

**Параметры:**

- `path`: Путь к директории, которую нужно архивировать.

## Основной файл

- **`main.cpp`**: Основной файл, содержащий код для архивации, разархивации и печати файлов. Принимает один аргумент командной строки - путь к архиву для разархивации.

## Как использовать

### Сборка

Для сборки проекта выполните следующие шаги:

1. Убедитесь, что у вас установлен компилятор C++11 или новее.
2. Создайте файл `CMakeLists.txt` для сборки проекта (если используете CMake):

    ```cmake
    cmake_minimum_required(VERSION 3.10)
    project(FileArchiver)

    set(CMAKE_CXX_STANDARD 11)

    add_executable(file_archiver main.cpp)
    ```

3. Выполните следующие команды для сборки:

    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

### Запуск

1. **Архивация директории**

   Запустите программу для создания архива из директории `myfolder`:

   ```sh
   ./file_archiver
   ```

2. **Разархивация файла**

   Запустите программу с указанием пути к архиву, чтобы разархивировать его:

   ```sh
   ./file_archiver ../new_file.dat
   ```

   После разархивации программа выведет список всех файлов и их имен в разархивированной директории.

## Примеры использования

### Архивация

Чтобы создать архив из директории `../myfolder`, просто запустите:

```sh
./file_archiver
```

### Разархивация

Для разархивации файла `../new_file.dat` выполните:

```sh
./file_archiver ../new_file.dat
```

