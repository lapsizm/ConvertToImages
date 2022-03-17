#include <iostream>
#include <filesystem>
#include <fstream>

void print_all_files(const std::string &path) {
    using std::cout; using std::cin;
    using std::endl; using std::string;
    using std::filesystem::recursive_directory_iterator;
    for (const auto &file : recursive_directory_iterator(path))
        cout << file.path() << endl;
}

void get_filename(const std::string &path) {
    using std::cout; using std::cin;
    using std::endl; using std::string;
    using std::filesystem::recursive_directory_iterator;
    for (const auto &file : recursive_directory_iterator(path))
        cout << file.path().filename() << endl;
}

int main() {
    std::string path = "../files.bmtar.dat";
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

    while(!fin.eof()){
        std::string file_name;
        std::getline(fin, file_name, '\0');
        std::ofstream fout(dir_name + file_name, std::ios::binary);
        int size;
        fin.read(reinterpret_cast<char*>(&size), 4);
        for(size_t i = 0; i < size; ++i){
            char symbol;
            fin.read(reinterpret_cast<char*>(&symbol), 1);
            fout.write(reinterpret_cast<char*>(&symbol), 1);
        }
        fout.close();
    }
    fin.close();

    print_all_files(dir_name);
    get_filename(dir_name);
}
