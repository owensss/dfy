#ifndef _BLANK_HPP_
#define _BLANK_HPP_

#include "Item.hpp"

class Blank : public Item
{
	public: 
        void ReadStream(std::istream& is) {};
        Blank() {this->setPixmap(QPixmap("blank.png", "png"));};
        ~Blank() {};
};
#endif
