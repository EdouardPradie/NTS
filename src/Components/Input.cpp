#include "../../include/Components/Input.hpp"

Input::Input(std::string type, std::string name)
{
    this->type = type;
    this->name = name;
    this->val = Nts::Undefined;
    this->display = Nts::Undefined;
}

void Input::simulate(std::size_t tick)
{
    std::size_t x = tick;
    tick = x;
    this->display = this->val;
}

Nts::tristate Input::compute(std::size_t pin)
{
    return this->links.at(pin).first->getVal();
}

Nts::tristate Input::getVal()
{
    return this->display;
}

std::string Input::getName()
{
    return this->name;
}

std::string Input::getType()
{
    return this->type;
}

void Input::setVal(Nts::tristate val)
{
    this->val = val;
}

void Input::getLink()
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

void Input::setLink(std::size_t pin, Nts::IComponent &other, std::size_t other_pin)
{
    if (pin != 1) {
        std::cout << "The pin " << pin << " for " << this->name << " is not available\n";
        throw std::exception();
    }
    this->links.at(pin - 1).first = &other;
    this->links.at(pin - 1).second = other_pin;
}

Nts::tristate operator&&(Nts::tristate a, Nts::tristate b)
{
    if (a == Nts::True && b == Nts::True) {
        return Nts::True;
    }
    if (a == Nts::False || b == Nts::False) {
        return Nts::False;
    }
    return Nts::Undefined;
}

Nts::tristate operator||(Nts::tristate a, Nts::tristate b)
{
    if (a == Nts::True || b == Nts::True) {
        return Nts::True;
    }
    if (a == Nts::Undefined || b == Nts::Undefined) {
        return Nts::Undefined;
    }
    return Nts::False;
}

Nts::tristate operator!=(Nts::tristate a, Nts::tristate b)
{
    if (a == Nts::True) {
        return Nts::False;
    }
    if (a == Nts::False) {
        return Nts::True;
    }
    return b;
}

Nts::tristate operator|=(Nts::tristate a, Nts::tristate b)
{
    if (a == Nts::Undefined || b == Nts::Undefined) {
        return Nts::Undefined;
    }
    if ((a == Nts::True && b != Nts::True) || (b == Nts::True && a != Nts::True) ){
        return Nts::True;
    }
    return Nts::False;
}

std::ostream &operator<<(std::ostream &s, const Nts::tristate &t) {
    if (t == Nts::Undefined) {
        s << "U";
    } else if (t == Nts::True) {
        s << "1";
    } else {
        s << "0";
    }
    return s;
}
