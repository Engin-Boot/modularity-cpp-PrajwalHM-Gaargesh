#include "ColorPair.h"
#include <cassert>

namespace TelCoColorCoder
{
	MajorColor ColorPair::getMajor()
	{
		return majorColor;
	}
	MinorColor ColorPair::getMinor()
	{
		return minorColor;
	}
	std::string ColorPair::ToString()
	{
		std::string colorPairStr = MajorColorNames[majorColor];
		colorPairStr += " ";
		colorPairStr += MinorColorNames[minorColor];
		return colorPairStr;
	}
	ColorPair ColorPair::GetColorFromPairNumber(int pairNumber)
	{
		int zeroBasedPairNumber = pairNumber - 1;
		MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
		MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
		return ColorPair(majorColor, minorColor);
	}
	int ColorPair::GetPairNumberFromColor(MajorColor major, MinorColor minor)
	{
		return major * numberOfMinorColors + minor + 1;
	}
}

void testNumberToPair(int pairNumber, TelCoColorCoder::MajorColor expectedMajor, TelCoColorCoder::MinorColor expectedMinor)
{
	TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::ColorPair::GetColorFromPairNumber(pairNumber);
	std::cout << "Got pair " << colorPair.ToString() << std::endl;
	assert(colorPair.getMajor() == expectedMajor);
	assert(colorPair.getMinor() == expectedMinor);
}
void testPairToNumber(TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor, int expectedPairNumber)
{
	int pairNumber = TelCoColorCoder::ColorPair::GetPairNumberFromColor(major, minor);
	std::cout << "Got pair number " << pairNumber << std::endl;
	assert(pairNumber == expectedPairNumber);
}

