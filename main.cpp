#include <iostream>
#include <filesystem>
#include <fstream>

void print_all_files(const std::string &path) {
    using std::cout; using std::cin;
    using std::endl; using std::string;
    using std::filesystem::recursive_directory_iterator;
    for (const auto &file: recursive_directory_iterator(path))
        cout << file.path() << endl;
}

void get_filename(const std::string &path) {
    using std::cout; using std::cin;
    using std::endl; using std::string;
    using std::filesystem::recursive_directory_iterator;
    for (const auto &file: recursive_directory_iterator(path))
        cout << file.path().filename() << endl;
}

//функция для создания архива при наличии myfolder
void archive(const std::string &path){
    using std::filesystem::recursive_directory_iterator;
    std::string new_file("../new_file.dat");
    std::ofstream fout(new_file);
    int temp = path.length() - 1;
    while(temp > 0){
        if(path[temp] == '/'){
            break;
        }
        --temp;
    }
    std::string name_dir = path.substr(temp + 1, path.length());
    fout << name_dir << '\0';

    for (const auto &file: recursive_directory_iterator(path)){
        std::ifstream fin(file.path());
        std::string file_name = file.path().filename().string();
        fout << file_name << '\0';
        int size = file.file_size();
        fout.write(reinterpret_cast<char*>(&size), 4);
        for(int i = 0; i < size; ++i){
            char symbol;
            fin.read(reinterpret_cast<char*>(&symbol), 1);
            fout.write(reinterpret_cast<char *>(&symbol), 1);
        }
        fin.close();
    }
    fout.close();
}

int main(int argc, char **argv) {
    if (argc == 2) {
        std::string path = argv[1];
        std::ifstream fin(path, std::ios::binary);
        if (!fin.is_open()) {
            std::cout << "!!!file is not opened!!!" << std::endl;
            return -1;
        }
        std::string temp_dir;
        std::getline(fin, temp_dir, '\0');
        std::string dir_name = "../";
        dir_name += temp_dir + "/";
        std::filesystem::create_directory(dir_name);
        while (!fin.eof()) {
            std::string file_name;
            std::getline(fin, file_name, '\0');
            std::ofstream fout(dir_name + file_name, std::ios::binary);
            int size;
            fin.read(reinterpret_cast<char *>(&size), 4);
            for (size_t i = 0; i < size; ++i) {
                char symbol;
                fin.read(reinterpret_cast<char *>(&symbol), 1);
                fout.write(reinterpret_cast<char *>(&symbol), 1);
            }
            fout.close();
        }
        fin.close();

        print_all_files(dir_name);
        get_filename(dir_name);
    }
    archive("../myfolder");
}
