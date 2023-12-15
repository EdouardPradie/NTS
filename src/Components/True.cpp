#include "../../include/Components/True.hpp"

True::True(std::string type, std::string name)
{
    this->type = type;
    this->name = name;
    this->val = Nts::True;
    this->display = Nts::True;
}

void True::simulate(std::size_t tick)
{
    this->links.at(0).first->simulate(tick);
}

Nts::tristate True::compute(std::size_t pin)
{
    return this->links.at(pin).first->getVal();
}

Nts::tristate True::getVal()
{
    return Nts::True;
}

std::string True::getName()
{
    return this->name;
}

std::string True::getType()
{
    return this->type;
}

void True::setVal(Nts::tristate val)
{
    val = Nts::True;
    this->val = val;
}

void True::getLink()
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

void True::setLink(std::size_t pin, Nts::IComponent &other, std::size_t other_pin)
{
    if (pin != 1) {
        std::cout << "The pin " << pin << " fTrue " << this->name << " is True available\n";
        throw std::exception();
    }
    this->links.at(pin - 1).first = &other;
    this->links.at(pin - 1).second = other_pin;
    this->links.at(0).first->setVal(this->getVal());
}
