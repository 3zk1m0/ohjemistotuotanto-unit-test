#include "gtest/gtest.h"
#include "Date.h"

TEST(Date, default_constructor) {

    Date d1;
    ASSERT_EQ(d1.get_day(), 1);
    ASSERT_EQ(d1.get_month(), 1);
    ASSERT_EQ(d1.get_year(), 1900);
}

TEST(Date, argument_constructor) {
    Date d1{1,2,2000};
    ASSERT_EQ(d1.get_day(), 1);
    ASSERT_EQ(d1.get_month(), 2);
    ASSERT_EQ(d1.get_year(), 2000);
}

TEST(Date, copy_constructor) {
    Date d1{1,2,2000};
    Date d2{d1};
    ASSERT_EQ(d1.get_day(), 1);
    ASSERT_EQ(d1.get_month(), 2);
    ASSERT_EQ(d1.get_year(), 2000);
}

TEST(Date, week_later) {

    Date d1{};
    Date d2 = d1.week_later(d1);
    ASSERT_EQ(d2.get_day(), 8);
    ASSERT_EQ(d2.get_month(), 1);
    ASSERT_EQ(d2.get_year(), 1900);

    ASSERT_EQ(d2.days_between(d1), 7);
}

TEST(Date, days_between) {
    Date d1{1,1,2000};
    Date d2{15,1,2000};
    ASSERT_EQ(d2.days_between(d1), 14);
}