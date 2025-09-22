







inline
uint64_t rw::core::timer::Stopwatch::GetCPUCycle()
{
    ;
    uint64_t time;
    asm volatile ("mfspr %0, 268": [tb] "=r" (time));
    return time * rw::core::timer::mTimeBaseCoefficient;




}

inline
uint64_t rw::core::timer::Stopwatch::GetStopwatchCycle()
{
    ;
    uint64_t time;
    asm volatile ("mftb %0" : "=r"(time));
    return time;
}
