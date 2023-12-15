/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-edouard.pradie
** File description:
** Prompt
*/

#include "../../include/CommandLine/Prompt.hpp"
#include <iostream>
#include <string>

void Prompt::runPrompt(std::vector<std::unique_ptr<Nts::IComponent>> &components)
{
    for (std::string line; !loop;) {
        try {
            std::cout << PROMPT;
            std::getline(std::cin, line);
            if (std::cin.eof()) {
                loop = true;
            }
            if (!line.empty())
                compareWithBultin(line, components);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            loop = true;
        }
    }
}

void check_setInputValue(std::string str, std::vector<std::unique_ptr<Nts::IComponent>> &components, Nts::tristate val)
{
    for (unsigned int idx = 0; idx < components.size(); idx += 1) {
        Nts::IComponent &a_component = *components[idx];
        if ((a_component.getType() == "input" || a_component.getType() == "clock") &&
        a_component.getName() == str.substr(0, str.find("="))) {
            a_component.setVal(val);
            break;
        }
    }
}

void Prompt::setInputValue(std::string str, std::vector<std::unique_ptr<Nts::IComponent>> &components)
{
    if (str.find("=U") != std::string::npos) {
        check_setInputValue(str, components, Nts::Undefined);
    } else if (str.find("=0") != std::string::npos) {
        check_setInputValue(str, components, Nts::False);
    } else {
        check_setInputValue(str, components, Nts::True);
    }
}

void Prompt::compareWithBultin(std::string str, std::vector<std::unique_ptr<Nts::IComponent>> &components)
{
    if (str == "exit") {
        loop = true;
        return;
    }
    if (str == "simulate") {
        for (unsigned int idx = 0; idx < components.size(); idx += 1) {
            components[idx]->simulate(nb_simulate);
        }
        nb_simulate += 1;
        return;
    }
    if (str == "display") {
        bultinDisplay(components);
        return;
    }
    if (str.find("=1") != std::string::npos || str.find("=0") != std::string::npos || str.find("=U") != std::string::npos) {
        setInputValue(str, components);
        return;
    }
    if (str == "loop") {
        while (true) {
            for (unsigned int idx = 0; idx < components.size(); idx += 1) {
                Nts::IComponent &a_component = *components[idx];
                if (a_component.getType() == "input")
                    a_component.simulate(1);
            }
            nb_simulate += 1;
            bultinDisplay(components);
        }
    }
    std::cout << str << PROMPT_ERROR;
}

void Prompt::bultinDisplay(std::vector<std::unique_ptr<Nts::IComponent>> &components)
{
    std::cout << "tick: " << nb_simulate << std::endl;
    std::cout << "input(s):" << std::endl;
    for (unsigned int idx = 0; idx < components.size(); idx += 1) {
        Nts::IComponent &a_component = *components[idx];
        if (a_component.getType() == "input" || a_component.getType() == "clock") {
            std::cout << "  " << a_component.getName() << ": " << a_component.getVal() << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (unsigned int idx = 0; idx < components.size(); idx += 1) {
        Nts::IComponent &a_component = *components[idx];
        if (a_component.getType() == "output") {
            std::cout << "  " << a_component.getName() << ": " << a_component.getVal() << std::endl;
        }
    }
}
