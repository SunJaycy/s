



























enum RwObjectType
{
    RWOBJECTTYPE_NULL = ((((rwCOMPONENTID_NA) & 0xff) << 16) | ((0x00) & 0xff)),
    RWOBJECTTYPE_NA = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x00) & 0xff)),
    RWOBJECTTYPE_ARENA = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x01) & 0xff)),


    RWOBJECTTYPE_RAW = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x02) & 0xff)),


    RWOBJECTTYPE_SUBREFERENCE = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x03) & 0xff)),


    RWOBJECTTYPE_SECTIONMANIFEST = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x04) & 0xff)),
    RWOBJECTTYPE_SECTIONTYPES = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x05) & 0xff)),
    RWOBJECTTYPE_SECTIONEXTERNALARENAS = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x06) & 0xff)),
    RWOBJECTTYPE_SECTIONSUBREFERENCES = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x07) & 0xff)),
    RWOBJECTTYPE_SECTIONATOMS = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x08) & 0xff)),
    RWOBJECTTYPE_DEFARENAIMPORTS = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x09) & 0xff)),
    RWOBJECTTYPE_DEFARENAEXPORTS = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x0a) & 0xff)),
    RWOBJECTTYPE_DEFARENATYPES = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x0b) & 0xff)),
    RWOBJECTTYPE_DEFARENADEFINEDARENAID = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x0c) & 0xff)),
    RWOBJECTTYPE_ATTRIBUTEPACKET = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x0d) & 0xff)),
    RWOBJECTTYPE_ATTRIBUTEPACKET_DELEGATE = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x0e) & 0xff)),


    RWOBJECTTYPE_BITTABLE = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x0f) & 0xff)),


    RWOBJECTTYPE_ARENALOCALATOMTABLE = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x10) & 0xff)),


    RWOBJECTTYPE_BASERESOURCE_START = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x30) & 0xff)),
    RWOBJECTTYPE_BASERESOURCE_RESERVEDTO = ((((rwCOMPONENTID_CORE) & 0xff) << 16) | ((0x3f) & 0xff)),




    RWOBJECTTYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};




typedef enum RwObjectType RwObjectType;
