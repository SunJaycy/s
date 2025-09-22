






























namespace rw
{
namespace core
{
namespace atom
{













class DynamicAtomTable;










class StaticAtomTable
{
public:


    AtomID Register(const RwChar* atom); void Register(const RwChar* atom, AtomID id); AtomID At(const RwChar* atom) const; const RwChar* At(AtomID id) const; bool Exists(const RwChar* atom) const; bool Exists(AtomID id) const; bool FindID(const RwChar*, AtomID&) const; bool Empty() const; template <class _AtomTable_> void RegisterAtomsWith(_AtomTable_&) const; AtomID NumAtoms() const; uint32_t BytesUsedByAtomStrings() const;

    void
    Initialize(void* buffer, uint32_t bufferSizeInBytes, AtomID numAtomIDs);

    static rw::Resource
    Create(const DynamicAtomTable&, rw::IResourceAllocator&, rw::ResourceDescriptor&);

    inline uint32_t
    BytesAvailable() const;

    inline uint32_t
    FreeAtomIDs() const;

    static inline uint32_t
    MinTableSizeForAverageAtomLength(AtomID numAtomIDs, uint32_t averageAtomLength);

    static inline uint32_t
    MinTableSizeForTotalAtomLength(AtomID numAtomIDs, uint32_t totalAtomLength);

    bool
    CanRegisterNewAtom(const RwChar* atom) const;

    void
    Unfix(void*);

    void
    Refix(void*);

    void
    Fixup(void*);

    static void
    InitializeArenaReadCallbacks();

    static void
    InitializeArenaWriteCallbacks();

private:

    struct Members
    {
        RwChar* atomNames;
        RwChar* atomNameTail;
        uint32_t* stringIndex;
        AtomID* idArray;
        AtomID numAtomIDs;
        AtomID freeAtomIDs;
        AtomID nextAvailableID;
    };

    Members* table;

    inline AtomID
    HashIDArrayIndex(const RwChar*) const;

    void
    RefixMembers();
};








inline const RwChar*
StaticAtomTable::At(const AtomID atomID) const
{
    ;
    ;
    ;
    return &table->atomNames[table->stringIndex[atomID]];
}





inline bool
StaticAtomTable::Empty() const
{
    ;
    ;
    return table->freeAtomIDs == table->numAtomIDs;
}





inline uint32_t
StaticAtomTable::BytesAvailable() const
{
    ;
    void* offset = RwPtrSubtractBasePtr(table->idArray, table->atomNameTail);
    return static_cast<uint32_t>(RwPtrToOffset(offset));
}






inline uint32_t
StaticAtomTable::FreeAtomIDs() const
{
    ;
    ;
    return table->freeAtomIDs;
}









           inline uint32_t
StaticAtomTable::MinTableSizeForAverageAtomLength(const AtomID numAtomIDs, const uint32_t averageAtomLength)
{
    ;
    ;
    ;

    return MinTableSizeForTotalAtomLength(numAtomIDs, averageAtomLength * numAtomIDs);
}









           inline uint32_t
StaticAtomTable::MinTableSizeForTotalAtomLength(const AtomID numAtomIDs, const uint32_t totalAtomLength)
{
    ;
    ;
    ;

    uint32_t size;
    size = uint32_t(numAtomIDs) * (sizeof(uint32_t) + sizeof(AtomID));
    size += totalAtomLength;
    size += sizeof(Members);

    return size;
}







template <class _AtomTable_>
inline void
StaticAtomTable::RegisterAtomsWith(_AtomTable_& destinationTable) const
{
    ;
    ;


    for (AtomID idLoop=0; idLoop<table->numAtomIDs; ++idLoop)
    {
        uint32_t atomStringIndex;
        if ((atomStringIndex = table->stringIndex[idLoop]) != uint32_t(0xffffffff))
        {

            destinationTable.Register(&table->atomNames[atomStringIndex]);
        }
    }

    return;
}





inline AtomID
StaticAtomTable::NumAtoms() const
{
    ;
    ;
    return (AtomID)(table->numAtomIDs - table->freeAtomIDs);
}





inline uint32_t
StaticAtomTable::BytesUsedByAtomStrings() const
{
    ;
    ;
    return uint32_t(table->atomNameTail - table->atomNames);
}

}
}
}
