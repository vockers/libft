#include "libft.h"

#include <error.h>

static void argp_init(const t_argp_option* opts)
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
            error(EXIT_FAILURE, 0, "invalid option type for '%d'", opts->type);
        }
    }
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
        error(EXIT_FAILURE, 0, "invalid option type for '%d'", opt->type);
        break;
    }

    return ARGP_SUCCESS;
}

static void argp_short_opt(const t_argp_option* opts, char key, const char* arg, int* arg_parsed)
{
    if (!key) {
        error(EXIT_FAILURE, 0, "invalid option -- ''");
    }

    for (; opts->type != FT_ARGP_OPT_END; opts++) {
        if (opts->key == 0) {
            continue; // Skip options without a key
        }

        if (opts->key == key) {
            if (argp_value(opts, arg, arg_parsed) != ARGP_SUCCESS) {
                error(EXIT_FAILURE, 0, "option requires an argument -- '%c'", key);
            }
            return;
        }
    }

    error(EXIT_FAILURE, 0, "invalid option -- '%c'", key);
}

static void
argp_long_opt(const t_argp_option* opts, const char* name, const char* arg, int* arg_parsed)
{
    for (; opts->type != FT_ARGP_OPT_END; opts++) {
        if (opts->name == NULL) {
            continue; // Skip options without a name
        }

        if (ft_strcmp(opts->name, name) == 0) {
            if (argp_value(opts, arg, arg_parsed) != ARGP_SUCCESS) {
                error(EXIT_FAILURE, 0, "option requires an argument -- '%s'", name);
            }
            return;
        }
    }

    error(EXIT_FAILURE, 0, "invalid option -- '%s'", name);
}

void ft_argp_parse(int argc, char** argv, int* arg_index, const t_argp_option* opts)
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
                argp_long_opt(opts, &argv[i][2], arg, &arg_parsed);
            } else {
                // Check for short options
                argp_short_opt(opts, argv[i][1], arg, &arg_parsed);
            }
        } else if (arg_index && *arg_index == -1) {
            if (!arg_parsed)
                *arg_index = i;

            arg_parsed = 0; // Reset arg_parsed for the next argument
        }
    }
}
