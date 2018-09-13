/* -----------------------
 ____  _  _   __   _  _
(__  )/ )( \ / _\ / )( \
 / _/ ) __ (/    \\ /\ /
(____)\_)(_/\_/\_/(_/\_)
-------------------------- */
/**
 * @file
 * @brief Converts Fahrenheit to Celcius
 * Accepts the lower (-l), upper (-u) limit and the stepsize (-s) as arguments
 * E.g. ./src/main -l -100 -u 50 -s 30
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int min;
    int max;
    int step;
} options;

float fahrenheitToCelcius(int fahrenheit)
{
    return (5 * (fahrenheit - 32)) / 9.0;
}

void printTemparatureTable(int MIN, int MAX, int STEP)
{
    printf("Fahrenheit\tCelcius\n");
    printf("-----------------------\n");
    for(int i = MIN; i <= MAX; i+=STEP) {
        printf("%4d\t\t%7.2f\n", i, fahrenheitToCelcius(i));
    }
}

options parseArgs(options DEFAULT_OPTIONS, int argc, char* argv[])
{
    options opts = DEFAULT_OPTIONS;
    int c;
    char *txt;
    while ((c = getopt(argc, argv, "l:u:s:")) != -1) {
        switch (c)
        {
            case 'l':
                opts.min = strtol(optarg, &txt, 10);
                break;
            case 'u':
                opts.max = strtol(optarg, &txt, 10);
                break;
            case 's':
                opts.step = strtol(optarg, &txt, 10);
                break;
            default:
                break;
        }
    }
    return opts;
}

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments
 *                  with argv[0] being the command call
 *                  argv[1] the 1st argument, ...
 *                  argv[argc-1] the last argument.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 */
int main(int argc, char* argv[])
{
    const options DEFAULT_OPTIONS = { -100, 200, 20 };

    const options opts = parseArgs(DEFAULT_OPTIONS, argc, argv);

    (void)printTemparatureTable(opts.min, opts.max, opts.step);

    return EXIT_SUCCESS;
}
