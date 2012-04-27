#ifndef _DICE_HPP_
#define _DECE_HPP_

class Dice
{
	public:
		static const unsigned MAX_NUM = 6;
	public:
		Dice(void);
		~Dice(void) {}
		operator int(void) {return value;}
		void Generate(void);
		void SetValue(int _value) {value = _value;}
		void SetTimes(int _times) {times = _times;}
		int Value(void) const {return value;}
		int Times(void) const {return times;}
	private:
		int value;
		int times;
};

#endif
