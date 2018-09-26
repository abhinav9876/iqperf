
#ifndef __IPERF_UTIL_H
#define __IPERF_UTIL_H

#include "iperf_config.h"
#include "cjson.h"
#ifdef LINUX
#include <sys/select.h>
#else
#include <sys/timeb.h>
#include <sys/types.h>
#include <winsock2.h>
#endif
#include <stddef.h>

int readentropy(void *out, size_t outsize);

void fill_with_repeating_pattern(void *out, size_t outsize);

void make_cookie(char *);

int is_closed(int);

double timeval_to_double(struct timeval *tv);

int timeval_equals(struct timeval *tv0, struct timeval *tv1);

double timeval_diff(struct timeval *tv0, struct timeval *tv1);

void cpu_util(double pcpu[3]);

const char* get_system_info(void);

const char* get_optional_features(void);

cJSON* iperf_json_printf(const char *format, ...);

void iperf_dump_fdset(FILE *fp, char *str, int nfds, fd_set *fds);

#ifndef HAVE_DAEMON
extern int daemon(int nochdir, int noclose);
#endif /* HAVE_DAEMON */

#ifndef HAVE_GETLINE
ssize_t getline(char **buf, size_t *bufsiz, FILE *fp);
#endif /* HAVE_GETLINE */

#endif
