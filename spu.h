

















#include <sys/raw_spu.h>
#include <sys/spu_initialize.h>
#include <stddef.h>
#include <sys/ppu_thread.h>
#include <sys/spu_utility.h>

















namespace rw
{




























class SPU
{
public:

    static void ManagerInitialize(uint32_t numProcessors);
    static void ManagerRelease();

    void Initialize();
    void Release();


    uint32_t GetMail();

    void PutMail(uint32_t value);
    void PutMail(int32_t value);
    void SendSignal1(uint32_t value);
    void SendSignal2(uint32_t value);

    void Execute(const RwChar *filename);
    void WaitForCompletion();
    void WaitForDMA(uint32_t tagMask);

private:

    static const rw::HostPtr m_baseAddress = 0x00000000e0000000;
    static const rw::HostPtr m_offset = 0x0000000000100000;

    static const rw::HostPtr m_tagQueryTypeAddress = 0x00000000e0043204;

    static const rw::HostPtr m_tagQueryMaskAddress = 0x00000000e004321c;

    static const rw::HostPtr m_tagStatusAddress = 0x00000000e004322c;

    static const rw::HostPtr m_spuMailboxAddress = 0x00000000e004400c;

    static const rw::HostPtr m_runControlAddress = 0x00000000e004401c;
    static const uint32_t m_runControlStop = 0x00000000;
    static const uint32_t m_runControlRun = 0x00000001;
    static const uint32_t m_runControlIsolateExit = 0x00000002;
    static const uint32_t m_runControlIsolateLoad = 0x00000003;

    static const rw::HostPtr m_statusAddress = 0x00000000e0044024;
    static const uint32_t m_statusRunMask = 0x00000001;

    static const rw::HostPtr m_nextProgramCounterAddress = 0x00000000e0044034;
    static const uint32_t m_memorySize = 0x00040000;

    static const rw::HostPtr m_signal1Address = 0x00000000e005400c;

    static const rw::HostPtr m_signal2Address = 0x00000000e005c00c;

    rw::HostPtr LocalToEffectiveAddress(uint32_t localAddress);
    uint32_t GetStatus();
    uint32_t GetTagStatus();
    void SetNextProgramCounter(uint32_t localAddress);
    void SetRunControl(uint32_t value);
    void SetTagQueryMask(uint32_t value);
    void SetTagQueryType(uint32_t value);

    sys_raw_spu_t m_id;

    static const uint64_t m_statusMask = 1;
    static const uint32_t m_bufferSize = 256;
    static const uint32_t m_flagZero = 1;
    static const uint32_t m_flagUpper = 2;
    static const uint32_t m_flagSigned = 4;

    uint32_t ToString(RwChar *buffer, uint32_t value, uint32_t base, uint32_t flags, uint32_t align);
    void Printf(uint32_t localAddress);
    void HandleInterrupt();
    static void InterruptHandler(uint64_t argument);

    sys_ppu_thread_t m_thread;
    sys_interrupt_tag_t m_tag;
    sys_interrupt_thread_handle_t m_handle;
};



inline rw::HostPtr SPU::LocalToEffectiveAddress(uint32_t localAddress)
{
    ;
    ;
    return m_baseAddress + m_id * m_offset + localAddress;
}

inline uint32_t SPU::GetMail()
{
    ;
    uint32_t value;
    sys_raw_spu_read_puint_mb(m_id, &value);
    return value;
}

inline void SPU::PutMail(uint32_t value)
{
    ;
    *reinterpret_cast<volatile uint32_t *>(m_spuMailboxAddress + m_id * m_offset) = value;
    return;
}

inline void SPU::PutMail(int32_t value)
{
    ;
    *reinterpret_cast<volatile int32_t *>(m_spuMailboxAddress + m_id * m_offset) = value;
    return;
}

inline void SPU::SetNextProgramCounter(uint32_t localAddress)
{
    ;
    *reinterpret_cast<volatile uint32_t *>(m_nextProgramCounterAddress + m_id * m_offset) = localAddress;
    return;
}

inline void SPU::SetRunControl(uint32_t value)
{
    ;
    *reinterpret_cast<volatile uint32_t *>(m_runControlAddress + m_id * m_offset) = value;
    return;
}

inline uint32_t SPU::GetStatus()
{
    ;
    return *reinterpret_cast<volatile uint32_t *>(m_statusAddress + m_id * m_offset);
}

inline void SPU::SetTagQueryMask(uint32_t value)
{
    ;
    *reinterpret_cast<volatile uint32_t *>(m_tagQueryMaskAddress + m_id * m_offset) = value;
    return;
}

inline void SPU::SetTagQueryType(uint32_t value)
{
    ;
    *reinterpret_cast<volatile uint32_t *>(m_tagQueryTypeAddress + m_id * m_offset) = value;
    return;
}

inline uint32_t SPU::GetTagStatus()
{
    ;
    return *reinterpret_cast<volatile uint32_t *>(m_tagStatusAddress + m_id * m_offset);
}


inline void SPU::ManagerInitialize(uint32_t numProcessors)
{
    ;
    sys_spu_initialize(numProcessors, numProcessors);
    return;
}

inline void SPU::ManagerRelease()
{
    ;
    return;
}

inline void SPU::WaitForCompletion()
{
    ;
    do
    {
        asm volatile ("eieio");
    } while (0 != (m_statusRunMask & GetStatus()));
    return;
}

inline void SPU::WaitForDMA(uint32_t tagMask)
{
    ;
    SetTagQueryMask(tagMask);
    do
    {
        asm volatile ("eieio");
    } while (tagMask != GetTagStatus());
    return;
}

inline void SPU::SendSignal1(uint32_t value)
{
    ;
    *reinterpret_cast<volatile int32_t *>(m_signal1Address + m_id * m_offset) = value;
    return;
}

inline void SPU::SendSignal2(uint32_t value)
{
    ;
    *reinterpret_cast<volatile int32_t *>(m_signal2Address + m_id * m_offset) = value;
    return;
}

}
