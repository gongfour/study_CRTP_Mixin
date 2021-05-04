
#include <string>
#include <iostream>

// Original Class
class Name
{
    std::string m_firstName;
    std::string m_lastName;

public:
    Name(std::string firstName, std::string lastName)
        : m_firstName(firstName)
        , m_lastName(lastName)
    {
    }

    void print() const
    {
        std::cout << m_lastName << ", " << m_firstName << '\n';
    }
};

// This is the CRTP
template <class Printable>
struct RepeatPrint : Printable // public inheritance (STRUCT)
{
    // copy constructor or move constructor
    explicit RepeatPrint(const Printable& printable) : Printable(printable) 
    {}

    void repeat(unsigned int n) const
    {
        while(n-- > 0)
            this->print();
    }
};

// It is useful
template <class Printable>
RepeatPrint<Printable> repeatPrint(const Printable& printable)
{
    return RepeatPrint<Printable>(printable);
}

int main(int argc, char const *argv[])
{
    Name ned("Eddard", "Stark");
    repeatPrint(ned).repeat(10);
    repeatPrint(Name{"A", "B"}).repeat(2);

    RepeatPrint<Name> print(ned);
    print.repeat(5);
    print.print();
    return 0;
}
