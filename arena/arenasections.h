
























































namespace rw
{
namespace core
{
namespace arena
{










class ArenaIterator;
class ArenaSection;
typedef ArenaSection* ArenaSectionPtr; typedef const ArenaSection* ArenaSectionConstPtr;
class ArenaSectionManifest;
class ArenaSectionTypes;
class ArenaSectionExternalArenas;
class ArenaSectionSubreferences;
class ArenaSectionAtoms;
struct SizeAndAlignment;

class Arena;
typedef Arena* ArenaPtr; typedef const Arena* ArenaConstPtr;







class ArenaTypeReg;
typedef ArenaTypeReg* ArenaTypeRegPtr; typedef const ArenaTypeReg* ArenaTypeRegConstPtr;

struct ArenaDictEntry;
typedef ArenaDictEntry* ArenaDictEntryPtr; typedef const ArenaDictEntry* ArenaDictEntryConstPtr;




class ArenaSection
{
public:
    ArenaTypeRegPtr typeReg;
    uint32_t numEntries;

    void
    Release();
};








class ArenaSectionManifest : public ArenaSection
{
public:
    ArenaSectionPtr* dict;



    static ResourceDescriptor
    GetResourceDescriptor(uint32_t numSections);

    static ArenaSectionManifest*
    Initialize(const Resource& resource, uint32_t numSections);

    ArenaSectionTypes&
    Types();

    const ArenaSectionTypes&
    Types() const;

    ArenaSectionExternalArenas&
    ExternalArenas();

    const ArenaSectionExternalArenas&
    ExternalArenas() const;

    ArenaSectionSubreferences&
    Subreferences();

    const ArenaSectionSubreferences&
    Subreferences() const;

    ArenaSectionAtoms&
    Atoms();

    const ArenaSectionAtoms&
    Atoms() const;

    void
    Release();

    static Arena::UnfixContext *
    Unfix(void *obj, Arena::UnfixContext *context);

    static void
    Refix(void *obj, void *offset, Arena::RefixContext *iterator);

    static RwBool
    Fixup(void *obj, Arena::FixupContext *iterator);
};


class ArenaSectionTypes : public ArenaSection
{
public:
    ArenaTypeRegPtr* dict;


    static ResourceDescriptor
    GetResourceDescriptor(uint32_t numTypes);

    static ArenaSectionTypes*
    Initialize(const Resource& resource, uint32_t numTypes);

    void
    Release();

    static Arena::UnfixContext *
    Unfix(void *obj, Arena::UnfixContext *offset);

    static void
    Refix(void *obj, void *offset, Arena::RefixContext *iterator);

    static RwBool
    Fixup(void *obj, Arena::FixupContext *iterator);
};


class ArenaSectionExternalArenas : public ArenaSection
{
public:
    ArenaDictEntryPtr* dict;

    static ResourceDescriptor
    GetResourceDescriptor(uint32_t numArenas);

    static ArenaSectionExternalArenas*
    Initialize(const Resource& resource, uint32_t numArenas);

    void
    Release();

    static Arena::UnfixContext *
    Unfix(void *obj, Arena::UnfixContext *offset);

    static void
    Refix(void *obj, void *offset, Arena::RefixContext *iterator);

    static RwBool
    Fixup(void *obj, Arena::FixupContext *iterator);

    typedef Arena* ArenaSectionExternalArenasRecord;
    const ArenaSectionExternalArenasRecord& Record(size_t i) const
    {
        ;
        return (reinterpret_cast<const ArenaSectionExternalArenasRecord *>(&this[1]))[i];
    }
    ArenaSectionExternalArenasRecord& Record(size_t i)
    {
        ;
        return (reinterpret_cast<ArenaSectionExternalArenasRecord *>(&this[1]))[i];
    }


    void
    SynchronizeInternalArenas(Arena &current, ArenaSectionSubreferences &subreferences);
};

class ArenaSectionSubreferences : public ArenaSection
{
private:

    ArenaDictEntry* m_dictAfterRefix;
    ArenaSectionSubreferencesRecord* m_recordsAfterRefix;

public:
    ArenaDictEntry* dict;
    ArenaSectionSubreferencesRecord* records;
    uint32_t numUsed;

    static ResourceDescriptor
    GetResourceDescriptor();
    static ResourceDescriptor
    GetResourceDescriptor(uint32_t numSubreferences);

    static ArenaSectionSubreferences*
    Initialize(const Resource& resource);
    static ArenaSectionSubreferences*
    Initialize(const Resource& resource, uint32_t numSubreferences);

    void
    Release();

    static Arena::UnfixContext *
    Unfix(void *obj, Arena::UnfixContext *offset);

    static void
    Refix(void *obj, void *offset, Arena::RefixContext *iterator);

    static RwBool
    Fixup(void *obj, Arena::FixupContext *iterator);

    void UnfixData(ArenaIterator *iterator);
    void RefixData(ArenaIterator *iterator);

    const ArenaSectionSubreferencesRecord& Record(size_t i) const
    {
        ;
        return records[i];
    }
    ArenaSectionSubreferencesRecord& Record(size_t i)
    {
        ;
        return records[i];
    }
};





class ArenaSectionAtoms : public ArenaSection
{
public:

    rw::core::atom::StaticAtomTable* atomTable;

    static ArenaSectionAtoms*
    Initialize(const Resource& resource );

    static ResourceDescriptor
    GetResourceDescriptor( );

    static Arena::UnfixContext*
    Unfix(void *obj, Arena::UnfixContext *offset);

    static void
    Refix(void *obj, void *offset, Arena::RefixContext *iterator);

    static RwBool
    Fixup(void *obj, Arena::FixupContext *iterator);

    void
    SetAtomTableAndUnfixIt(rw::core::atom::StaticAtomTable*, Arena&);
};














extern void
ArenaSectionRegisterArenaWriteCallbacks(void);

extern void
ArenaSectionRegisterArenaReadCallbacks(void);


extern ResourceDescriptor
ArenaSectionsGetResourceDescriptor(uint32_t numTypes, const uint32_t* typeIds,
                                   uint32_t numExternalArenas, Arena* const * externalArenas);
extern ResourceDescriptor
ArenaSectionsGetResourceDescriptor(uint32_t numTypes, const uint32_t* typeIds,
                                   uint32_t numExternalArenas, Arena* const * externalArenas,
                                   uint32_t maxSubreferences);

extern ArenaSection*
ArenaSectionsInitialize(const Resource& resource, uint32_t numTypes, const uint32_t* typeIds,
                        uint32_t numExternalArenas, Arena* const * externalArenas);
extern ArenaSection*
ArenaSectionsInitialize(const Resource& resource, uint32_t numTypes, const uint32_t* typeIds,
                        uint32_t numExternalArenas, Arena* const * externalArenas, uint32_t maxSubreferences);

extern void
ArenaSectionsRelease(ArenaSection *section);


extern uint32_t
ArenaSectionsDefaultGetSize(uint32_t maxSubreferences);

extern uint32_t
ArenaSectionsDefaultGetAlign(uint32_t maxSubreferences);

extern ArenaSection *
ArenaSectionsDefaultInitialize(void *ptr, uint32_t maxSubreferences);

extern void
ArenaSectionsDefaultRelease(ArenaSection *section);

}
}
}



namespace rw
{
namespace core
{
namespace arena
{


class rw_NullSections
{
public:
    ArenaSectionManifest manifest __attribute__ ((__aligned__ (4)));
    ArenaSection* additionalSectionPtrs[4];
    ArenaSectionTypes types __attribute__ ((__aligned__ (4)));
    ArenaTypeReg* typesPtrs[(BASERESOURCE_NUMBEROFBASERESOURCETYPES + 1)];
    ArenaSectionExternalArenas extArenas __attribute__ ((__aligned__ (4)));
    Arena* extArenaRecord[3];
    Arena* extArenaPtrs[3];
    ArenaSectionSubreferences subrefs __attribute__ ((__aligned__ (4)));
    ArenaSectionAtoms atoms __attribute__ ((__aligned__ (4)));

    static rw_NullSections *
    Initialize(const Resource& resource);
};

extern uint32_t
rw_ArenaGetSectionsSize(const ArenaSectionManifest &sections);

}
}
}
