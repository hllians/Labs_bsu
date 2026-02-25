#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/null_sink.h>
#include "lab2_lib.h"

class Environment : public ::testing::Environment {
public:
    void SetUp() override {
        auto null_sink = std::make_shared<spdlog::sinks::null_sink_mt>();
        auto logger = std::make_shared<spdlog::logger>("null", null_sink);
        spdlog::set_default_logger(logger);
        spdlog::set_level(spdlog::level::off);
    }
};

TEST(CalcExpration1Test, PositiveValues) {
    EXPECT_EQ(calcExpration1(1), 3);
    EXPECT_EQ(calcExpration1(2), 42);
    EXPECT_EQ(calcExpration1(3), 273);
    EXPECT_EQ(calcExpration1(5), 3255);
}

TEST(CalcExpration1Test, Zero) {
    EXPECT_EQ(calcExpration1(0), 0);
}

TEST(CalcExpration2Test, PositiveValues) {
    EXPECT_EQ(calcExpration2(1), (1 + 2*(1-4) + 1) / 1);  
    EXPECT_EQ(calcExpration2(2), (32 + 2*(4-4) + 2) / 8);
    EXPECT_EQ(calcExpration2(3), (243 + 2*(9-4) + 3) / 27);
    EXPECT_EQ(calcExpration2(4), (1024 + 2*(16-4) + 4) / 64);
}

TEST(CalcExpration2Test, NegativeValues) {
    EXPECT_EQ(calcExpration2(-1), ( -1 + 2*(1-4) -1 ) / -1);
    EXPECT_EQ(calcExpration2(-2), ( -32 + 2*(4-4) -2 ) / -8);
    EXPECT_EQ(calcExpration2(-3), ( -243 + 2*(9-4) -3 ) / -27);
    EXPECT_EQ(calcExpration2(-3), 8);
}

TEST(CalcExpration2Test, DivisionByZero) {
    EXPECT_EQ(calcExpration2(0), 0);
}

TEST(Add48Test, SimpleSum) {
    int16_t A1=1, A2=2, A3=3, B1=4, B2=5, B3=6;
    int16_t C1, C2, C3;
    add48(A1, A2, A3, B1, B2, B3, C1, C2, C3);
    uint64_t res = (uint64_t(uint16_t(C3)) << 32) | (uint64_t(uint16_t(C2)) << 16) | uint64_t(uint16_t(C1));
    uint64_t sum = (uint64_t(uint16_t(A3)) << 32) | (uint64_t(uint16_t(A2)) << 16) | uint64_t(uint16_t(A1)) +
                   (uint64_t(uint16_t(B3)) << 32) | (uint64_t(uint16_t(B2)) << 16) | uint64_t(uint16_t(B1));
    EXPECT_EQ(res, sum);
}

TEST(Add48Test, SumWithCarry) {
    int16_t A1 = 0xFFFF, A2 = 0xFFFF, A3 = 0x0000;
    int16_t B1 = 0x0001, B2 = 0x0000, B3 = 0x0000;
    int16_t C1, C2, C3;
    add48(A1, A2, A3, B1, B2, B3, C1, C2, C3);
    EXPECT_EQ(uint16_t(C1), 0x0000);
    EXPECT_EQ(uint16_t(C2), 0x0000);
    EXPECT_EQ(uint16_t(C3), 0x0001);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::AddGlobalTestEnvironment(new Environment);
    return RUN_ALL_TESTS();
}