#include <iostream>
#include <cstring>
#include <string>
#include "ErrorState.h"
using namespace std;

namespace AMA{
    ErrorState::ErrorState(const char* errorMessage){
        if (errorMessage == nullptr){
            AddressMessage = nullptr;
        }
        else{
            AddressMessage = new char[strlen(errorMessage) + 1];
            strcpy(AddressMessage, errorMessage);
        }
    }

    ErrorState::~ErrorState(){
        delete[] AddressMessage;
        AddressMessage = nullptr;
    }

    void ErrorState::clear(){
        delete[] AddressMessage;
        AddressMessage = nullptr;
    }

    bool ErrorState::isClear() const{
		return (AddressMessage == nullptr);
    }

    void ErrorState::message(const char* str){
        delete[] AddressMessage;
        AddressMessage = new char[strlen(str) + 1];
        strcpy(AddressMessage, str);
    }

    const char* ErrorState::message() const{
        return AddressMessage;
    }

    std::ostream& operator<<(std::ostream& os, const ErrorState& em){
        if (!em.isClear())
        {
            os << em.message();
        }
        return os;
    }
}