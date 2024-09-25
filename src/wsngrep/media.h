#pragma once

#include "config.h"
#include <sys/types.h>
#include "capture.h"

#define MEDIATYPELEN 15

//! Shorter declaration of sdp_media structure
typedef struct sdp_media sdp_media_t;
//! Shorter declaration of sdp_media_fmt structure
typedef struct sdp_media_fmt sdp_media_fmt_t;

struct sip_msg;
struct sip_call;

struct sdp_media_fmt {
    uint32_t id;
    char format[50];
};


struct sdp_media {
    //! SDP Addresses information
    address_t address;
    char type[MEDIATYPELEN];
    uint32_t fmtcode;
    //! List of described formats in this media
    vector_t* formats;
    //! Message with this SDP content
    struct sip_msg* msg;
};

/**
 * @brief Allocate memory for a new media structure
 *
 * Create a structure for a new message sdp connection data.
 *
 * @param msg SIP Message pointer owner of this media
 * @return new allocated structure
 */
sdp_media_t*
media_create(struct sip_msg* msg);

/**
 * @brief Vector destroyer for media items
 */
void
media_destroyer(void* item);

void
media_set_type(sdp_media_t* media, const char* type);

void
media_set_address(sdp_media_t* media, address_t addr);

void
media_set_prefered_format(sdp_media_t* media, uint32_t code);

void
media_add_format(sdp_media_t* media, uint32_t code, const char* format);

const char*
media_get_type(sdp_media_t* media);

const char*
media_get_format(sdp_media_t* media, uint32_t code);

const char*
media_get_prefered_format(sdp_media_t* media);

int
media_get_format_code(sdp_media_t* media);
