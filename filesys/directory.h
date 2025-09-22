


































namespace rw
{
    namespace core
    {

        namespace filesys
        {










            class DirectoryEntry
            {
            public:
                DirectoryEntry();
                explicit DirectoryEntry(const char *directory, const char *pattern = 0);
                ~DirectoryEntry();

                static void *operator new(size_t size)
                {
                    ;
                    return Manager::GetAllocator()->Allocate( ResourceDescriptor(size, 4), 0).GetMemoryResource();


                }

                static void operator delete(void *ptr)
                {
                    ;
                    Manager::GetAllocator()->Free(ptr);
                    return;
                }






                enum DirectoryFlags
                {
                    FLAG_READONLY = 0x01,

                    FLAG_DIRECTORY = 0x02
                };

                void GetNextFile();
                void OpenDirectory(const char *directory, const char *pattern = 0);









                bool IsValid() const
                {
                    ;
                    return mValid;
                }
                unsigned int GetFlags() const;
                const char * GetName() const;
                uint64_t GetSize() const;
                uint64_t GetCreationTime() const;
                uint64_t GetAccessTime() const;
                uint64_t GetModificationTime() const;

            private:
                bool mValid;
                DeviceDriver *mDriver;
                void *mFindHandle;
                DeviceDriver::FindData mFindData;
            };

            bool CreateDirectory(const char *directory);
            bool RemoveDirectory(const char *directory);
        }
    }
}
