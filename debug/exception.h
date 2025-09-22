



































namespace rw
{



























class Exception
{
public:

    Exception(const RwChar *msg, const RwChar *file = "",
              const uint32_t line = 0, const RwChar *func = "") throw();


    virtual ~Exception() throw();


    Exception(const Exception& _Right) throw();


    Exception& operator = (const Exception& _Right) throw();


    const RwChar *What() const throw();


    const RwChar *Where() throw();

private:


    Exception() throw() {}


    RwChar * m_pMsg;


    RwChar * m_pFile;



    RwChar * m_pFunc;


    int32_t m_Line;


    RwChar * m_pWhere;
};

}
