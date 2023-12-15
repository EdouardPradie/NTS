#ifndef OUTPUT_H_
    #define OUTPUT_H_
    #include "IComponent.hpp"
    #include "../Parser/Parser.hpp"

class Output : public Nts::IComponent
{
    public:
        Output(std::string type, std::string name);
        ~Output() override = default;

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
