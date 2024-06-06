#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

bool is_regular_file(const std::string &path) {
    struct stat path_stat;
    stat(path.c_str(), &path_stat);
    return S_ISREG(path_stat.st_mode);
}

bool has_java_extension(const std::string &filename) {
    return filename.size() > 5 && filename.substr(filename.size() - 5) == ".java";
}

std::vector<int> find_loop_headers(const std::string &file_path) {
    std::ifstream file(file_path);
    std::vector<int> line_numbers;
    std::string line;
    int line_number = 0;


    while (std::getline(file, line)) {
        line_number++;
        if (line.find("for") != std::string::npos || line.find("while") != std::string::npos) {
            line_numbers.push_back(line_number);
        }
    }

    file.close();
    return line_numbers;
}

void save_results(const std::vector<std::pair<std::string, std::vector<int>>> &results) {
    std::ofstream outfile("loops.txt");


    for (const auto &result : results) {
        outfile << result.first;
        for (int line_number : result.second) {
            outfile << " " << line_number;
        }
        outfile << std::endl;
    }

    outfile.close();
}

int main(int argc, char *argv[]) {
    std::string directory_path = argv[1];
    DIR *dir = opendir(directory_path.c_str());
    std::vector<std::pair<std::string, std::vector<int>>> results;
    struct dirent *entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string file_name = entry->d_name;
        std::string file_path = directory_path + "/" + file_name;

        if (is_regular_file(file_path) && has_java_extension(file_name)) {
            std::vector<int> line_numbers = find_loop_headers(file_path);
            results.emplace_back(file_name, line_numbers);
        }
    }
    std::cerr << std::endl;
    closedir(dir);

    // save_results(results);

    return 0;
}
