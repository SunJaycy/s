















namespace rw
{
    namespace core
    {
        namespace debug
        {
            class Channel;








            class Formatter : public IFormatter
            {
            public:


                Formatter() {}
                virtual ~Formatter() {}

                virtual bool Format(char *buffer, unsigned int bufLen, Channel *channel, const char *format, va_list args);
            };
        }
    }
}
