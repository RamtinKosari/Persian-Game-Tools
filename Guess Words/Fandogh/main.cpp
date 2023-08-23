# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <regex>

# define WARNING "\033[38;2;255;255;0m[WARNING]\033[0m "
# define SUCCESS "\033[38;2;0;255;0m[SUCCESS]\033[0m "
# define FAILED "\033[38;2;255;0;0m[FAILED]\033[0m "
# define LOG "\033[38;2;150;150;150m[LOG]\033[0m "
# define IP "\033[38;2;150;150;0m[IP]\033[0m"
# define TAB "   "
# define ENDL "\n"

int main(int argc, char* argv[]) {
    //-- Check Arguments
    if (argc != 2) {
        std::cout << FAILED "No Data File Specified" ENDL;
        exit(EXIT_FAILURE);
    }
    //-- Import Data File
    std::ifstream data_file(argv[1]);
    //-- Check if the File has been Opened Successfully
    if (!data_file.is_open()) {
        std::cout << FAILED "Error opening the file." ENDL;
        exit(EXIT_FAILURE);
    }
}