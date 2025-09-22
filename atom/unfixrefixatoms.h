




























namespace rw
{
namespace core
{
namespace atom
{




class DynamicAtomTable;









class UnfixRefixAtoms
{
public:




    virtual
    ~UnfixRefixAtoms()
    {
        ;
        return;
    }

    AtomID
    Unfix(const void* object, AtomID atomID, DynamicAtomTable&) const;

    AtomID
    Refix(const void* object, AtomID atomID, const DynamicAtomTable&) const;

protected:





    virtual const RwChar*
    At(const void*, AtomID) const = 0;




    virtual AtomID
    At(const void*, const RwChar*) const = 0;
};













inline AtomID
UnfixRefixAtoms::Unfix(const void* object, AtomID atomID, DynamicAtomTable& unfixAtomTable) const
{
    ;
    return unfixAtomTable.Register(At(object, atomID));
}










inline AtomID
UnfixRefixAtoms::Refix(const void* object, AtomID atomID, const DynamicAtomTable& refixAtomTable) const
{
    ;
    return At(object, refixAtomTable.At(atomID));
}


}
}
}
