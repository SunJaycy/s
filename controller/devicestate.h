






















namespace rw
{
    namespace core
    {
        namespace controller
        {



            enum PadButtonId
            {


                PAD_BUTTON_SELECT,
                PAD_BUTTON_LTHUMB,
                PAD_BUTTON_RTHUMB,
                PAD_BUTTON_START,
                PAD_BUTTON_UP,
                PAD_BUTTON_RIGHT,
                PAD_BUTTON_DOWN,
                PAD_BUTTON_LEFT,
                PAD_BUTTON_L2,
                PAD_BUTTON_R2,
                PAD_BUTTON_L1,
                PAD_BUTTON_R1,
                PAD_BUTTON_TRIANGLE,
                PAD_BUTTON_CIRCLE,
                PAD_BUTTON_X,
                PAD_BUTTON_SQUARE,




























































                PAD_BUTTON_ID_MAX
            };





            enum PadAxisId
            {

                PAD_AXIS_LEFTX,
                PAD_AXIS_LEFTY,
                PAD_AXIS_RIGHTX,
                PAD_AXIS_RIGHTY,
    PAD_AXIS_SENSORX,
    PAD_AXIS_SENSORY,
    PAD_AXIS_SENSORZ,
    PAD_AXIS_SENSORG,



















                PAD_AXIS_ID_MAX
            };



























































































































































































































































































































            class DeviceState
            {
            public:







                enum KeyboardState
                {
                    KS_SHIFT = 0x01,
                    KS_CTRL = 0x02,
                    KS_ALT = 0x04
                };




                enum ConnectedState
                {
                    DISCONNECTED,
                    CONNECTED
                };




                enum NetworkState
                {
                    LOCAL,
                    NETWORKED
                };


                static const unsigned int INVALID_ID = 0xFFFFFFFF;


                static const uint8_t MIN_BUTTON_VALUE = 0x00;


                static const uint8_t MAX_BUTTON_VALUE = 0xFF;


                static const int MIN_AXIS_VALUE = -1000;


                static const int MAX_AXIS_VALUE = 1000;


                static void *operator new(size_t size);
                static void operator delete(void *p);




                DeviceState(unsigned int id, NetworkState networked);




                virtual ~DeviceState();







                unsigned int GetID() const
                {
                    ;
                    return mDeviceID;
                }




    void HasSensorData(bool b) { mHasSensorData = b; }
    bool HasSensorData() const { return mHasSensorData; }




    void HasPressData(bool b) { mHasPressData = b; }
    bool HasPressData() const { return mHasPressData; }






                bool IsConnected() const
                {
                    ;
                    return mIsConnected == CONNECTED;
                }





                bool IsNetworked() const
                {
                    ;
                    return mIsNetworked == NETWORKED;
                }





                unsigned int GetTimeStamp() const
                {
                    ;
                    return mTimestamp;
                }





                bool GetButtonPressed(unsigned int buttonIndex) const;





                void GetAllButtonPressed(bool *pButtonPressed, unsigned int numButtons) const;





                uint8_t GetButtonValue(unsigned int buttonIndex) const;





                void GetAllButtonValues(uint8_t *pButtonValues, unsigned int numButtons) const;




                int GetAxisValue(unsigned int axisIndex) const;




                void GetAllAxisValues(int *pAxisValues, unsigned int numAxis) const;




                unsigned int GetAscii(unsigned int buttonIndex) const;




                unsigned int GetVirtKey(unsigned int buttonIndex) const;




                unsigned int GetKeyState() const;




                unsigned int GetNumberDigitalButtons() const;




                unsigned int GetNumberAnalogButtons() const;




                unsigned int GetNumberAxis() const;




                void SetButtonValue(unsigned int buttonIndex, uint8_t buttonValue);





                void SetAllButtonValues(const uint8_t *buttonValues, unsigned int numButtons);




                void SetAxisValue(unsigned int axisIndex, int axisValue);




                void SetAllAxisValues(const int *axisValues, unsigned int numAxis);




                void SetTimestamp(unsigned int newTimestamp);




                void Reset(ConnectedState connected, unsigned int numDigitalButtons, unsigned int numAnalogButtons, unsigned int numAxis);


                DeviceState(const DeviceState &device);
                DeviceState& operator=(const DeviceState &device);

            private:




                unsigned int mDeviceID;

    bool mHasSensorData;
    bool mHasPressData;





                ConnectedState mIsConnected;





                NetworkState mIsNetworked;





                unsigned int mTimestamp;





                unsigned int mNumDigitalButtons;
                unsigned int mNumAnalogButtons;





                unsigned int mNumberAxis;








                uint8_t *mDigitalButtonValues;




                uint8_t *mButtonValues;




                int *mAxisValues;
            };

        }
    }
}
