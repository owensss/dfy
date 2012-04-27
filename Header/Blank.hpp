#include "Item.hpp"

class Blank : public Item
{
	public: 
		void ReadStream(std::istream& is);
		Blank();
		~Blank();
};
