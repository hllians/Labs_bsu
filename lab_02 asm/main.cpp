#include <iostream>
#include <iomanip>
#include <cstdint>
#include "lab2_lib.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

int main()
{
    auto console = spdlog::stdout_color_mt("console");
    spdlog::set_default_logger(console);
    spdlog::set_level(spdlog::level::info);

    spdlog::info("Lab02");

    int a1;
    std::cout << "enter a for task 1 (positive): ";
    std::cin >> a1;
    int res1 = calcExpration1(a1);
    std::cout << "result (a⁵ + a³ + a) = " << res1 << "\n\n";

    int a2;
    std::cout << "enter a for task 2 (non-zero): ";
    std::cin >> a2;
    int res2 = calcExpration2(a2);
    std::cout << "result ((a⁵ + 2·(a²–4) + a) / a³) = " << res2 << "\n\n";

    int16_t A1 = 0x1234, A2 = 0x5678, A3 = 0x9ABC;
    int16_t B1 = 0xDEF0, B2 = 0x1111, B3 = 0x2222;
    int16_t C1, C2, C3;

    spdlog::info("task 3: 48-bit addition");
    spdlog::info("A = {:04X}{:04X}{:04X}", uint16_t(A3), uint16_t(A2), uint16_t(A1));
    spdlog::info("B = {:04X}{:04X}{:04X}", uint16_t(B3), uint16_t(B2), uint16_t(B1));

    add48(A1, A2, A3, B1, B2, B3, C1, C2, C3);

    std::cout << "sum (hex words): "
              << std::hex << std::setfill('0')
              << std::setw(4) << uint16_t(C3) << " "
              << std::setw(4) << uint16_t(C2) << " "
              << std::setw(4) << uint16_t(C1) << std::dec << "\n";

    uint64_t full = (uint64_t(uint16_t(C3)) << 32) |
                    (uint64_t(uint16_t(C2)) << 16) |
                    uint64_t(uint16_t(C1));
    std::cout << "full number in decimal: " << full << "\n";

    spdlog::info("program finished.");
    return 0;
}