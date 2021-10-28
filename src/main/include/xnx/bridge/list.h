#pragma once

#include <xnx/bridge/types.h>

typedef struct _LIST_ENTRY
{
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, *PRLIST_ENTRY;

#if !defined(CONTAINING_RECORD)
#   if defined(container_of)
#       define CONTAINING_RECORD(address, type, field) container_of(address, type, field)
#   else
#       define CONTAINING_RECORD(address, type, field) ((type *)((char *)(address) - (uint64_t)(&((type *)0)->field)))
#   endif
#endif

VOID InitializeListHead(PLIST_ENTRY ListHead);
BOOLEAN RemoveEntryList(PLIST_ENTRY Entry);
VOID InsertTailList(PLIST_ENTRY ListHead, PLIST_ENTRY Entry);
