#ifndef PARSER_H_
    #define PARSER_H_
    #include <sstream>
    #include <fstream>
    #include <vector>
    #include <iostream>
    #include <exception>

class Parser
{
    public:
        Parser(std::string path);
        ~Parser() = default;

        size_t nb_char(std::string str, char c);
        int getlenline(int pos);
        std::vector<std::string> my_str_to_array();
        std::vector<std::string> get_text(std::string path);
        std::vector<std::string> getChipsets();
        std::vector<std::string> getLinks();
    private:
        std::string text;
        std::stringstream buffer;
        size_t nb_line;
        std::vector<std::string> array;
        std::vector<std::string> chipsets;
        std::vector<std::string> links;
};

#endif
