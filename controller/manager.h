
















namespace rw
{
    namespace core
    {
        namespace debug
        {
            class Channel;
        }

        namespace controller
        {

            class DeviceInfo;
            class DeviceState;
            class IDeviceEffect;












            struct Options
            {



                Options();




                Options(debug::Channel *PrintChannel,
                        rw::IResourceAllocator *coreAllocator);

                debug::Channel *mPrintChannel;
                rw::IResourceAllocator *mAllocator;
            };









            class Manager
            {
            public:



                enum
                {









                    MAX_DEVICES = 4





                };





                static void CreateInstance(const Options &options);





                static Manager* GetInstance();



                static void DestroyInstance();





                static bool IsInitialized()
                {
                    ;
                    return rw::core::controller::Manager::sInstance != 0;
                }



                static rw::IResourceAllocator* GetAllocator();




                virtual void Update() = 0;




                const DeviceInfo* GetDeviceInfo(unsigned int deviceNumber) const;










                const DeviceState* GetDeviceState(unsigned int deviceNumber) const;




                virtual IDeviceEffect* GetDeviceEffect(unsigned int deviceNumber) const = 0;





                virtual unsigned int GetNumControllers() const = 0;










                virtual uint32_t TMPGetButtonData() const
                {
                    ;
                    return 0;
                }






                virtual bool GetInterceptState() const = 0;

            private:

                explicit Manager(const Options &options);
                virtual ~Manager();


                static Manager *sInstance;


                static rw::IResourceAllocator *sAllocator;


                debug::Channel *mPrintChannel;



                unsigned int mTimestamp;


                DeviceInfo *mDeviceInfoList[MAX_DEVICES];
                DeviceState *mDeviceStateList[MAX_DEVICES];


                friend class LLManager;
            };
        }
    }
}
