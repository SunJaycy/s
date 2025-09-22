




















namespace rw
{





















typedef struct LinkListTag LinkList;





typedef struct LLLink LLLink;
























struct LLLink
{
    struct LLLink *next;
    struct LLLink *prev;
    void *data;
};










struct LinkListTag
{
    LLLink terminator;
};














extern void
LinkListInitialize(LinkList *list);

extern void
LLLinkInitialize(LLLink *link);

extern void
LinkListAddLLLink(LinkList *list, LLLink *link);

extern void
LinkListRemoveLLLink(LLLink *link);











inline const LLLink *
LinkListGetTerminator(const LinkList *list)
{
    ;
    return (const LLLink *)(&list->terminator);
}









inline LLLink *
LinkListGetFirstLLLink(LinkList *list)
{
    ;
    return list->terminator.next;
}










inline LLLink *
LLLinkGetPrev(LLLink *link)
{
    ;
    return link->prev;
}










inline LLLink *
LLLinkGetNext(LLLink *link)
{
    ;
    return link->next;
}









inline void *
LLLinkGetData(LLLink *link)
{
    ;
    return link->data;
}








inline void
LLLinkSetData(LLLink *link, void *data)
{
    ;

    link->data = data;

    return;
}

}
