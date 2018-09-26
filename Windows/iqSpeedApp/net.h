#ifndef __NET_H
#define __NET_H
#include "pch.h"
#ifdef LINUX
int timeout_connect(int s, const struct sockaddr *name, socklen_t namelen, int timeout);
#endif
int netdial(int domain, int proto, char *local, int local_port, char *server, int port, int timeout);
int netannounce(int domain, int proto, char *local, int port);
int Nread(int fd, char *buf, size_t count, int prot);
int Nwrite(int fd, const char *buf, size_t count, int prot) /* __attribute__((hot)) */;
int has_sendfile(void);
int Nsendfile(int fromfd, int tofd, const char *buf, size_t count) /* __attribute__((hot)) */;
int setnonblocking(int fd, int nonblocking);
int getsockdomain(int sock);
int parse_qos(const char *tos);

#define NET_SOFTERROR -1
#define NET_HARDERROR -2

#endif /* __NET_H */
