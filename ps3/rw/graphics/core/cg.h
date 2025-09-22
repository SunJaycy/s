
























namespace rw
{
namespace graphics
{
namespace core
{
namespace cg
{























struct _rw_CGprogram
{
    uint32_t m_profile;
    uint32_t unknown1;
    uint32_t unknown2;
    uint32_t m_numParameters;

    uint32_t m_parameterOffset;
    uint32_t unknown3;
    uint32_t m_uCodeSize;
    uint32_t m_uCodeOffset;

    uint32_t m_programInformationOffset;
};
typedef const _rw_CGprogram* rw_CGprogram;

struct _rw_CGprogramInfo
{
    uint32_t unknown1;
    uint32_t unknown2;
    uint32_t m_numRegistersFragment;
    uint32_t unknown4;

    uint32_t unknown5;
    uint32_t unknown6;
    uint8_t m_numRegistersVertex;
};

struct _rw_CGparameter
{
    uint32_t m_type;
    uint32_t m_resource;
    uint32_t m_variability;
    uint32_t m_resourceIndex;

    uint32_t m_nameOffset;
    uint32_t unknown2;
    uint32_t m_patchOffset;
    uint32_t m_semanticOffset;

    uint32_t unknown3;
    uint32_t unknown4;
    uint32_t m_referenced;
    uint32_t unknown5;
};
typedef const _rw_CGparameter* rw_CGparameter;







enum rw_CGprofile
{
    rwCG_FRAGMENTRSX = 7004,
    rwCG_VERTEXRSX = 7003
};

enum rw_CGenum
{
    rwCG_IN = 4097,
    rwCG_OUT = 4098,
    rwCG_INOUT = 4099,
    rwCG_MIXED = 4100,
    rwCG_VARYING = 4101,
    rwCG_UNIFORM = 4102,

    rwCGVARIABILITY_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};

enum rw_CGresource
{
    rwCG_TEXUNIT0 = 2048,
    rwCG_CONSTTABLE = 2178,
    rwCG_UNDEFINED = 3256,

    rwCGRESOURCE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};

enum rw_CGtype
{
    rwCG_FLOAT = 1045,
    rwCG_FLOAT1 = 1091,
    rwCG_FLOAT2 = 1046,
    rwCG_FLOAT3 = 1047,
    rwCG_FLOAT4 = 1048,
    rwCG_FLOAT3x3 = 1059,
    rwCG_FLOAT3x4 = 1060,
    rwCG_FLOAT4x3 = 1063,
    rwCG_FLOAT4x4 = 1064,
    rwCG_SAMPLER1D = 1065,
    rwCG_SAMPLER2D = 1066,
    rwCG_SAMPLER3D = 1067,
    rwCG_SAMPLERCUBE = 1069,
    rwCG_BOOL = 1114,
    rwCGTYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};















































typedef ::CGprogram CGprogram;
typedef ::CGparameter CGparameter;
typedef ::CGtype CGtype;
typedef ::CGenum CGenum;
typedef ::CGresource CGresource;










uint32_t cgPreInitGetUCodeSize(const rw_CGprogram prog);
uint32_t cgPreInitGetNumParameters(const rw_CGprogram prog);
rw_CGparameter cgPreInitGetIndexParameter(const rw_CGprogram prog, uint32_t index);
const char * cgPreInitGetName(const rw_CGprogram prog, const rw_CGparameter param);
CGenum cgPreInitGetVariability(const rw_CGprogram prog, const rw_CGparameter param);
CGresource cgPreInitGetResource(const rw_CGprogram prog, const rw_CGparameter param);
uint32_t cgPreInitGetResourceIndex(const rw_CGprogram prog, const rw_CGparameter param);
uint32_t cgPreInitGetReferenced(const rw_CGprogram prog, const rw_CGparameter param);
CGtype cgPreInitGetType(const rw_CGprogram prog, const rw_CGparameter param);





}
}
}
}
