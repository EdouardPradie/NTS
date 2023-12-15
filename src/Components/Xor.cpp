#include "../../include/Components/Xor.hpp"

Xor::Xor(std::string type, std::string name)
{
    this->type = type;
    this->name = name;
    this->val = Nts::Undefined;
    this->display = Nts::Undefined;
}

void Xor::simulate(std::size_t tick)
{
    std::size_t x = tick;
    tick = x;
    if (this->links.empty() || (this->links.at(0).first == nullptr) || (this->links.at(1).first == nullptr) || (this->links.at(2).first == nullptr))
        return;
    this->links.at(2).first->setVal(this->compute(0) |= this->compute(1));
}

Nts::tristate Xor::compute(std::size_t pin)
{
    return this->links.at(pin).first->getVal();
}

Nts::tristate Xor::getVal()
{
    return this->display;
}

std::string Xor::getName()
{
    return this->name;
}

std::string Xor::getType()
{
    return this->type;
}

void Xor::setVal(Nts::tristate val)
{
    this->val = val;
}

void Xor::getLink()
{
    std::cout << "\t";
    for (int i = 0; i < 3; i += 1) {
        if (this->links.at(i).first != nullptr)
            std::cout << this->links.at(i).first->getName() << " " << this->links.at(i).second << " ";
        else
            std::cout << "N N ";
    }
    std::cout << std::endl;
}

void Xor::setLink(std::size_t pin, Nts::IComponent &other, std::size_t other_pin)
{
    if (pin > 3 || pin == 0) {
        std::cout << "The pin " << pin << " for " << this->name << " is not available\n";
        throw std::exception();
    }
    this->links.at(pin - 1).first = &other;
    this->links.at(pin - 1).second = other_pin;
}
