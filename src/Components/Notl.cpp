#include "../../include/Components/Notl.hpp"

Notl::Notl(std::string type, std::string name)
{
    this->type = type;
    this->name = name;
    this->val = Nts::Undefined;
    this->display = Nts::Undefined;
}

void Notl::simulate(std::size_t tick)
{
    std::size_t x = tick;
    tick = x;
    if (this->links.empty())
        return;
    if ((this->links.at(0).first != nullptr) && (this->links.at(1).first != nullptr))
        this->links.at(1).first->setVal(this->compute(0) != this->compute(0));
    if ((this->links.at(2).first != nullptr) && (this->links.at(3).first != nullptr))
        this->links.at(3).first->setVal(this->compute(2) != this->compute(2));
    if ((this->links.at(4).first != nullptr) && (this->links.at(5).first != nullptr))
        this->links.at(5).first->setVal(this->compute(4) != this->compute(4));
    if ((this->links.at(7).first != nullptr) && (this->links.at(8).first != nullptr))
        this->links.at(7).first->setVal(this->compute(8) != this->compute(8));
    if ((this->links.at(9).first != nullptr) && (this->links.at(10).first != nullptr))
        this->links.at(9).first->setVal(this->compute(10) != this->compute(10));
    if ((this->links.at(11).first != nullptr) && (this->links.at(12).first != nullptr))
        this->links.at(11).first->setVal(this->compute(12) != this->compute(12));
}

Nts::tristate Notl::compute(std::size_t pin)
{
    return this->links.at(pin).first->getVal();
}

Nts::tristate Notl::getVal()
{
    return this->display;
}

std::string Notl::getName()
{
    return this->name;
}

std::string Notl::getType()
{
    return this->type;
}

void Notl::setVal(Nts::tristate val)
{
    this->val = val;
}

void Notl::getLink()
{
    std::cout << "\t";
    for (int i = 0; i < 14; i += 1) {
        if (this->links.at(i).first != nullptr)
            std::cout << this->links.at(i).first->getName() << " " << this->links.at(i).second << " ";
        else
            std::cout << "N N ";
    }
    std::cout << std::endl;
}

void Notl::setLink(std::size_t pin, Nts::IComponent &other, std::size_t other_pin)
{
    if (pin > 14 || pin == 0) {
        std::cout << "The pin " << pin << " for " << this->name << " is not available\n";
        throw std::exception();
    }
    this->links.at(pin - 1).first = &other;
    this->links.at(pin - 1).second = other_pin;
}
