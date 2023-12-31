# include <iostream>
# include <fstream>
# include <string>
# include <locale>
# include <vector>

# define SUGGEST "\033[38;2;255;255;0m[SUGGESTION]\033[0m "
# define SUCCESS "\033[38;2;0;255;0m[SUCCESS]\033[0m "
# define ANSWER "\033[38;2;0;255;0m[ANSWER]\033[0m "
# define FAILED "\033[38;2;255;0;0m[FAILED]\033[0m "
# define EMPTY "\033[38;2;255;200;0m[EMPTY]\033[0m "
# define LOG "\033[38;2;150;150;150m[LOG]\033[0m "
# define IP "\033[38;2;150;150;0m[IP]\033[0m"
# define TAB "   "
# define ENDL "\n"

int main(int argc, char* argv[]) {
    //-- Check Arguments
    if (argc != 2) {
        std::wcout << FAILED "No Data File Specified" ENDL;
        exit(EXIT_FAILURE);
    }
    //-- Set the Locale to Handle Persian Characters
    std::locale::global(std::locale(""));
    //-- Import Data File
    std::wifstream data_file(argv[1]);
    //-- Check if the File has been Opened Successfully
    if (!data_file.is_open()) {
        std::wcout << FAILED "Error opening the file." ENDL;
        exit(EXIT_FAILURE);
    }
    //-- Definitions
    std::vector<std::wstring> words;
    std::wstring line;
    while (std::getline(data_file, line)) {
        std::wstring tmp_word;
        // Filter out non-alphabetic characters
        for (wchar_t c : line) {
            if (std::iswalpha(c)) {
                tmp_word += std::towupper(c);
            }
        }
        words.push_back(tmp_word);
    }
    if (words.size() > 0) {
        std::wcout << SUCCESS "Data has been Loaded Successfully" ENDL;
    } else {
        std::wcout << FAILED "Empty Data" ENDL;
    }
    //-- Calculates Maximum Size of Word that is Possible According to Data File
    int max_size = 0;
    for (int i = 0; i < words.size(); i++) {
        if (words[i].size() > max_size) {
            max_size = words[i].size();
        }
    }
    //-- Client Section
    int point_value = 0;
    int accept_value = 0;
    std::wstring search_key;
    int accept_amount_with_letters = 0;
    std::vector<std::wstring> accepted_with_letters;
    std::wcout << LOG "Enter Letters Concatenated to each Other : "; std::wcin >> search_key;
    if (search_key.size() <= 1) {
        std::wcout << FAILED "At Least Two Letters Should be Passed" ENDL;
        exit(EXIT_FAILURE);
    }
    std::wcout << TAB LOG "Letters : " ENDL;
    for (wchar_t letter : search_key) {
        std::wcout << TAB TAB LOG << letter << ENDL;
    }
    std::wcout << LOG "Generating Possibilities ..." ENDL;
    for (int i = 0; i < words.size(); i++) {
        accept_value = words[i].size();
        for (int l1 = 0; l1 < words[i].size(); l1++) {
            for (int l2 = 0; l2 < search_key.size(); l2++) {
                if (words[i][l1] == search_key[l2]) {
                    point_value++;
                }
            }
        }
        if (point_value >= accept_value) {
            accepted_with_letters.push_back(words[i]);
            accept_amount_with_letters++;
        }
        point_value = 0;
    }
    if (accept_amount_with_letters > 0) {
        unsigned int amount = 0;
        for (int i = 2; i < max_size; i++) {
            std::wcout << TAB SUGGEST "Suggestions Words with " << i << " Letters :" ENDL;
            for (int j = 0; j < accepted_with_letters.size(); j++) {
                if (accepted_with_letters[j].size() == i) {
                    std::wcout << TAB TAB ANSWER << accepted_with_letters[j] << ENDL;
                    amount++;
                }
            }
            if (amount == 0) {
                std::wcout << TAB TAB EMPTY "Can Not Find any According to Data File" ENDL;
            }
            amount = 0;
        }
        std::wcout << TAB SUCCESS "Total Amount of Words with Combination of Your Letters :" ENDL;
    } else {
        std::wcout << TAB FAILED "No Accepted Word Found According to Data File" ENDL;
    }
    return 0;
}