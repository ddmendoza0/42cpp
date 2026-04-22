#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
    private:
        std::string _FirstName;
        std::string _LastName;
        std::string _NickName;
        std::string _PhoneNum;
        std::string _Secret;

    public:
        Contact();
        ~Contact();

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNum() const;
        std::string getSecret() const;
        
        bool    setContact();
};

#endif