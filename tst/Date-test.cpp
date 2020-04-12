#include "gtest/gtest.h"
#include "Date.h"

TEST(Constuctor, _default) {

    Date d1;
    ASSERT_EQ(d1.get_day(), 1);
    ASSERT_EQ(d1.get_month(), 1);
    ASSERT_EQ(d1.get_year(), 1900);
}

TEST(Constuctor, argument) {
    Date d1{1,2,2000};
    ASSERT_EQ(d1.get_day(), 1);
    ASSERT_EQ(d1.get_month(), 2);
    ASSERT_EQ(d1.get_year(), 2000);
}

TEST(Constuctor, copy) {
    Date d1{1,2,2000};
    Date d2{d1};
    ASSERT_EQ(d1.get_day(), 1);
    ASSERT_EQ(d1.get_month(), 2);
    ASSERT_EQ(d1.get_year(), 2000);
}

TEST(Week_later, basic) {

    Date d1{};
    Date d2 = d1.week_later(d1);
    ASSERT_EQ(d2.get_day(), 8);
    ASSERT_EQ(d2.get_month(), 1);
    ASSERT_EQ(d2.get_year(), 1900);

    ASSERT_EQ(d2.days_between(d1), 7);
}

TEST(Days_between, basic) {
    Date d1{1,1,2000};
    Date d2{15,1,2000};
    ASSERT_EQ(d2.days_between(d1), 14);
}

TEST(Days_between, leep_year) {
    Date d1{1,1,2020};
    Date d2{25,9,2020};
    ASSERT_EQ(d2.days_between(d1), 267);
}


TEST(Days_since_newyear, basic) {
    Date d1{10,1,2000};
    ASSERT_EQ(d1.days_since_newyear(), 9);
}

TEST(Days_since_newyear, leep_year) {
    Date d1{1,12,2020};
    ASSERT_EQ(d1.days_since_newyear(), 334);
}