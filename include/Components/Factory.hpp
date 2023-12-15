#ifndef FACTORY_H_
    #define FACTORY_H_
    #include <array>
    #include <memory>
    #include <map>
    #include <functional>
    #include "Input.hpp"
    #include "Output.hpp"
    #include "Nand.hpp"
    #include "And.hpp"
    #include "Andl.hpp" 
    #include "Nor.hpp"
    #include "Not.hpp"
    #include "Notl.hpp"
    #include "Or.hpp"
    #include "Orl.hpp"
    #include "Clock.hpp"
    #include "True.hpp"
    #include "False.hpp"
    #include "Xor.hpp"
    #include "Xorl.hpp"

class Factory
{
    public:
        Factory() = delete;
        ~Factory() = delete;
        static std::unique_ptr<Nts::IComponent> creatComponent (std::string type, std::string name);
    private:
        static std::unique_ptr<Nts::IComponent> creatInput (std::string type, std::string name);
        static std::unique_ptr<Nts::IComponent> creatOutput (std::string type, std::string name);
        static std::unique_ptr<Nts::IComponent> creatAnd (std::string type, std::string name);
        static std::unique_ptr<Nts::IComponent> creatNand (std::string type, std::string name);
        static std::unique_ptr<Nts::IComponent> creatAndl (std::string type, std::string name);
        static std::unique_ptr<Nts::IComponent> creatOr (std::string type, std::string name);
        static std::unique_ptr<Nts::IComponent> creatOrl (std::string type, std::string name);
        static std::unique_ptr<Nts::IComponent> creatXor (std::string type, std::string name);
        static std::unique_ptr<Nts::IComponent> creatXorl (std::string type, std::string name);
        static std::unique_ptr<Nts::IComponent> creatNot (std::string type, std::string name);
        static std::unique_ptr<Nts::IComponent> creatNor (std::string type, std::string name);
        static std::unique_ptr<Nts::IComponent> creatNotl (std::string type, std::string name);
        static std::unique_ptr<Nts::IComponent> creatClock (std::string type, std::string name);
        static std::unique_ptr<Nts::IComponent> creatTrue (std::string type, std::string name);
        static std::unique_ptr<Nts::IComponent> creatFalse (std::string type, std::string name);
};

#endif
