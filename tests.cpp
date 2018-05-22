#include<gtest/gtest.h>
#include<vector>
#include "galbalas.cpp"

TEST(galBaltestas, pagalvidurki)
{
    EXPECT_DOUBLE_EQ(10, galBalas_vidurkis(std::vector<int>(10,10),10));
}

TEST (galBaltestas, pagalmediana)
{
    EXPECT_DOUBLE_EQ(10.0, galBalas_vidurkis(std::vector<int>(10,10.0),10.0));
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}