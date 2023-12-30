/*
 * Error handling routines
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
int errors;
int warnings;
int dbflag = 1;

void fatal(char *fmt,...)
{
        va_list args;
        va_start(args,fmt);
        fprintf(stderr, "\nFatal error: ");
        vfprintf(stderr, fmt, args);
        fprintf(stderr, "\n");
        va_end(args);
        exit(1);
}

void error(char *fmt, ...)
{
        va_list args;
        va_start(args,fmt);
        fprintf(stderr, "\nError: ");
        fprintf(stderr, fmt, args);
        fprintf(stderr, "\n");
        errors++;
        va_end(args);
}

void warning(char *fmt,...)
{
        va_list args;
        va_start(args,fmt);
        fprintf(stderr, "\nWarning: ");
        fprintf(stderr, fmt,args);
        fprintf(stderr, "\n");
        warnings++;
        va_end(args);
}

void debug(char *fmt,...)
{
        va_list args;
        va_start(args,fmt);
        if(!dbflag) return;
        fprintf(stderr, "\nDebug: ");
        fprintf(stderr, fmt, args);
        fprintf(stderr, "\n");
        va_end(args);
}

