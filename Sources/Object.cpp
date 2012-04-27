#include "../Header/Object.hpp"

#ifdef _DEBUG_
#include <iostream>
#endif

Object::Object()
{
#ifdef _DEBUG_
	cout << "# Object Create\n";
#endif
	// nothing
}

Object::~Object()
{
#ifdef _DEBUG_
	cout << "# Object Destruct\n";
#endif
}

