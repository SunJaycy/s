














#include <string.h>
#include <stdio.h>










namespace rw
{
    namespace core
    {
        namespace stdc
        {










            enum HexFormat16
            {
                HEX16_CAPITALIZE,
                HEX16_NO_CAPITALIZE
            };




            int IsWCharSpace(char16_t c);
            char16_t* WCharSearch(const char16_t* stringPtr, char16_t c);


            char16_t* WStringCopy(char16_t* destPtr,const char16_t* sourcePtr);
            char16_t* WStringCat(char16_t* destPtr,const char16_t* sourcePtr);
            int WStringCompare(const char16_t* string1Ptr,const char16_t* string2Ptr);
            int WStringNoCaseCompare(const char16_t* string1,const char16_t* string2Ptr);
            unsigned int WStringLength(const char16_t* stringPtr);
            char16_t* WStringToUpperCase(char16_t* destPtr,const char16_t* sourcePtr);
            char16_t* WStringToLowerCase(char16_t* destPtr,const char16_t* sourcePtr);
            char16_t* WStringToMixedCase(char16_t* destPtr,const char16_t* sourcePtr,const char16_t* separatorsPtr);
            char16_t* FindFirstWCharInWString(const char16_t* sourcePtr,char16_t chr);
            char16_t* FindLastWCharInWString(const char16_t* sourcePtr,char16_t chr);
            char16_t* FindSubWStringInWString(const char16_t* mainStringPtr,const char16_t* subStringPtr);



            char16_t* WStringnCopy(char16_t* destPtr,const char16_t* sourcePtr,unsigned int charCount);
            char16_t* WStringnCat(char16_t* destPtr,const char16_t* sourcePtr,unsigned int charCount);
            int WStringnCompare(const char16_t* string1Ptr,const char16_t* string2Ptr,unsigned int charCount);
            int WStringnNoCaseCompare(const char16_t* string1,const char16_t* string2Ptr,unsigned int charCount);



            int Wsprintf(char16_t* destPtr,const char16_t* formatPtr,...);

            int Wsnprintf(char16_t* destPtr,unsigned int destBufferSize,const char16_t* formatPtr,...);

            int Wvsprintf(char16_t* destPtr,const char16_t* formatPtr, va_list argptr);
            int Wvsnprintf(char16_t* destPtr,unsigned int destBufferSize,const char16_t* formatPtr, va_list argptr);


            int ConvertWToI(const char16_t* sourcePtr);
            float ConvertWToF(const char16_t* sourcePtr);
            unsigned int ConvertWToX(const char16_t* sourcePtr);
            char16_t* ConvertIToW(int source,char16_t* destPtr,int base=10);
            char16_t* ConvertXToW(unsigned int source,char16_t* destPtr,HexFormat16 format);
            char* ConvertWToA(char* destPtr,const char16_t* sourcePtr);
            char16_t* ConvertAToW(char16_t* destPtr,const char* sourcePtr);
            int64_t ConvertWToI64(const char16_t* sourcePtr);
            char16_t* ConvertI64ToW(int64_t source,char16_t* destPtr,int64_t base=10);


            const char16_t* GetFirstTokenInWString(const char16_t* source,const char16_t* delimitors,unsigned int* tokenStringLength);
            const char16_t* GetNextTokenInWString(const char16_t* currentTokenPointer,const char16_t* delimitors,unsigned int* tokenStringLength);
        }
    }
}
