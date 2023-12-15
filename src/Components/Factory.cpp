#include "../../include/Components/Factory.hpp"

std::unique_ptr<Nts::IComponent> Factory::creatComponent (std::string type, std::string name)
{
    std::map<std::string, std::function<std::unique_ptr<Nts::IComponent>(std::string, std::string)>> m{
        {"input", creatInput},
        {"and", creatAnd},
        {"4081", creatAndl},
        {"4011", creatNand},
        {"or", creatOr},
        {"4071", creatOrl},
        {"xor", creatXor},
        {"4030", creatXorl},
        {"output", creatOutput},
        {"clock", creatClock},
        {"true", creatTrue},
        {"false", creatFalse},
        {"not", creatNot},
        {"4001", creatNor},
        {"4069", creatNotl}};

    if (m.find(type) != m.end()) {
        return m[type](type, name);
    }
    std::cout << "\"" << type << "\" is not a type\n";
    throw std::exception();
}

std::unique_ptr<Nts::IComponent> Factory::creatInput (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<Input>(type, name);

    return result;
}

std::unique_ptr<Nts::IComponent> Factory::creatOutput (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<Output>(type, name);

    return result;
}

std::unique_ptr<Nts::IComponent> Factory::creatNand (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<Nand>(type, name);

    return result;
}

std::unique_ptr<Nts::IComponent> Factory::creatAnd (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<And>(type, name);

    return result;
}

std::unique_ptr<Nts::IComponent> Factory::creatAndl (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<Andl>(type, name);

    return result;
}

std::unique_ptr<Nts::IComponent> Factory::creatOr (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<Or>(type, name);

    return result;
}

std::unique_ptr<Nts::IComponent> Factory::creatOrl (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<Orl>(type, name);

    return result;
}

std::unique_ptr<Nts::IComponent> Factory::creatXor (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<Xor>(type, name);

    return result;
}

std::unique_ptr<Nts::IComponent> Factory::creatXorl (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<Xorl>(type, name);

    return result;
}

std::unique_ptr<Nts::IComponent> Factory::creatNot (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<Not>(type, name);

    return result;
}

std::unique_ptr<Nts::IComponent> Factory::creatNor (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<Nor>(type, name);

    return result;
}

std::unique_ptr<Nts::IComponent> Factory::creatNotl (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<Notl>(type, name);

    return result;
}

std::unique_ptr<Nts::IComponent> Factory::creatClock (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<Clock>(type, name);

    return result;
}

std::unique_ptr<Nts::IComponent> Factory::creatFalse (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<False>(type, name);

    return result;
}

std::unique_ptr<Nts::IComponent> Factory::creatTrue (std::string type, std::string name)
{
    std::unique_ptr<Nts::IComponent> result = std::make_unique<True>(type, name);

    return result;
}
