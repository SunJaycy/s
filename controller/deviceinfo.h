





















namespace rw
{
    namespace core
    {
        namespace controller
        {




            class DeviceInfo
            {
            public:

                static const unsigned int INVALID_ID = 0xFFFFFFFF;









                enum Type
                {
                    PAD,
                    MOUSE,
                    KEYBOARD,
                    UNKNOWN
                };






                enum ButtonCapability
                {
                    ANALOG = 0x1
                };


                static void *operator new(size_t size);
                static void operator delete(void *p);





                explicit DeviceInfo(unsigned int id);
                ~DeviceInfo();







                unsigned int GetID() const
                {
                    ;
                    return mDeviceID;
                }






                Type GetType() const
                {
                    ;
                    return mDeviceType;
                }






                unsigned int GetNumberButtons() const
                {
                    ;
                    return mNumberButtons;
                }






                unsigned int GetNumberAxis() const
                {
                    ;
                    return mNumberAxis;
                }




                ButtonCapability GetButtonCapability(unsigned int ButtonIndex) const;




                void SetButtonCapability(unsigned int ButtonIndex, ButtonCapability newCapability);




                void Reset(Type deviceType, unsigned int numButtons, unsigned int numAxis);


                DeviceInfo(const DeviceInfo &device);
                DeviceInfo& operator=(const DeviceInfo &device);

            private:

                unsigned int mDeviceID;


                Type mDeviceType;


                unsigned int mNumberButtons;


                unsigned int mNumberAxis;






                ButtonCapability *mButtonCapabilities;
            };

        }
    }
}
