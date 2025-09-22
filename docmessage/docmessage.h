















#include <stdio.h>










namespace rw
{




































typedef void (*DocMessageHandlerCallBack)(const RwChar *file,
                                          uint32_t line,
                                          uint32_t messageId,
                                          const RwChar *format,
                                          va_list args);






}

namespace rw
{





class DocMessageData
{
public:




    DocMessageData(void);
};

class DocMessage
{
private:















    DocMessage()
    {
        ;
        return;
    }

    DocMessage & operator=(const DocMessage & )
    {
        ;
        return *this;
    }

public:








    DocMessage(const RwChar* , uint32_t )
    {
        ;
        return;
    }











    static void
    SetTarget(DocMessageHandlerCallBack )
    {
        ;
        return;
    }


    static DocMessageData*&
    SharedData();

    static DocMessageData&
    Data();
};
















}
