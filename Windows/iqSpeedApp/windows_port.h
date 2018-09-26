#pragma once
#pragma warning(disable:4996)


#define INET6_ADDRSTRLEN 48
#include "sys/getopt.h"
#include <cstdint>
#include <sys/stat.h>
#define pid_t int
#define S_IRUSR _S_IRUSR	
typedef short int ssize_t;
#define close(x)                        