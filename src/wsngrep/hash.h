#pragma once

#include "config.h"
#include <stdio.h>

//! Shorter declaration of hash structures
typedef struct htable htable_t;
typedef struct hentry hentry_t;

/**
 *  Structure to hold a Hash table entry
 */
struct hentry {
    //! Key of the hash entry
    const char* key;
    //! Pointer to has entry data
    void* data;
    //! Next entry sharing the same hash value
    hentry_t* next;
};

struct htable {
    //! Fixed hash table limit
    size_t size;
    // Hash table entries
    hentry_t** buckets;
};

htable_t*
htable_create(size_t size);

void
htable_destroy(htable_t* table);

int
htable_insert(htable_t* table, const char* key, void* data);

void
htable_remove(htable_t* table, const char* key);

void*
htable_find(htable_t* table, const char* key);

size_t
htable_hash(htable_t* table, const char* key);
