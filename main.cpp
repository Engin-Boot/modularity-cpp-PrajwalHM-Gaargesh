#include "ColorPair.h"

int main()
{
	testNumberToPair(4, TelCoColorCoder::MajorColor::WHITE, TelCoColorCoder::BROWN);
	testNumberToPair(5, TelCoColorCoder::MajorColor::WHITE, TelCoColorCoder::SLATE);

	testPairToNumber(TelCoColorCoder::MajorColor::BLACK, TelCoColorCoder::ORANGE, 12);
	testPairToNumber(TelCoColorCoder::MajorColor::VIOLET, TelCoColorCoder::SLATE, 25);

	ToString();
}