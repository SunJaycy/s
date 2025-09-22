





























































class RwGUID
{
public:
    RwGUID();
    explicit RwGUID(const RwChar *str);
    explicit RwGUID(const uint8_t *ptr);
    void Zero();
    void EndianSwap();
    RwBool operator == ( const RwGUID & guid ) const;
    RwBool operator < ( const RwGUID & guid ) const;
    RwGUID& operator++();
    void ToString(RwChar *buffer) const;
private:
    uint32_t m_data1;
    uint16_t m_data2;
    uint16_t m_data3;
    uint8_t m_data4[8];
};
