#include<gtest/gtest.h>
#include<vector>
#include "galbalas.cpp"

TEST(galBaltestas, vidurkis)
{
    EXPECT_DOUBLE_EQ(8.92, galBalas_vidurkis(std::vector<int>{10,10,5,9,10},9));
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}