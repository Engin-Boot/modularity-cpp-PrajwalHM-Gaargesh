#include <string>
#include <iostream>

namespace TelCoColorCoder
{
	enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
	enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

	static const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
	static int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

	static const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
	static int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

	class ColorPair
	{
	private:
		MajorColor majorColor;
		MinorColor minorColor;
	public:
		ColorPair() = default;
		ColorPair(MajorColor major_color, MinorColor minor_color) : majorColor((major_color)), minorColor(minor_color) {}
		MajorColor getMajor();
		MinorColor getMinor();
		std::string ToString();
		static ColorPair GetColorFromPairNumber(int pairNumber);
		static int GetPairNumberFromColor(MajorColor major, MinorColor minor);
	};
}
void testNumberToPair(int pairNumber, TelCoColorCoder::MajorColor expectedMajor, TelCoColorCoder::MinorColor expectedMinor);
void testPairToNumber(TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor, int expectedPairNumber);

static void ToString()
{
	for(int i = 1; i < TelCoColorCoder::numberOfMajorColors*TelCoColorCoder::numberOfMinorColors; ++i)
	{
		std::cout << std::to_string(i) << " : " << TelCoColorCoder::ColorPair::GetColorFromPairNumber(i).ToString() << std::endl;
	}
}