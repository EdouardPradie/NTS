#include "../../include/Components/False.hpp"

False::False(std::string type, std::string name)
{
    this->type = type;
    this->name = name;
    this->val = Nts::False;
    this->display = Nts::False;
}

void False::simulate(std::size_t tick)
{
    this->links.at(0).first->simulate(tick);
}

Nts::tristate False::compute(std::size_t pin)
{
    return this->links.at(pin).first->getVal();
}

Nts::tristate False::getVal()
{
    return Nts::False;
}

std::string False::getName()
{
    return this->name;
}

std::string False::getType()
{
    return this->type;
}

void False::setVal(Nts::tristate val)
{
    val = Nts::False;
    this->val = val;
}

void False::getLink()
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

void False::setLink(std::size_t pin, Nts::IComponent &other, std::size_t other_pin)
{
    if (pin != 1) {
        std::cout << "The pin " << pin << " fFalse " << this->name << " is False available\n";
        throw std::exception();
    }
    this->links.at(pin - 1).first = &other;
    this->links.at(pin - 1).second = other_pin;
    this->links.at(0).first->setVal(this->getVal());
}
