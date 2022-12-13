#pragma once

#include <string>
#include "CShowable.hpp"

class CSong : public CShowable {
private:
    std::string author, title;
public:
    CSong(std::string author = "-", std::string title = "-");

    ~CSong();

    std::string show() final;
};
