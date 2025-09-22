


















#include <limits.h>
#include <string.h>
#include <stdio.h>















































































extern int32_t RwStricmp(const RwChar *string1, const RwChar *string2);



extern int32_t RwStrnicmp(const RwChar *string1, const RwChar *string2, uint32_t length);



extern RwChar * RwStristr(RwChar *string1, const RwChar *string2);


 RwChar * rwGenericSprintf(const RwChar *format, ...);
RwChar *rwGenericSprintfVL(const RwChar *format, va_list args);







extern int32_t
RwVsnprintf(char *buffer, size_t count, const RwChar *format, va_list argptr);


extern int32_t
RwSnprintf(RwChar *buffer, size_t count, const RwChar *format, ...);
