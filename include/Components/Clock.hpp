#ifndef CLOCK_H_
    #define CLOCK_H_
    #include "IComponent.hpp"
    #include "../Parser/Parser.hpp"

class Clock : public Nts::IComponent
{
    public:
        Clock(std::string type, std::string name);
        ~Clock() override = default;

        void getLink() override;
        std::string getName() override;
        std::string getType() override;
        Nts::tristate getVal () override;
        void setVal (Nts::tristate val) override;
        void simulate(std::size_t tick) override;
        Nts::tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, Nts::IComponent &other, std::size_t other_pin) override;
    private:
        std::string name;
        std::string type;
        Nts::tristate display;
        Nts::tristate val;
        std::array<Nts::link_t, 1> links;
};

#endif
