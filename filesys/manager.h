


















#include <rw/core/filesys/detail/list.h>

namespace rw
{
    namespace core
    {

        namespace filesys
        {

            class Device;
            class Handle;
            class DeviceDriver;










            struct Options
            {



                Options();











                Options(rw::core::debug::Channel *FileSysPrintChannel,
                    rw::IResourceAllocator *Allocator);








                Options(rw::core::debug::Channel *FileSysPrintChannel,
                    rw::IResourceAllocator *Allocator,
                    unsigned int maxSearchLocations,
                    unsigned int maxSearchPathLength);






                debug::Channel * mPrintChannel;








                IResourceAllocator * mAllocator;





                unsigned int mMaxSearchLocations;





                unsigned int mMaxSearchPathLength;
            };







            class Manager
            {
            public:
                static Manager *CreateInstance(const Options &options);
                static Manager *GetInstance();
                static void DestroyInstance();
                static bool IsInitialized()
                {
                    ;
                    return rw::core::filesys::Manager::sInstance != 0;
                }






































                bool ReadFileFailCallback() const
                {
                    ;
                    return mReadFileFailCallback();
                }










                void SetReadFileFailCallback(bool (*handler)(void))
                {
                    ;
                    mReadFileFailCallback = handler;
                    return;
                }
















                enum DeviceFlags
                {
                    DEVICEFLAG_TYPE_PHYSICAL = 0x0,
                    DEVICEFLAG_TYPE_VIRTUAL = 0x1
                };

                Device * RegisterDevice(DeviceDriver *DeviceToAdd, unsigned int flags = DEVICEFLAG_TYPE_PHYSICAL) const;
                bool UnregisterDevice(Device *DeviceToRemove) const;
                void SetSearchPath(const char *NewSearchPath);






                enum SearchPathFlags
                {
                    SEARCHPATH_ADD_TO_TAIL,
                    SEARCHPATH_ADD_TO_HEAD
                };

                void AddSearchLocation(const char *NewLocation, unsigned int flags = SEARCHPATH_ADD_TO_TAIL);
                bool RemoveSearchLocation(const char *LocationToRemove);


                enum ReadSchedulePolicy
                {


                    READ_SCHEDULE_POLICY_FCFS,

















                    READ_SCHEDULE_POLICY_SORTED
                };

                void SetReadSchedulePolicy(ReadSchedulePolicy newPolicy)
                {
                    ;
                    mReadSchedulePolicy = newPolicy;
                    return;
                }

                ReadSchedulePolicy GetReadSchedulePolicy() const
                {
                    ;
                    return mReadSchedulePolicy;
                }



































                void SetReadQuantumSize(unsigned int size)
                {
                    ;
                    mReadQuantumSize = size;
                    return;
                }





                unsigned int GetReadQuantumSize() const
                {
                    ;
                    return mReadQuantumSize;
                }






                static IResourceAllocator *GetAllocator()
                {
                    ;
                    return sAllocator;
                }






                debug::Channel *GetPrintChannel() const
                {
                    ;
                    return mPrintChannel;
                }

            private:


                explicit Manager(const Options &options);
                ~Manager();

                static void *operator new(size_t size);
                static void operator delete(void *p);

                void Init();





                static rw::IResourceAllocator * sAllocator;


                static Manager * sInstance;






                detail::ListSingle<Device> mDeviceList;










                unsigned int mReadQuantumSize;


                Device * mNullDevice;




                char * mSearchPath;


                unsigned int mMaxSearchPathLength;


                unsigned int mMaxSearchLocations;

                struct SearchPathInfo
                {
                    char *mPath;
                    Device *mDevice;
                };


                SearchPathInfo * mSearchPathInfo;


                debug::Channel * mPrintChannel;
                ReadSchedulePolicy mReadSchedulePolicy;





                bool (*mReadFileFailCallback)(void);







                friend class Handle;
                friend class Device;
                friend class AsyncOp;
            };
        }
    }
}
