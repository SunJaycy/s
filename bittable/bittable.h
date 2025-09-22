

























namespace rw
{


struct BitTable;

namespace core
{
namespace arena
{
    struct SizeAndAlignment;
    class ArenaIterator;
}
}






























struct BitTable
{
    uint32_t m_rows;
    uint32_t m_columns;
    uint32_t m_arraySize;
    uint32_t m_array[1];









    BitTable(uint32_t rows, uint32_t columns)
        : m_rows(rows),
          m_columns(columns)
    {
        ;

        m_arraySize = ((rows * columns)+31)>>5;

        return;
    }






    static ResourceDescriptor
    GetResourceDescriptor(uint32_t numRows, uint32_t numCols)
    {
        ;
        uint32_t size = (3 + (((numRows * numCols)+31)>>5)) * sizeof(uint32_t);
        return ResourceDescriptor(size, 4);
    }


    static BitTable *
    Initialize(const Resource& resource, uint32_t numRows, uint32_t numCols);










    static uint32_t
    GetSize(uint32_t numRows, uint32_t numCols)
    {
        ;
        ;
        return GetResourceDescriptor(numRows, numCols).GetSize();
    }







    static uint32_t
    GetAlignment(uint32_t numRows, uint32_t numCols)
    {
        ;
        ;
        return GetResourceDescriptor(numRows, numCols).GetAlignment();
    }


    static BitTable *
    Initialize(void *memPtr, uint32_t numRows, uint32_t numCols);







    static void
    Release(BitTable *bitTable)
    {
        ;




        bitTable->~BitTable();
        return;
    }








    void
    SetBit(uint32_t row, uint32_t column)
    {
        ;
        ;
        ((void)(m_array[((row)*m_columns+(column))>>5] |=
             (1<<(((row)*m_columns+(column))&31))));
        return;
    }







    void
    ClearBit(uint32_t row, uint32_t column)
    {
        ;
        ;
        ((void)(m_array[((row)*m_columns+(column))>>5] &=
                         ~(1<<(((row)*m_columns+(column))&31))));
        return;
    }








    void
    SetBitValue(uint32_t row, uint32_t column, RwBool value, RwBool symmetric = 0)
    {
        ;
        if (value)
        {
            SetBit(row, column);
            if (symmetric && row != column)
            {
                SetBit(column, row);
            }
        }
        else
        {
            ClearBit(row, column);
            if (symmetric && row != column)
            {
                ClearBit(column, row);
            }
        }
        return;
    }





    void
    ClearTable()
    {
        ;
        for(uint32_t i = 0; i < m_arraySize; i++)
        {
            m_array[i] = 0;
        }
        return;
    }








    uint32_t
    GetBit(uint32_t row, uint32_t column) const
    {
        ;
        ;
        return (m_array[((row)*m_columns+(column))>>5] & (1<<(((row)*m_columns+(column))&31)));

    }






    uint32_t
    GetRowCount() const
    {
        ;
        return m_rows;
    }






    uint32_t
    GetColumnCount() const
    {
        ;
        return m_columns;
    }


    static rw::core::arena::SizeAndAlignment *
    Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset);

    static void
    Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *);

    static RwBool
    Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator);

    static void
    RegisterArenaReadCallbacks(void);

    static void
    RegisterArenaWriteCallbacks(void);

};


}
