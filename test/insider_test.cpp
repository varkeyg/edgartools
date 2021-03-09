#include <gtest/gtest.h>
#include <iostream>
#include <common.h>

using namespace std;

TEST(httpGetTest, CurlTest)
{
    // Berkshire Hathaway 13F holdings filing for 2020-12-31, filed on 2021-02-16
    auto url = string("https://www.sec.gov/Archives/edgar/data/1067983/000095012321002786/0000950123-21-002786.txt");
    auto response = httpGet(url);
    auto size = response.size();
    LOG(INFO) << "Size of output: " << size << endl;
    EXPECT_TRUE(size);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}