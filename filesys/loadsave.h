






















namespace rw
{
    namespace core
    {
        namespace filesys
        {
            void Save(const char *filePath, const void *addr, uint64_t bytes);
            bool Delete(const char *filePath);
            bool Move(const char *currentName, const char *newName);
        }
    }
}
