
#include <string>
#include <iostream>


template <class Printable>
struct RepeatPrint
{
    void repeat(unsigned int n)
    {
        while(n-- > 0)
            static_cast<Printable*>(this)->print(); // 상속 받을 클래스로 형변환 가능
    }
};

// Original Class
// you should inherit a RepeatPrint Interface
// This is the CRTP: 자기 자신을 베이스 클래스의 템플릿 인자로 상속받는 것
class Name : public RepeatPrint<Name>
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

int main(int argc, char const *argv[])
{
    Name ned("Eddard", "Stark");
    ned.repeat(10);
    return 0;
}
