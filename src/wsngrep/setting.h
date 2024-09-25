#pragma once

//! Max setting value
#define MAX_SETTING_LEN   1024

//! Max extra length needed for "/.sngreprc.old"
#define RCFILE_EXTRA_LEN   16

//! Shorter declarartion of setting_option struct
typedef struct setting_option setting_t;

//! Generic setting formats
#define SETTING_ENUM_ONOFF       (const char *[]){ "on", "off", NULL }
#define SETTING_ENUM_YESNO       (const char *[]){ "yes", "no", NULL }
#define SETTING_ENUM_BACKGROUND  (const char *[]){ "dark" , "default", NULL }
#define SETTING_ENUM_COLORMODE   (const char *[]){ "request", "cseq", "callid", NULL }
#define SETTING_ENUM_HIGHLIGHT   (const char *[]){ "bold", "reverse", "reversebold", NULL }
#define SETTING_ENUM_SDP_INFO    (const char *[]){ "off", "first", "full", "compressed", NULL}
#define SETTING_ENUM_STORAGE     (const char *[]){ "none", "memory", NULL }
#define SETTING_ENUM_HEPVERSION  (const char *[]){ "2", "3", NULL }
#define SETTING_ENUM_MEDIA       (const char *[]){ "off", "on", "active", NULL }

//! Other useful defines
#define SETTING_ON  "on"
#define SETTING_OFF "off"
#define SETTING_YES "yes"
#define SETTING_NO  "no"
#define SETTING_ACTIVE "active"


//! Available setting Options
enum setting_id {
    SETTING_BACKGROUND = 0,
    SETTING_COLORMODE,
    SETTING_SYNTAX,
    SETTING_SYNTAX_TAG,
    SETTING_SYNTAX_BRANCH,
    SETTING_ALTKEY_HINT,
    SETTING_EXITPROMPT,
    SETTING_CAPTURE_LIMIT,
    SETTING_CAPTURE_DEVICE,
    SETTING_CAPTURE_OUTFILE,
    SETTING_CAPTURE_BUFFER,
#if defined(WITH_GNUTLS) || defined(WITH_OPENSSL)
    SETTING_CAPTURE_KEYFILE,
    SETTING_CAPTURE_TLSSERVER,
#endif
#ifdef USE_EEP
    SETTING_CAPTURE_EEP,
#endif
    SETTING_CAPTURE_RTP,
    SETTING_CAPTURE_STORAGE,
    SETTING_CAPTURE_ROTATE,
    SETTING_SIP_NOINCOMPLETE,
    SETTING_SIP_HEADER_X_CID,
    SETTING_SIP_CALLS,
    SETTING_SAVEPATH,
    SETTING_DISPLAY_ALIAS,
    SETTING_ALIAS_PORT,
    SETTING_CL_SCROLLSTEP,
    SETTING_CL_COLORATTR,
    SETTING_CL_AUTOSCROLL,
    SETTING_CL_SORTFIELD,
    SETTING_CL_SORTORDER,
    SETTING_CF_FORCERAW,
    SETTING_CF_RAWMINWIDTH,
    SETTING_CF_RAWFIXEDWIDTH,
    SETTING_CF_SPLITCALLID,
    SETTING_CF_HIGHTLIGHT,
    SETTING_CF_SCROLLSTEP,
    SETTING_CF_LOCALHIGHLIGHT,
    SETTING_CF_SDP_INFO,
    SETTING_CF_MEDIA,
    SETTING_CF_ONLYMEDIA,
    SETTING_CF_DELTA,
    SETTING_CR_SCROLLSTEP,
    SETTING_CR_NON_ASCII,
    SETTING_FILTER_PAYLOAD,
    SETTING_FILTER_METHODS,
#ifdef USE_EEP
    SETTING_EEP_SEND,
    SETTING_EEP_SEND_VER,
    SETTING_EEP_SEND_ADDR,
    SETTING_EEP_SEND_PORT,
    SETTING_EEP_SEND_PASS,
    SETTING_EEP_SEND_ID,
    SETTING_EEP_LISTEN,
    SETTING_EEP_LISTEN_VER,
    SETTING_EEP_LISTEN_ADDR,
    SETTING_EEP_LISTEN_PORT,
    SETTING_EEP_LISTEN_PASS,
    SETTING_EEP_LISTEN_UUID,
#endif
    SETTING_COUNT
};

//! Available setting formats
enum setting_fmt {
    SETTING_FMT_STRING = 0,
    SETTING_FMT_NUMBER,
    SETTING_FMT_ENUM,
};

/**
 * @brief Configurable Setting structure
 */
struct setting_option {
    //! Setting id
    enum setting_id id;
    //! Setting name
    const char* name;
    //! Setting format
    enum setting_fmt fmt;
    //! Value of the setting
    char value[MAX_SETTING_LEN];
    //! Compa separated valid values
    const char** valuelist;
};

setting_t*
setting_by_id(int id);

setting_t*
setting_by_name(const char* name);

/**
 * @brief Return the setting id of a given string
 *
 * @param name String representing configurable setting
 * @return setting id or -1 if setting is not found
 */
int
setting_id(const char* name);

/**
 * @brief Return string representing given setting id
 *
 * @param id Setting id from settings enum
 * @return string representation of setting or NULL
 */
const char*
setting_name(int id);

int
setting_format(int id);

const char**
setting_valid_values(int id);

const char*
setting_get_value(int id);

int
setting_get_intvalue(int id);

void
setting_set_value(int id, const char* value);

void
setting_set_intvalue(int id, int value);

int
setting_enabled(int id);

int
setting_disabled(int id);

int
setting_has_value(int id, const char* value);

void
setting_toggle(int id);

const char*
setting_enum_next(int id, const char* value);

/**
 * @brief Dump configuration settings
 *
 * This function will print to stdout configuration settings
 * after reading system/local/user resource files (in that order).
 *
 */
void
settings_dump();