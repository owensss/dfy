#ifndef _DICE_HPP_
#define _DICE_HPP_

class Dice
{
	public:
		static const unsigned MAX_NUM = 6;
	public:
        Dice(void);
		~Dice(void) {}
        operator int() {return value;}
        void Generate(void);
        void SetValue(int _value);
        void SetTimes(int _times) {times = _times;}
        int Value(void) const {return value;}
        int Times(void) const {return times;}
        int Min(void) { return times; }
        int Max(void) { return times*MAX_NUM; }
    private:
		int value;
        int times;
};

#endif
