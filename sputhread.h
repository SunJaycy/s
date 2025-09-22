

















#include <sys/event.h>






#include <sys/paths.h>


#include <sys/spu_image.h>




















namespace rw
{




























class SpuThread
{
public:

    sys_event_queue_t sendQueue;
    sys_event_port_t ppuSendPort;
    sys_event_queue_t receiveQueue;


    sys_spu_thread_group_t threadGroup;


    sys_spu_thread_t thread;



    sys_spu_image threadImage;



    sys_event_queue_t spuPrintfSendQueue;


    RwBool InitializeSPUs();

    RwBool InitializeThreadGroup(const char* groupName, int32_t priority);

    RwBool InitializeThread(const char* elfName, const char* threadName, uint32_t arg1, uint64_t arg2);

    RwBool Initialize(const char* elfName, const char* groupName, const char* threadName, int32_t priority);
    RwBool Initialize(const char* elfName, const char* groupName, const char* threadName, int32_t priority, uint32_t arg1, uint64_t arg2);

    RwBool InitializeSpuSendEventQueue(uint32_t port,
                                       uint32_t key = 0x00,
                                       int32_t size = 127);

    RwBool InitializeSpuReceiveEventQueue(uint32_t queueNum,
                                          uint32_t port = 0x01,
                                          int32_t size = 127);

    RwBool InitializeSpuPrintfEventQueue();

    RwBool InitializeSpuPrintfHandlerThread();

    RwBool StartThreadGroup();

    RwBool WaitForThreadGroup(int32_t& exitCause, int32_t& exitStatus);

    RwBool Release();
};




}
