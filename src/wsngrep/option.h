#pragma once
#include <stdint.h>

//! Shorter declaration of config_option struct
typedef struct config_option option_opt_t;

//! Option types
enum option_type {
    COLUMN = 0,
    ALIAS
};

/**
 * @brief Configurable option structure
 *
 * sngrep is optionured by a group of attributes that can be
 * modified using resource files.
 */
struct config_option {
    //! Setting type
    enum option_type type;
    //! Name of attribute
    char* opt;
    //! Value of attribute
    char* value;
};

/**
 * @brief Initialize all program options
 *
 * This function will give all available settings an initial value.
 * This values can be overriden using resources files, either from system dir
 * or user home dir.
 *
 * @param no_config Do not load config file if set to 1
 * @return 0 in all cases
 */
int init_options(int no_config);

/**
 * @brief Deallocate options memory
 *
 * Deallocate memory used for program configurations
 */
void deinit_options();

/**
 * @brief Read optionuration directives from file
 *
 * This function will parse passed filenames searching for configuration
 * directives of sngrep. See documentation for a list of available
 * directives and attributes
 *
 * @param fname Full path configuration file name
 * @return 0 in case of parse success, -1 otherwise
 */
int read_options(const char* fname);

/**
 * @brief Get settings option value (string)
 *
 * Used in all the program to access the optionurable options of sngrep
 * Use this function instead of accessing optionuration array.
 *
 * @param opt Name of optionurable option
 * @return configuration option value or NULL if not found
 */
const char* get_option_value(const char* opt);

/**
 * @brief Get settings option value (int)
 *
 * Basically the same as get_option_value converting the result to
 * integer.
 * Use this function instead of accessing configuration array.
 *
 * @todo -1 is an error!
 *
 * @param opt Name of optionurable option
 * @return option numeric value or -1 in case of error
 */
int get_option_int_value(const char* opt);

/**
 * @brief Sets a settings option value
 *
 * Basic setter for 'set' directive attributes
 *
 * @param opt Name of configuration option
 * @param value Value of configuration option
 */
void set_option_value(const char* opt, const char* value);

/**
 * @brief Sets an alias for a given address
 *
 * @param address IP Address
 * @param string representing the alias
 */
void set_alias_value(const char* address, const char* alias);

/**
 * @brief Get alias for a given address (string)
 *
 * @param address IP Address
 * @return configured alias or address if alias not found
 */
const char* get_alias_value(const char* address);

/**
 * @brief Get alias for a given address and port (string)
 *
 * @param address IP Address
 * @param port port
 * @return configured alias or address if alias not found
 */
const char* get_alias_value_vs_port(const char* address, uint16_t port);
