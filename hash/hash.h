






























namespace rw
{




extern const uint32_t RWHASH32_INIT;





extern const uint64_t RWHASH64_INIT;






















 uint32_t
RwHash32UInt32(uint32_t integer,
               uint32_t hashValue);

 uint32_t
RwHash32Buffer(const uint8_t *buffer,
               size_t length,
               uint32_t hashValue);

 uint32_t
RwHash32String(const RwChar *str,
               uint32_t hashValue);


 uint64_t
RwHash64Buffer(const uint8_t *buffer,
               size_t length,
               uint64_t hashValue);

 uint64_t
RwHash64String(const RwChar *str,
               uint64_t hashValue);






}
