#include "libft.h"

#include <error.h>

static int argp_init(const t_argp_option* opts)
{
    for (; opts->type != FT_ARGP_OPT_END; opts++) {
        switch (opts->type) {
        case FT_ARGP_OPT_BOOL:
            *(bool*)(opts->value) = 0;
            break;
        case FT_ARGP_OPT_STRING:
            *(const char**)(opts->value) = NULL; // Initialize string options to NULL
            break;
        default:
            error(0, 0, "invalid option type for '%d'", opts->type);
            return ARGP_ERR_INVALID_OPT;
        }
    }

    return ARGP_SUCCESS;
}

static int argp_value(const t_argp_option* opt, const char* arg, int* arg_parsed)
{
    switch (opt->type) {
    case FT_ARGP_OPT_BOOL:
        *(bool*)(opt->value) = 1;
        break;
    case FT_ARGP_OPT_STRING:
        if (arg == NULL) {
            return ARGP_ERR_NO_ARG; // Argument is required for string options
        }
        *(const char**)(opt->value) = arg;

        *arg_parsed = 1; // Indicate that an argument was parsed
        break;
    default:
        error(0, 0, "invalid option type for '%d'", opt->type);
        return ARGP_ERR_INVALID_OPT;
    }

    return ARGP_SUCCESS;
}

static int argp_short_opt(const t_argp_option* opts, char key, const char* arg, int* arg_parsed)
{
    if (!key) {
        error(0, 0, "invalid option -- ''");
    }

    for (; opts->type != FT_ARGP_OPT_END; opts++) {
        if (opts->key == 0) {
            continue; // Skip options without a key
        }

        if (opts->key == key) {
            int status = argp_value(opts, arg, arg_parsed);
            if (status == ARGP_SUCCESS) {
                return ARGP_SUCCESS;
            } else if (status == ARGP_ERR_NO_ARG) {
                error(0, 0, "option requires an argument -- '%c'", key);
                return ARGP_ERR_NO_ARG;
            }
            error(0, 0, "invalid option type for '%c'", key);
            return ARGP_ERR_INVALID_OPT;
        }
    }

    error(0, 0, "invalid option -- '%c'", key);

    return ARGP_ERR_INVALID_OPT;
}

static int
argp_long_opt(const t_argp_option* opts, const char* name, const char* arg, int* arg_parsed)
{
    for (; opts->type != FT_ARGP_OPT_END; opts++) {
        if (opts->name == NULL) {
            continue; // Skip options without a name
        }

        if (ft_strcmp(opts->name, name) == 0) {
            int status = argp_value(opts, arg, arg_parsed);
            if (status == ARGP_SUCCESS) {
                return ARGP_SUCCESS;
            } else if (status == ARGP_ERR_NO_ARG) {
                error(0, 0, "option requires an argument -- '%s'", name);
                return ARGP_ERR_NO_ARG;
            }
            error(0, 0, "invalid option type for '%s'", name);
            return ARGP_ERR_INVALID_OPT;
        }
    }

    error(0, 0, "invalid option -- '%s'", name);

    return ARGP_ERR_INVALID_OPT;
}

int ft_argp_parse(int argc, char** argv, int* arg_index, const t_argp_option* opts)
{
    argp_init(opts);

    if (arg_index)
        *arg_index = -1;

    int arg_parsed = 0; // Track if an argument was parsed
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            const char* arg = i + 1 < argc && (argv[i + 1][0] != '-') ? argv[i + 1] : NULL;
            // Check for long options
            if (argv[i][1] == '-') {
                int status = argp_long_opt(opts, &argv[i][2], arg, &arg_parsed);
                if (status != ARGP_SUCCESS) {
                    return status;
                }
            } else {
                // Check for short options
                int status = argp_short_opt(opts, argv[i][1], arg, &arg_parsed);
                if (status != ARGP_SUCCESS) {
                    return status;
                }
            }
        } else if (arg_index && *arg_index == -1) {
            if (!arg_parsed)
                *arg_index = i;

            arg_parsed = 0; // Reset arg_parsed for the next argument
        }
    }

    return ARGP_SUCCESS;
}
