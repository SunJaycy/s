





























namespace rw
{
namespace core
{
namespace atom
{




class StaticAtomTable;









class DynamicAtomTable
{
public:


    AtomID Register(const RwChar* atom); void Register(const RwChar* atom, AtomID id); AtomID At(const RwChar* atom) const; const RwChar* At(AtomID id) const; bool Exists(const RwChar* atom) const; bool Exists(AtomID id) const; bool FindID(const RwChar*, AtomID&) const; bool Empty() const; template <class _AtomTable_> void RegisterAtomsWith(_AtomTable_&) const; AtomID NumAtoms() const; uint32_t BytesUsedByAtomStrings() const;

    void
    Initialize(rw::IResourceAllocator&);

    void
    Release();

private:

    void
    CreateNewTable();

    inline void*
    Alloc(size_t);

    inline void
    Free(void*);

    StaticAtomTable** staticAtomTableArray;
    uint32_t numTables;
    IResourceAllocator* allocator;
};








inline bool
DynamicAtomTable::Empty() const
{
    ;
    return 0 == numTables;
}







template <class _AtomTable_>
inline void
DynamicAtomTable::RegisterAtomsWith(_AtomTable_& destinationTable) const
{
    ;

    for (uint32_t tableLoop=0; tableLoop<numTables; ++tableLoop)
    {
        ;
        staticAtomTableArray[tableLoop]->RegisterAtomsWith(destinationTable);
    }

    return;
}

}
}
}
