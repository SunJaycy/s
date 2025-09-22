























namespace rw
{







typedef void (*ThrowDocExceptionCallBack)(const RwChar *file,
                                          const RwChar *function,
                                          uint32_t line,
                                          uint32_t messageId,
                                          const RwChar *format,
                                          va_list args);





class ThrowDocException
{
private:





    const RwChar *m_file;
    const RwChar *m_function;
    const uint32_t m_line;



    ThrowDocException() : m_file(0), m_function(0), m_line(0) {}
    ThrowDocException & operator=(const ThrowDocException & )
    {
        ;
        return *this;
    }

public:

    ThrowDocException(const RwChar *file, const RwChar *function, const uint32_t line)
        : m_file(file), m_function(function), m_line(line)
    {
        ;
        return;
    }
















    static void
    SetCallBack(ThrowDocExceptionCallBack )
    {
        ;
        return;
    }

};





class DocException : public Exception
{
public:


    DocException(uint32_t messageId,
                 const RwChar *msg,
                 const RwChar *file = "",
                 const uint32_t line = 0,
                 const RwChar *func = "") throw();


    DocException(const DocException &source) throw();


    DocException& operator = (const DocException &other) throw();


    uint32_t GetMessageId() const throw()
    {
        ;
        return m_messageId;
    }

private:


    uint32_t m_messageId;
};






inline void
SetDocExceptionCallBack(ThrowDocExceptionCallBack fn)
{
    ;
    ThrowDocException::SetCallBack(fn);
    return;
}






















































}
