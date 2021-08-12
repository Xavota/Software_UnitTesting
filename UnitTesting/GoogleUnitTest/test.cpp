#include "pch.h"
#include "../UnitTesting/MathString.h"

TEST(UnitTesting, StringMath) {
	EXPECT_TRUE(MathString::AreEqual("Hola Mundo", MathString::Concat("Hola ", "Mundo")));

	EXPECT_TRUE(MathString::AreEqual("aloH", MathString::Reverse("Hola").c_str()));

	EXPECT_EQ(6, MathString::FindFirst("StringFoundyes", "Found"));

	EXPECT_TRUE(MathString::AreEqual({ 0, 12, 16 },
		                                   MathString::FindAll("No Yes yeah NopeNo On no", "No")));

	EXPECT_TRUE(MathString::AreEqual("Profe", 
	                                           MathString::SubstractFirst("ProfePelon", "Pelon")));

	EXPECT_TRUE(MathString::AreEqual("Yes No Maybe I don't know",
		           MathString::SubstractAll("Test Yes No Test Maybe Test I don't know", "Test ")));

	EXPECT_TRUE(MathString::AreEqual({ "1", "2", "3", "11", "", "67" },
		                                                  MathString::Split("1,2,3,11,,67", ',')));

	EXPECT_TRUE(MathString::AreEqual("ABFHJSYaghks", 
												 MathString::OrderAscend("BSJHFAYahksg").c_str()));

	EXPECT_TRUE(MathString::AreEqual("skhgaYSJHFBA", 
												MathString::OrderDescend("BSJHFAYahksg").c_str()));

	EXPECT_TRUE(MathString::CheckPalindrome("aajehe121ehejaa"));
	EXPECT_FALSE(MathString::CheckPalindrome("aabbcc"));

	std::string sTest = "Test";

	sTest = MathString::Concat(sTest, MathString::Concat(".Unit", ".Test"));
	EXPECT_TRUE(MathString::AreEqual("Test.Unit.Test", sTest.c_str()));

	std::vector<std::string> vTest = MathString::Split(sTest, '.');
	EXPECT_TRUE(MathString::AreEqual({ "Test", "Unit", "Test" }, vTest));

	sTest = MathString::Concat(vTest[0], MathString::Reverse(vTest[2]));
	EXPECT_TRUE(MathString::AreEqual("TesttseT", sTest.c_str()));
	EXPECT_TRUE(MathString::CheckPalindrome(sTest));
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}