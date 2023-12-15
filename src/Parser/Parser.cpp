#include "../../include/Parser/Parser.hpp"
#include <vector>

size_t Parser::nb_char(std::string file, char c)
{
    size_t result = 0;

    for(size_t i = 0; i < file.length(); i += 1) {
        if (file.at(i) == c) {
            result += 1;
        }
    }
    return result;
}

int Parser::getlenline(int pos)
{
    int idx = 0;

    while (this->text.at(pos + idx) != '\n') {
        idx += 1;
    }
    return idx;
}

std::vector<std::string> Parser::my_str_to_array()
{
    std::vector<std::string> result;
    int len_l = 0;
    int idx = 0;

    for (size_t i = 0; i < this->nb_line; i += 1) {
        len_l = getlenline(idx);
        result.push_back(this->text.substr(idx, len_l));
        idx += len_l + 1;
    }
    return result;
}

std::vector<std::string> Parser::get_text(std::string arg)
{
    std::ifstream fileStream(arg);

    if (!fileStream.is_open()) {
        std::cerr << "No patern for this file: " << arg << std::endl;
    }
    std::stringstream buffer;
    this->buffer << fileStream.rdbuf();
    this->text = this->buffer.str();
    this->nb_line = nb_char(this->text, '\n');
    std::vector<std::string> result = my_str_to_array();
    fileStream.close();
    return result;
}

std::vector<std::string> Parser::getChipsets()
{
    return this->chipsets;
}

std::vector<std::string> Parser::getLinks()
{
    return this->links;
}

Parser::Parser(std::string path)
{
    std::string tmp;

    this->array = get_text(path);
    if (this->array.empty()) {
        std::cout << "bad text\n";
        throw std::exception();
    }
    while (!this->array.empty()) {
        if (this->array.front().compare(".chipsets:") == 0) {
            tmp = "chipsets";
        } else if (this->array.front().compare(".links:") == 0) {
            tmp = "links";
        } else if (nb_char(this->array.front(), ' ') == 1) {
            if (tmp.compare("links") == 0) {
                this->links.push_back(this->array.front());
            } else if (tmp.compare("chipsets") == 0) {
                this->chipsets.push_back(this->array.front());
            } else {
                std::cout << "\"" << this->array.front() << "\" bad arguments\n";
                throw std::exception();
            }
        } else if (!this->array.front().empty() && this->array.front().at(0) != '#') {
            std::cout << "\"" << this->array.front() << "\" bad arguments\n";
            throw std::exception();
        }
        this->array.erase(this->array.begin());
    }
    if (this->chipsets.empty() || this->links.empty()) {
        std::cout << "argument not avalble\n";
        throw std::exception();
    }
}