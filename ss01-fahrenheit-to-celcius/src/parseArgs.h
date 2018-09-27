#include "options.h"

#ifndef _PARSE_ARGS_H_
#define _PARSE_ARGS_H_

/**
 * @brief           Entry point for calculating.
 * @param[in] text  Text to be processed.
 * @return          Calculated value.
 */
options parseArgs(options DEFAULT_OPTIONS, int argc, char* argv[]);

#endif