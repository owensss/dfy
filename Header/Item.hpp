#ifndef _ITEMS_HPP_
#define _ITEMS_HPP_
#include "Object.hpp"
#include <iostream>

class Item
{
	public:
		Item() {};
		virtual ~Item() {};
        virtual void ReadStream(std::istream&) = 0;
};

#endif
