





namespace rw
{
    namespace core
    {
        namespace filesys
        {
            namespace detail
            {








                class ListNodeS
                {
                public:

                    ListNodeS() : next(0)
                    {
                        ;
                        return;
                    }




                    ~ListNodeS()
                    {
                        ;
                        next = 0;
                        return;
                    }

                    ListNodeS *next;
                };


                template<class T> class ListSingleIterator;










                template<class T>
                class ListSingle
                {
                public:

                    ListSingle() : mHead(0), mTail(0), mNumNodes(0)
                    {
                        ;
                        return;
                    }


                    ~ListSingle()
                    {



                        ;
                        ListNodeS *node = mHead;
                        ListNodeS *nextnode = mHead;

                        while (node && node->next)
                        {
                            nextnode = node->next;
                            node->next = 0;
                            node = nextnode;
                        }

                        mHead = mTail = 0;
                        mNumNodes = 0;
                        return;
                    }


                    void Push(T *node);


                    void Append(T *node);


                    T * Pop();


                    T * GetHead() const
                    {
                        ;
                        return mHead;
                    }


                    uint32_t GetCount() const
                    {
                        ;
                        return mNumNodes;
                    }


                    T * GetNode(unsigned int index);


                    void InsertAfter(T *node, T *newnode);



                    bool Remove(T *node, T *prevnode = 0);

                    ListSingleIterator<T> Begin()
                    {
                        ;
                        return ListSingleIterator<T>(mHead);
                    }

                private:
                    T *mHead;
                    T *mTail;
                    uint32_t mNumNodes;
                };

                template<class T>
                class ListSingleIterator
                {
                public:

                    explicit ListSingleIterator(T *node) : mNode(node)
                    {
                        ;
                        return;
                    }

                    ListSingleIterator() : mNode(0)
                    {
                        ;
                        return;
                    }


                    T* operator++(int32_t)
                    {





                        ;
                        T *currNode = mNode;

                        if (mNode != 0)
                            mNode = static_cast<T *>(mNode->next);

                        return currNode;
                    }



                    T* operator++()
                    {





                        ;
                        if (mNode != 0)
                        {

                            mNode = static_cast<T *>(mNode->next);
                        }

                        return mNode;
                    }


                    bool operator != (const ListSingleIterator<T> &a)
                    {
                        ;
                        return mNode != a.mNode;
                    }


                    T *operator*() const
                    {
                        ;
                        return mNode;
                    }

                private:
                    T *mNode;
                };
            }
        }
    }
}

#include <rw/core/filesys/detail/list_inlines.h>
