

































enum rwComponentID
{
    rwCOMPONENTID_NA = 0x00,

    rwCOMPONENTID_CORE = 0x01,
    rwCOMPONENTID_GRAPHICS = 0x02,
    rwCOMPONENTID_AUDIO = 0x03,
    rwCOMPONENTID_PHYSICS = 0x04,
    rwCOMPONENTID_NETWORK = 0x05,
    rwCOMPONENTID_AI = 0x06,
    rwCOMPONENTID_ANIMATION = 0x07,
    rwCOMPONENTID_COLLISION = 0x08,
    rwCOMPONENTID_PLATFORM = 0x09,

    rwCOMPONENTID_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};







typedef enum rwComponentID rwComponentID;
