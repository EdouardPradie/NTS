#ifndef NOR_H_
    #define NOR_H_
    #include "IComponent.hpp"
    #include "../Parser/Parser.hpp"

class Nor : public Nts::IComponent
{
    public:
        Nor(std::string type, std::string name);
        ~Nor() override = default;

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
        std::array<Nts::link_t, 14> links;
};

#endif
