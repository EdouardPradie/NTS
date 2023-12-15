#include "../../include/Components/Clock.hpp"

Clock::Clock(std::string type, std::string name)
{
    this->type = type;
    this->name = name;
    this->val = Nts::Undefined;
    this->display = Nts::Undefined;
}

void Clock::simulate(std::size_t tick)
{
    std::size_t x = tick;
    tick = x;
    if (this->display == Nts::Undefined || this->val == Nts::Undefined) {
        this->display = this->val;
    } else {
        this->display = this->display != this->display;
    }
    this->links.at(0).first->setVal(this->display);
}

Nts::tristate Clock::compute(std::size_t pin)
{
    return this->links.at(pin).first->getVal();
}

Nts::tristate Clock::getVal()
{
    return this->display;
}

std::string Clock::getName()
{
    return this->name;
}

std::string Clock::getType()
{
    return this->type;
}

void Clock::setVal(Nts::tristate val)
{
    this->val = val;
}

void Clock::getLink()
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

void Clock::setLink(std::size_t pin, Nts::IComponent &other, std::size_t other_pin)
{
    if (pin != 1) {
        std::cout << "The pin " << pin << " for " << this->name << " is not available\n";
        throw std::exception();
    }
    this->links.at(pin - 1).first = &other;
    this->links.at(pin - 1).second = other_pin;
}
