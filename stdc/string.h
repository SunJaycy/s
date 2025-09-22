













#include <string.h>
#include <stdio.h>










namespace rw
{
    namespace core
    {
        namespace stdc
        {









            enum HexFormat
            {
                HEX_CAPITALIZE,
                HEX_NO_CAPITALIZE
            };






            char* StringCopy(char* destPtr,const char* sourcePtr);
            char* StringCat(char* destPtr,const char* sourcePtr);
            int StringCompare(const char* string1Ptr,const char* string2Ptr);
            int StringNoCaseCompare(const char* string1,const char* string2Ptr);
            unsigned int StringLength(const char* stringPtr);
            char* StringToUpperCase(char* destPtr,const char* sourcePtr);
            char* StringToLowerCase(char* destPtr,const char* sourcePtr);
            char* StringToMixedCase(char* destPtr,const char* sourcePtr,const char* separatorsPtr);
            char* FindFirstCharInString(const char* sourcePtr,char chr);
            char* FindLastCharInString(const char* sourcePtr,char chr);
            char* FindSubStringInString(const char* mainStringPtr,const char* subStringPtr);



            char* StringnCopy(char* destPtr,const char* sourcePtr,unsigned int charCount);
            char* StringnCat(char* destPtr,const char* sourcePtr,unsigned int charCount);
            int StringnCompare(const char* string1Ptr,const char* string2Ptr,unsigned int charCount);
            int StringnNoCaseCompare(const char* string1,const char* string2Ptr,unsigned int charCount);



            int Sprintf(char* destPtr,const char* formatPtr,...);

            int Snprintf(char* destPtr,unsigned int destBufferSize,const char* formatPtr,...);

            int Vsprintf(char* destPtr,const char* formatPtr, va_list argptr);
            int Vsnprintf(char* destPtr,unsigned int destBufferSize,const char* formatPtr, va_list argptr);


            int ConvertAToI(const char* sourcePtr);
            float ConvertAToF(const char* sourcePtr);
            unsigned int ConvertAToX(const char* sourcePtr);
            char* ConvertIToA(int source,char* destPtr,int base=10);
            char* ConvertXToA(unsigned int source,char* destPtr,HexFormat format);
            int64_t ConvertAToI64(const char* sourcePtr);
            char* ConvertI64ToA(int64_t source,char* destPtr,int64_t base=10);


            const char* GetFirstTokenInString(const char* source,const char* delimitors,unsigned int* tokenStringLength);
            const char* GetNextTokenInString(const char* currentTokenPointer,const char* delimitors,unsigned int* tokenStringLength);
        }
    }
}
