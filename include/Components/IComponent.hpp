#ifndef ICOMPONENT_H_
    #define ICOMPONENT_H_
    #define FAILURE 84
    #include <string>
    #include <array>
    #include <utility>
    #include <memory>

namespace Nts
{
    enum tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent
    {
    public:
        virtual ~IComponent() = default;

        virtual void getLink () = 0;
        virtual std::string getName () = 0;
        virtual std::string getType () = 0;
        virtual Nts::tristate getVal () = 0;
        virtual void setVal (Nts::tristate val) = 0;
        virtual void simulate (std::size_t tick) = 0;
        virtual Nts::tristate compute (std::size_t pin) = 0;
        virtual void setLink (std::size_t pin, Nts::IComponent &other, std::size_t other_pin) = 0;
    };

    struct link_t {
        Nts::IComponent *first;
        std::size_t second;
    };
}

Nts::tristate operator&&(Nts::tristate a, Nts::tristate b);
Nts::tristate operator||(Nts::tristate a, Nts::tristate b);
Nts::tristate operator|=(Nts::tristate a, Nts::tristate b);
Nts::tristate operator!=(Nts::tristate a, Nts::tristate b);
std::ostream &operator<<(std::ostream &s, const Nts::tristate &t);

#endif
