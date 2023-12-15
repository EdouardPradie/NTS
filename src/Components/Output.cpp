#include "../../include/Components/Output.hpp"

Output::Output(std::string type, std::string name)
{
    this->type = type;
    this->name = name;
    this->val = Nts::Undefined;
    this->display = Nts::Undefined;
}

void Output::simulate(std::size_t tick)
{
    std::size_t x = tick;
    tick = x;
    if (!this->links.empty())
        this->val = this->compute(0);
    this->display = this->val;
}

Nts::tristate Output::compute(std::size_t pin)
{
    return this->links.at(pin).first->getVal();
}

Nts::tristate Output::getVal()
{
    return this->display;
}

std::string Output::getName()
{
    return this->name;
}

std::string Output::getType()
{
    return this->type;
}

void Output::setVal(Nts::tristate val)
{
    this->val = val;
    this->display = val;
}

void Output::getLink()
{
    std::cout << "\t";
    for (int i = 0; i < 1; i += 1) {
        if (this->links.at(i).first != nullptr)
            std::cout << this->links.at(i).first->getName() << " " << this->links.at(i).second << " ";
        else
            std::cout << "N N ";
    }
    std::cout << std::endl;
}

void Output::setLink(std::size_t pin, Nts::IComponent &other, std::size_t other_pin)
{
    if (pin != 1) {
        std::cout << "The pin " << pin << " for " << this->name << " is not available\n";
        throw std::exception();
    }
    this->links.at(pin - 1).first = &other;
    this->links.at(pin - 1).second = other_pin;
}
