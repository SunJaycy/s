





















namespace rw
{
    namespace core
    {
        namespace controller
        {





            class IDeviceEffect
            {
            public:









                struct Info
                {





                    enum Magnitudes
                    {
                        MIN_MAGNITUDE = 0,

                        MAX_MAGNITUDE = 65535



                    };







                    enum PlayControl
                    {
                        STOP,
                        START,
                        START_IF_PLAYING
                    };

                    int MagnitudeLeft;
                    int MagnitudeRight;
                    PlayControl StartPlaying;
                };


                IDeviceEffect() {}
                virtual ~IDeviceEffect() {}




                virtual bool IsPlaying() const = 0;




                virtual void Start() = 0;




                virtual void Stop() = 0;





                virtual void SetInfo(const Info *pInfo) = 0;
            };

        }
    }
}
