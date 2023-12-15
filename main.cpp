#include "include/Components/Factory.hpp"
#include "include/CommandLine/Prompt.hpp"

Nts::IComponent &get_comp(std::vector<std::unique_ptr<Nts::IComponent>> &arg, std::string name)
{
    if (arg.back()->getName() == name) {
        return *arg[arg.size() - 1];
    }
    for (int i = 0; arg.at(i) != arg.back(); i += 1) {
        if (arg.at(i)->getName() == name) {
            return *arg[i];
        }
    }
    std::cout << "Unknow component name \'" << name << "\'.\n";
    throw std::exception();
}

std::vector<std::unique_ptr<Nts::IComponent>> linker_roll(std::vector<std::unique_ptr<Nts::IComponent>> arg, std::vector<std::string> links)
{
    std::string name_1;
    std::string name_2;
    std::size_t pin_1;
    std::size_t pin_2;
    std::string str;

    while (!links.empty()) {
        str = links.front();
        name_1 = str.substr(0, str.find(':'));
        name_2 = str.substr(str.find(' ') + 1, str.find(':', str.find(':') + 1) - str.find(' ') - 1);
        pin_1 = std::atoi(str.substr(str.find(':') + 1, str.find(' ') - str.find(':') - 1).c_str());
        pin_2 = std::atoi(str.substr(str.find(':', str.find(':') + 1) + 1, str.length() - str.find(':', 1) - 1).c_str());
        if (name_1.empty() || name_2.empty() || pin_1 <= 0 || pin_2 <= 0) {
            std::cout << "Invalid Link in : \"" << str << "\"\n";
            throw std::exception();
        }
        Nts::IComponent &comp_1 = get_comp(arg, name_1);
        Nts::IComponent &comp_2 = get_comp(arg, name_2);
        comp_1.setLink(pin_1, comp_2, pin_2);
        comp_2.setLink(pin_2, comp_1, pin_1);
        links.erase(links.begin());
    }
    return arg;
}

std::vector<std::unique_ptr<Nts::IComponent>> factory_roll(std::string file)
{
    std::vector<std::unique_ptr<Nts::IComponent>> result;
    Parser parse(file);

    std::vector<std::string> chipsets = parse.getChipsets();
    while (!chipsets.empty()) {
        std::string str = chipsets.front();
        std::string type = str.substr(0, str.find(' '));
        std::string name = str.substr(str.find(' ') + 1, str.length() - str.find(' ') - 1);
        std::unique_ptr<Nts::IComponent> tmp = Factory::creatComponent(type, name);
        result.push_back(std::move(tmp));
        chipsets.erase(chipsets.begin());
    }
    return linker_roll(std::move(result), parse.getLinks());
}

int main(int const argc, char *const *argv)
{
    if (argc != 2) {
        std::cout << "Bad argument\n";
        return FAILURE;
    }
    try
    {
        Prompt prompt;
        std::vector<std::unique_ptr<Nts::IComponent>> components = factory_roll(argv[1]);
        for (unsigned int idx = 0; idx < components.size(); idx += 1) {
            components[idx]->simulate(0);
        }
        prompt.runPrompt(components);
    }
    catch (const std::exception &e)
    {
        return FAILURE;
    }
    return 0;
}
