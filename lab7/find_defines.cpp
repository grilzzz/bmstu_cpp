#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <regex>

bool is_regular_file(const std::string &path) {
    struct stat path_stat;
    stat(path.c_str(), &path_stat);
    return S_ISREG(path_stat.st_mode);
}

bool has_c_extension(const std::string &filename) {
    return filename.size() > 2 && filename.substr(filename.size() - 2) == ".c";
}

// Ищет директивы #define в файле и классифицирует их
void find_defines(const std::string &file_path, std::vector<std::string> &constants, std::vector<std::string> &macros) {
    std::ifstream file(file_path);
    std::string line;
    std::regex define_regex("^\\s*#define\\s+([A-Za-z_][A-Za-z0-9_]*)\\s*(\\(([^)]*)\\))?.*");
    std::smatch match;


    while (std::getline(file, line)) {
        if (std::regex_search(line, match, define_regex)) {
            std::string macro_name = match[1];
            std::string params = match[3];
            if (params.empty()) {
                constants.push_back(macro_name);
            } else {
                macros.push_back(macro_name);
            }
        }
    }

    file.close();
}

// Сохраняет результаты в файлы
void save_results(const std::vector<std::string> &constants, const std::vector<std::string> &macros) {
    std::ofstream constants_file("constants.txt");
    std::ofstream macros_file("macros.txt");


    for (const auto &constant : constants) {
        constants_file << constant << std::endl;
    }

    for (const auto &macro : macros) {
        macros_file << macro << std::endl;
    }

    constants_file.close();
    macros_file.close();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <directory_path>" << std::endl;
        return 1;
    }

    std::string directory_path = argv[1];
    DIR *dir = opendir(directory_path.c_str());
    if (!dir) {
        std::cerr << "Unable to open directory: " << directory_path << std::endl;
        return 1;
    }

    std::vector<std::string> constants;
    std::vector<std::string> macros;
    struct dirent *entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string file_name = entry->d_name;
        std::string file_path = directory_path + "/" + file_name;

        if (is_regular_file(file_path) && has_c_extension(file_name)) {
            find_defines(file_path, constants, macros);
        }
    }

    closedir(dir);

    save_results(constants, macros);

    return 0;
}
