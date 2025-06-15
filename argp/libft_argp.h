#ifndef LIBFT_ARGP_H
#define LIBFT_ARGP_H

typedef enum e_argp_err
{
    ARGP_SUCCESS,         // Success
    ARGP_ERR_NO_ARG,      // No argument provided for an option that requires one
    ARGP_ERR_INVALID_OPT, // Invalid option type or unknown option
} t_argp_err;

typedef enum e_argp_opt_type
{
    FT_ARGP_OPT_END,    // End of options
    FT_ARGP_OPT_BOOL,   // Boolean flag option (no argument)
    FT_ARGP_OPT_STRING, // String option (takes a string argument)
    FT_ARGP_OPT_INT,    // Option takes an integer argument
} t_argp_opt_type;

typedef struct s_argp_option
{
    t_argp_opt_type type;  // Type of the option
    const char*     name;  // Long option name
    char            key;   // Short option key
    void*           value; // Pointer to store the value of the option
    const char*     help;  // Help text for the option
} t_argp_option;

void ft_argp_parse(int argc, char** argv, int* arg_index, const t_argp_option* opts);

#endif
