/**
 * @file: utest/core/timer.test.cc
 * @author: sailing-innocent
 * @create: 2022-10-15
 * @desp: testing suites for sail core timer
 * @done: TODO
*/

#include <gtest/gtest.h>
#include <sail/core.h>
#include <windows.h>

using namespace sail;

TEST(SAIL_TEST_TIMER, CREATE_TIMER)
{
    Timer<> timer1("Hello");
    timer1.tic();
    Sleep(1000);
    uint64 t = timer1.toc();
    Sleep(500);
    timer1.toc();
}
