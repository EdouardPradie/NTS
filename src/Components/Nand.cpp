#include "../../include/Components/Nand.hpp"

Nand::Nand(std::string type, std::string name)
{
    this->type = type;
    this->name = name;
    this->val = Nts::Undefined;
    this->display = Nts::Undefined;
}

void Nand::simulate(std::size_t tick)
{
    std::size_t x = tick;
    tick = x;
    if (this->links.empty())
        return;
    if ((this->links.at(0).first != nullptr) && (this->links.at(1).first != nullptr) && (this->links.at(2).first != nullptr)) {
        Nts::tristate a = this->compute(0) && this->compute(1);
        this->links.at(2).first->setVal(a != a);
    }
    if ((this->links.at(4).first != nullptr) && (this->links.at(5).first != nullptr) && (this->links.at(3).first != nullptr)) {
        Nts::tristate b = this->compute(4) && this->compute(5);
        this->links.at(3).first->setVal(b != b);
    }
    if ((this->links.at(7).first != nullptr) && (this->links.at(8).first != nullptr) && (this->links.at(9).first != nullptr)) {
        Nts::tristate c = this->compute(7) && this->compute(8);
        this->links.at(9).first->setVal(c != c);
    }
    if ((this->links.at(11).first != nullptr) && (this->links.at(12).first != nullptr) && (this->links.at(10).first != nullptr)) {
        Nts::tristate d = this->compute(11) && this->compute(12);
        this->links.at(10).first->setVal(d != d);
    }
}

Nts::tristate Nand::compute(std::size_t pin)
{
    return this->links.at(pin).first->getVal();
}

Nts::tristate Nand::getVal()
{
    return this->display;
}

std::string Nand::getName()
{
    return this->name;
}

std::string Nand::getType()
{
    return this->type;
}

void Nand::setVal(Nts::tristate val)
{
    this->val = val;
}

void Nand::getLink()
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

void Nand::setLink(std::size_t pin, Nts::IComponent &other, std::size_t other_pin)
{
    if (pin > 14 || pin == 0) {
        std::cout << "The pin " << pin << " for " << this->name << " is not available\n";
        throw std::exception();
    }
    this->links.at(pin - 1).first = &other;
    this->links.at(pin - 1).second = other_pin;
}
