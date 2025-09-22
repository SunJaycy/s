


























namespace rw
{
namespace core
{
namespace arena
{
















typedef uint32_t ObjectTypeId;










class ArenaTypeReg
{
public:
    ObjectTypeId id;
    RwUnfixCB unfixCB;
    RwRefixCB refixCB;
    RwFixupCB fixupCB;
    RwDestructCB destructCB;

    ArenaTypeReg()
    {
        ;
        return;
    }
    ArenaTypeReg(ObjectTypeId id_);

    ObjectTypeId
    GetId() const;
};
typedef ArenaTypeReg* ArenaTypeRegPtr; typedef const ArenaTypeReg* ArenaTypeRegConstPtr;




inline ObjectTypeId
ArenaTypeReg::GetId() const
{
    ;
    return id;
}










class TypeStaticMetadata
{
    public:
        class ConstIterator;
        friend class ConstIterator;

        static ConstIterator
        Find(uint32_t typeId);

        static ConstIterator
        End();

        const RwChar *
        GetName() const;

    private:
        const RwChar *m_name;

        TypeStaticMetadata(const RwChar *name);
};




class TypeStaticMetadata::ConstIterator
{
    public:
        friend class TypeStaticMetadata;




        const TypeStaticMetadata *
        operator->() const
        {
            ;
            return &m_data;
        }



        const TypeStaticMetadata&
        operator*() const
        {
            ;
            return m_data;
        }



        bool operator!=(const ConstIterator& rhs) const
        {
            ;

            return m_data.GetName()!=rhs->GetName();
        }

    private:
        ConstIterator(const RwChar *ptr);
        TypeStaticMetadata m_data;
};










extern ArenaTypeReg*
ArenaTypeRegGetType(uint32_t id);

extern RwBool
rw_PassthroughWriteCB(void *ptr, uint32_t size, uint32_t prePad);

extern SizeAndAlignment *
rw_PassthroughUnfixCB(void *obj, SizeAndAlignment *offset);

extern void
rw_PassthroughRefixCB(void *obj, void *offset, ArenaIterator *iterator);

extern RwBool
rw_PassthroughFixupCB(void *obj, ArenaIterator *iterator);

extern SizeAndAlignment *
rw_DefaultUnfixCB(void *obj, SizeAndAlignment *offset);

extern void
rw_DefaultRefixCB(void *obj, void *offset, ArenaIterator *iterator);

extern RwBool
rw_DefaultFixupCB(void *obj, ArenaIterator *iterator);

}
}
}



namespace rw
{
namespace core
{
namespace arena
{




struct rw_ArenaTypeRegHeader
{
    uint32_t numEntries;
    uint32_t numUsed;
};




class rw_ArenaTypeRegistry
{
public:

    rw_ArenaTypeRegistry()
    {
        ;
        return;
    }

    rw_ArenaTypeRegHeader header;
    ArenaTypeReg record[1];

    static rw_ArenaTypeRegistry *
    Open(void *buffer, uint32_t bufSize);

    ArenaTypeReg *
    Add(ObjectTypeId id);

    ArenaTypeReg *
    Find(ObjectTypeId id);

    uint32_t Size() const
    {
        ;
        return header.numUsed;
    }
    uint32_t Capacity() const
    {
        ;
        return header.numEntries;
    }

    void
    CopyTypeIds(ObjectTypeId *dest);
};





inline void
rw_AssertObjectTypeIdNotFound(uint32_t , RwChar *)
{
    ;
    return;
}


}
}
}
