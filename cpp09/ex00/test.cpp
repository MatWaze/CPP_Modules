#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include <iostream>
#include "BitcoinExchange.hpp"

BitcoinExchange createBitcoin(const std::string &line);

// bool  CHECK_OUTPUT(std::string str)
// {
//     std::streambuf* oldBuf = std::cout.rdbuf();
//     std::ostringstream os;
//     std::cout.rdbuf(os.rdbuf());


//     std::cout.rdbuf(oldBuf);

//     std::string ans = "";

//     return os.str() == ans;
// }


TEST_CASE("Testing createBitcoin correct output")
{
    BitcoinExchange btc0_00_1 = createBitcoin("     2004-04-16   | +1");
    BitcoinExchange btc0_00_2 = createBitcoin("2010-08-19 | +1.000       ");
    BitcoinExchange btc0_06_1 = createBitcoin("2010-08-30    |   1.00");
    BitcoinExchange btc0_06_2 = createBitcoin("     2010-09-15   |   1.0  ");
    BitcoinExchange btc0_07_1 = createBitcoin("2010-08-20 |    1");
    BitcoinExchange btc0_15 = createBitcoin("2010-09-16     | 1");
    BitcoinExchange btc13_53 = createBitcoin("2012-12-11 | 1");
    BitcoinExchange btc35365_2 = createBitcoin("2021-07-26 | 1");
    BitcoinExchange btc47115_93 = createBitcoin("2022-03-29 | 1");
    BitcoinExchange btc_two = createBitcoin("2022-03-29 | 2.0");
    BitcoinExchange btc44334_33 = createBitcoin("2022-03-25 | 1");

    BitcoinExchange btc_bc = createBitcoin("0-01-01 | 232");
    BitcoinExchange btc_old = createBitcoin("1240-06-21 | 999");
    BitcoinExchange btc_future = createBitcoin("2147483647-12-31 | 1");

    CHECK_EQ(btc13_53.compute(), 13.53f);
    CHECK_EQ(btc0_00_1.compute(), 0.0f);
    CHECK_EQ(btc0_00_2.compute(), 0.0f);
    CHECK_EQ(btc0_07_1.compute(), 0.07f);
    CHECK_EQ(btc0_06_1.compute(), 0.06f);
    CHECK_EQ(btc0_06_2.compute(), 0.06f);
    CHECK_EQ(btc0_15.compute(), 0.15f);
    CHECK_EQ(btc35365_2.compute(), 35365.2f);
    CHECK_EQ(btc44334_33.compute(), 44334.33f);
    CHECK_EQ(btc47115_93.compute() * 2, btc_two.compute());
    CHECK_EQ(btc_bc.compute(), 0.0f);
    CHECK_EQ(btc_old.compute(), 0.0f);
    CHECK_EQ(btc_future.compute(), btc47115_93.compute());
}

TEST_CASE("Check for InvalidInputException")
{
    CHECK_THROWS_AS(createBitcoin(""), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("4545995954"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("ofoffg"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("445 545454 545454 5454"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("2010-03-23 92933"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("2010-03-23 2010-03-23"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("2010-03-23 2010-03-23 2"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("2010-03-23 / 3"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("2010-03-23 \\ 3"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("2010-03-23 | 3434 | 4343"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("2010-03-23 | 2010-03-23 | 2010-03-23"), BitcoinExchange::InvalidInputException);

    CHECK_THROWS_AS(createBitcoin("2012-02-03|3"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 |3"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03| 3"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03|"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("|3"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("|"), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin(" | "), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("    |    "), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("    2012-02-03     |    "), BitcoinExchange::InvalidInputException);
    CHECK_THROWS_AS(createBitcoin("            |   3 "), BitcoinExchange::InvalidInputException);

}

TEST_CASE("Check for InvalidDateException")
{
    CHECK_THROWS_AS(createBitcoin("fdfdfd | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("ffff-ff-ff | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("ffff | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2022-0f-22 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2222-12-1f | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("222f-12-11 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("-- | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2012-01- | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2012--12 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("-02-12 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("- 02 -12 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("  - -  12 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("- - | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2012- 12- 3- | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2012 - 12 - 03 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("-2012 -12 -03 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("-2012-12-03 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2012-12-03- | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2012-12-03    - | 443"), BitcoinExchange::InvalidDateException);

    CHECK_THROWS_AS(createBitcoin("23343433 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2147483648 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("214748364999999 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("21474836472147483647214748364793943949493439439349439439 | 443"),
        BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("-93939320 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("0 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2 2 | 443"), BitcoinExchange::InvalidDateException);

    CHECK_THROWS_AS(createBitcoin("0-0 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("0-0-0 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2012-12 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2012-12-32 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2009-00-01 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2009-01-00 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2012-1-2 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2012-5-12 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2018-9-11 | 443"), BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("20182018201820182018201820182018-99999999999999999999999999999999-1111111111111111111111 | 443"),
        BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("2019-09-11203033204030430430430430430430430404304340403430403430430430430430043 | 443"),
        BitcoinExchange::InvalidDateException);
    CHECK_THROWS_AS(createBitcoin("20182094394949439439494349343949439349344318201820182018201820182018-3-4 | 443"),
        BitcoinExchange::InvalidDateException);
}

TEST_CASE("Check for InvalidValueException")
{
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | -1"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | -39949349434943943943943949934943944399"),
        BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | 493494394394349439394939949349434943943943943949934943944399"),
        BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | 230302"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | -0.00000000000000000000000001"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | -0.1"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | -1001"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | 1001"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | 100a"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | jjerrjerej"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | A"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | /"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | 1000.000d"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | 1000.0001"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | 1000.9"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | 1000abc"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | -100"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | ++100"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | +"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | +   "), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | -"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | -   "), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | 44-"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | 44+"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | 00+10"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | 10-01"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | 10=01"), BitcoinExchange::InvalidValueException);
    CHECK_THROWS_AS(createBitcoin("2012-02-03 | 1-001"), BitcoinExchange::InvalidValueException);
}