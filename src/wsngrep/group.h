#pragma once

#include "config.h"
#include "vector.h"
#include "sip.h"

//! Shorter declaration of sip_call_group structure
typedef struct sip_call_group sip_call_group_t;

/**
 * @brief Contains a list of calls
 *
 * This structure is used for displaying more than one dialog in the
 * same call flow. Instead of displaying a call flow, we will display
 * a calls group flow.
 */
struct sip_call_group {
    //! For extended display, main call-id
    char* callid;
    //! Calls array in the group
    vector_t* calls;
    //! Color of the last printed call in mode Color-by-Call
    int color;
    //! Only consider SDP messages from Calls
    int sdp_only;
};

/**
 * @brief Create a new groupt to hold Calls in it
 *
 * Allocate memory to create a new calls group
 *
 * @return Pointer to a new group
 */
sip_call_group_t*
call_group_create();

/**
 * @brief Deallocate memory of an existing group
 *
 * @param Pointer to an existing group
 */
void
call_group_destroy(sip_call_group_t* group);

/**
 * @brief Check if any of the calls of the group has changed
 *
 * This checks all the group flags to check if any of the call has
 * changed.
 *
 * @param ggroup Call group structure pointer
 * @return true if any of the calls of the group has changed, false otherwise
 */
bool
call_group_has_changed(sip_call_group_t* group);

/**
 * @brief Clone an existing call group
 *
 * Create a new call group with the same calls of the
 * original one. Beware: The call pointers are shared between
 * original and clone groups.
 *
 */
sip_call_group_t*
call_group_clone(sip_call_group_t* original);

/**
 * @brief Add a Call to the group
 *
 * @param group Pointer to an existing group
 * @param call Pointer to an existing call
 */
void
call_group_add(sip_call_group_t* group, sip_call_t* call);

/**
 * @brief Add several Calls to the group
 *
 * @param group Pointer to an existing group
 * @param calls Pointer to a vector with calls
 */
void
call_group_add_calls(sip_call_group_t* group, vector_t* calls);

/**
 * @brief Remove a call from the group
 *
 * @param group Pointer to an existing group
 * @param call Pointer to an existing call
 */
void
call_group_del(sip_call_group_t* group, sip_call_t* call);

/**
 * @brief Check if a call is in the group
 *
 * @param group Pointer to an existing group
 * @param call Pointer to an existing call
 * @return 1 if the call is in the group, 0 otherwise
 */
int
call_group_exists(sip_call_group_t* group, sip_call_t* call);

/**
 * @brief Return the color pair number of a call
 *
 * When color by callid mode is enabled, this function will
 * return the color pair number of the call depending its
 * position inside the call
 *
 * @param group Pointer to an existing group
 * @param call Pointer to an existing call
 * @return Color pair number
 */
int
call_group_color(sip_call_group_t* group, sip_call_t* call);

/**
 * @brief Return the next call in the group
 *
 * Return then next call after the given call parameter.
 * If NULL is used as parameter, return the first call.
 * It will return NULL if last call is given as parameter.
 *
 * @param group Pointer to an existing group
 * @param call Pointer to an existing call or NULL
 * @return Next call of the group, or NULL
 */
sip_call_t*
call_group_get_next(sip_call_group_t* group, sip_call_t* call);

/**
 * @brief Return number of calls in a group
 *
 * @param group Pointer to an existing group
 * @return How many calls the group has
 */
int
call_group_count(sip_call_group_t* group);

/**
 * @brief Return message count in the group
 *
 * Return the sum of messages of all calls in the group
 *
 * @param group Pointer to an existing group
 * @return How many messages have the calls in the group
 */
int
call_group_msg_count(sip_call_group_t* group);

/**
 * @brief Return Message position in the group
 *
 * Return how many messages are before the given message
 * sorting all messages in all group calls by timestamp
 *
 * @param group Pointer to an existing group
 * @param msg A sip message from a call in the group
 * @return The position of given message in the group
 */
int
call_group_msg_number(sip_call_group_t* group, sip_msg_t* msg);

/**
 * @brief Finds the next msg in a call group.
 *
 * If the passed msg is NULL it returns the first message
 * of the group.
 *
 * @param callgroup SIP call group structure
 * @param msg Actual SIP msg from any call of the group (can be NULL)
 * @return Next chronological message in the group or NULL
 */
sip_msg_t*
call_group_get_next_msg(sip_call_group_t* group, sip_msg_t* msg);

/**
 * @brief Find the previous message in a call group
 *
 * @param callgroup SIP call group structure
 * @param msg Actual SIP msg from any call of the group
 * @return Previous chronological message in the group or NULL
 */
sip_msg_t*
call_group_get_prev_msg(sip_call_group_t* group, sip_msg_t* msg);

/**
 * @brief Find the next stream in a call group
 *
 * @param callgroup SIP call group structure
 * @param msg Actual stream structure from any call of the group
 * @return next chronological stream in the group or NULL
 */
rtp_stream_t*
call_group_get_next_stream(sip_call_group_t* group, rtp_stream_t* stream);

/**
 * @brief Sort messages in a group by message time
 * @param vector sorted vector
 * @param item item to add to the vector
 */
void
call_group_msg_sorter(vector_t* vector, void* item);
