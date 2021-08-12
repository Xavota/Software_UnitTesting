#include "pch.h"
#include "CppUnitTest.h"

#include "../UnitTesting/MathString.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual("Hola Mundo", MathString::Concat("Hola ", "Mundo").c_str());

			Assert::AreEqual("aloH", MathString::Reverse("Hola").c_str());

			Assert::AreEqual(6, MathString::FindFirst("StringFoundyes", "Found"));

			Assert::IsTrue(MathString::AreEqual({0, 12, 16}, 
			                               MathString::FindAll("No Yes yeah NopeNo On no", "No")));
			Assert::AreEqual("Profe", MathString::SubstractFirst("ProfePelon", "Pelon").c_str());

			Assert::AreEqual("Yes No Maybe I don't know", 
			MathString::SubstractAll("Test Yes No Test Maybe Test I don't know", "Test ").c_str());

			Assert::IsTrue(MathString::AreEqual({ "1", "2", "3", "11", "", "67"}, 
			                                              MathString::Split("1,2,3,11,,67", ',')));

			Assert::AreEqual("ABFHJSYaghks", MathString::OrderAscend("BSJHFAYahksg").c_str());

			Assert::AreEqual("skhgaYSJHFBA", MathString::OrderDescend("BSJHFAYahksg").c_str());

			Assert::IsTrue(MathString::CheckPalindrome("aajehe121ehejaa"));
			Assert::IsFalse(MathString::CheckPalindrome("aabbcc"));

			std::string sTest = "Test";

			sTest = MathString::Concat(sTest, MathString::Concat(".Unit", ".Test"));
			Assert::AreEqual("Test.Unit.Test", sTest.c_str());

			std::vector<std::string> vTest = MathString::Split(sTest, '.');
			Assert::IsTrue(MathString::AreEqual({ "Test", "Unit", "Test" }, vTest));

			sTest = MathString::Concat(vTest[0], MathString::Reverse(vTest[2]));
			Assert::AreEqual("TesttseT", sTest.c_str());
			Assert::IsTrue(MathString::CheckPalindrome(sTest));
		}
	};
}
