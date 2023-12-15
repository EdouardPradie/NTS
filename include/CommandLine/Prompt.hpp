/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-edouard.pradie
** File description:
** Prompt
*/

#pragma once

#include <exception>
#include <string>
#include "../Components/Factory.hpp"

#define PROMPT "> "
#define PROMPT_ERROR ": Invalid command\n"

class Prompt
{
    public:
        Prompt() = default;
        ~Prompt() = default;
        void runPrompt(std::vector<std::unique_ptr<Nts::IComponent>> &components);
        void compareWithBultin(std::string str, std::vector<std::unique_ptr<Nts::IComponent>> &components);
        void bultinDisplay(std::vector<std::unique_ptr<Nts::IComponent>> &components);
        void setInputValue(std::string str, std::vector<std::unique_ptr<Nts::IComponent>> &components);
        void sendInputToGate(std::vector<std::unique_ptr<Nts::IComponent>> &components);

    private:
        bool loop = false;
        int nb_simulate = 0;
};
