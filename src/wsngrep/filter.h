#pragma once

#include "config.h"
#include "regex/regex.h"
#include "sip.h"

//! Shorter declaration of sip_call_group structure
typedef struct filter filter_t;

/**
 * @brief Available filter types
 */
enum filter_type {
    //! SIP From header in packet payload
    FILTER_SIPFROM = 0,
    //! SIP To header in packet payload
    FILTER_SIPTO,
    //! Packet source address
    FILTER_SOURCE,
    //! Packet destination address
    FILTER_DESTINATION,
    //! SIP Method in packet payload
    FILTER_METHOD,
    //! SIP Payload in any call packet
    FILTER_PAYLOAD,
    //! Displayed line in call list
    FILTER_CALL_LIST,
    //! Number of available filter types
    FILTER_COUNT,
};

/**
 * @brief Filter information
 */
struct filter {
    //! The filter text
    char* expr;
#ifdef WITH_PCRE
    //! The filter compiled expression
    pcre* regex;
#elif defined(WITH_PCRE2)
    //! The filter compiled expression
    pcre2_code* regex;
#else
    //! The filter compiled expression
    regex_t regex;
#endif
};

/**
 * @brief Set a given filter expression
 *
 * This function is used to set the filter expression
 * on a given filter. If given expression is NULL
 * the filter will be removed.
 *
 * @param type Type of the filter
 * @param expr Regexpression to match
 * @return 0 if the filter is valid, 1 otherwise
 */
int
filter_set(int type, const char* expr);

/**
 * @brief Get filter text expression
 *
 * @param type filter type
 * @return filter text expressions
 */
const char*
filter_get(int type);

/**
 * @brief Check if a call if filtered
 *
 * @param call Call to be checked
 * @return 1 if call is filtered
 */
int
filter_check_call(void* item);

/**
 * @brief Check if data matches the filter regexp
 *
 * @return 0 if the given data matches the filter
 */
int
filter_check_expr(filter_t filter, const char* data);

/**
 * @brief Reset filtered flag in all calls
 *
 * This function can be used to force reevaluation
 * of filters in all calls.
 */
void
filter_reset_calls();
