
#include "Contact.hpp"
Contact::Contact(const std::string firstName, const std::string lastName, const std::string nickname, const std::string phoneNumber, const std::string darkestSecret)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}
Contact::Contact(){};
void Contact::printContact(int j)
{
    std::cout << "|" << std::setw(10) << j << "|";
    std::cout << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|";
    std::cout << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|";
    std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "|" << std::endl;
}

std::string Contact::getFirstName()
{
    return firstName;
}
std::string Contact::getLastName()
{
    return lastName;
}
std::string Contact::getNickname()
{
    return nickname;
}
std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}
std::string Contact::getDarkestSecret()
{
    return darkestSecret;
}