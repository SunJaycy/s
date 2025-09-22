













namespace rw
{
namespace datacontainer
{


typedef uint32_t ContainerId;


typedef uint32_t TaskId;
















enum AccessType
{
    ACCESSTYPE_EXCLUSIVEWRITE,
    ACCESSTYPE_EXCLUSIVEREWRITE,
    ACCESSTYPE_SHAREDWRITE,
    ACCESSTYPE_SHAREDREAD,
    ACCESSTYPE_SHAREDMODIFY,
    ACCESSTYPE_SYNCHRONIZEDWRITE,
    ACCESSTYPE_SYNCHRONIZEDREAD
};







enum ReadStatus
{
    READSTATUS_EMPTY,
    READSTATUS_NONEMPTY
};








enum WriteOperation
{
    WRITEOPERATION_WRITE,
    WRITEOPERATION_DONTWRITE
};


extern bool AreAccessesCompatible(AccessType type1, AccessType type2);


}
}
