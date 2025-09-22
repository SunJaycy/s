


namespace rw
{
    namespace core
    {
        namespace filesys
        {
            namespace detail
            {





                template <class T>
                    inline void ListSingle<T>::Push(T *node)
                {
                    ;
                    node->next = mHead;
                    mHead = node;
                    ++mNumNodes;


                    if (node->next == 0)
                        mTail = node;

                    return;
                }

                template <class T>
                    inline void ListSingle<T>::Append(T *node)
                {
                    ;
                    ListNodeS *ls = mTail;

                    node->next = 0;
                    mTail = node;
                    ++mNumNodes;

                    if (ls == 0)
                        mHead = node;
                    else
                        ls->next = node;

                    return;
                }

                template <class T>
                    inline T* ListSingle<T>::Pop()
                {
                    ;
                    T *headNode = mHead;

                    if (mHead != 0)
                    {
                        if (mHead == mTail)
                        {
                            mHead = 0;
                            mTail = 0;
                        }
                        else
                        {

                            mHead = static_cast<T *>(mHead->next);
                        }

                        --mNumNodes;

                        if (headNode != 0)
                            headNode->next = 0;
                    }

                    return headNode;
                }

                template<class T>
                    inline T* ListSingle<T>::GetNode(unsigned int index)
                {
                    ;
                    ;

                    T *retNode = mHead;

                    while (index-- != 0)
                    {
                        ;

                        retNode = static_cast<T *>(retNode->next);
                    }

                    return retNode;
                }

                template<class T>
                    inline void ListSingle<T>::InsertAfter(T *node, T *newnode)
                {
                    ;
                    if (node == 0)
                    {

                        Push(newnode);
                    }
                    else
                    {

                        if (node->next == 0)
                            mTail = newnode;

                        newnode->next = node->next;
                        node->next = newnode;

                        ++mNumNodes;
                    }
                    return;
                }

                template<class T>
                    inline bool ListSingle<T>::Remove(T *node, T *prev)
                {
                    ;
                    bool foundit = false;

                    ;

                    if (node == mHead)
                    {
                        foundit = true;
                        --mNumNodes;
                        if (node == mTail)
                        {
                            mTail = 0;
                            mHead = 0;
                        }
                        else
                        {

                            mHead = static_cast<T *>(node->next);
                        }
                    }
                    else if (mHead != 0)
                    {
                        if (prev == 0)
                            prev = mHead;

                        while ((prev->next != 0) && (prev->next != node))
                        {

                            prev = static_cast<T *>(prev->next);
                        }

                        if ((prev->next != 0) && (prev->next == node))
                        {
                            foundit = true;
                            --mNumNodes;
                            prev->next = node->next;
                            if (node == mTail)
                                mTail = prev;
                        }
                    }

                    if (foundit)
                    {
                        node->next = 0;
                    }

                    return foundit;
                }




            }
        }
    }
}
