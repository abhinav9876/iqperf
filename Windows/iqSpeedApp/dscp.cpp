#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#ifdef WIN32
#pragma warning(disable:4996)
#define strcasecmp(a,b) _stricmp(a,b)
#define snprintf _snprintf
#endif

int parse_qos(const char *cp);
const char * iptos2str(int iptos);

/*
 * Definitions for IP type of service (ip_tos)
 */

#if HAVE_NETINET_IN_SYSTM_H
#include <netinet/in_systm.h>
#endif
#if HAVE_NETINET_IP_H
#include <netinet/ip.h>
#endif

#ifndef IPTOS_LOWDELAY
# define IPTOS_LOWDELAY          0x10
# define IPTOS_THROUGHPUT        0x08
# define IPTOS_RELIABILITY       0x04
# define IPTOS_LOWCOST           0x02
# define IPTOS_MINCOST           IPTOS_LOWCOST
#endif /* IPTOS_LOWDELAY */

/*
 * Definitions for DiffServ Codepoints as per RFC2474
 */
#ifndef IPTOS_DSCP_AF11
# define	IPTOS_DSCP_AF11		0x28
# define	IPTOS_DSCP_AF12		0x30
# define	IPTOS_DSCP_AF13		0x38
# define	IPTOS_DSCP_AF21		0x48
# define	IPTOS_DSCP_AF22		0x50
# define	IPTOS_DSCP_AF23		0x58
# define	IPTOS_DSCP_AF31		0x68
# define	IPTOS_DSCP_AF32		0x70
# define	IPTOS_DSCP_AF33		0x78
# define	IPTOS_DSCP_AF41		0x88
# define	IPTOS_DSCP_AF42		0x90
# define	IPTOS_DSCP_AF43		0x98
# define	IPTOS_DSCP_EF		0xb8
#endif /* IPTOS_DSCP_AF11 */

#ifndef IPTOS_DSCP_CS0
# define	IPTOS_DSCP_CS0		0x00
# define	IPTOS_DSCP_CS1		0x20
# define	IPTOS_DSCP_CS2		0x40
# define	IPTOS_DSCP_CS3		0x60
# define	IPTOS_DSCP_CS4		0x80
# define	IPTOS_DSCP_CS5		0xa0
# define	IPTOS_DSCP_CS6		0xc0
# define	IPTOS_DSCP_CS7		0xe0
#endif /* IPTOS_DSCP_CS0 */
#ifndef IPTOS_DSCP_EF
# define	IPTOS_DSCP_EF		0xb8
#endif /* IPTOS_DSCP_EF */

static const struct {
	const char *name;
	int value;
} ipqos[] = {
	{ "af11", IPTOS_DSCP_AF11 },
	{ "af12", IPTOS_DSCP_AF12 },
	{ "af13", IPTOS_DSCP_AF13 },
	{ "af21", IPTOS_DSCP_AF21 },
	{ "af22", IPTOS_DSCP_AF22 },
	{ "af23", IPTOS_DSCP_AF23 },
	{ "af31", IPTOS_DSCP_AF31 },
	{ "af32", IPTOS_DSCP_AF32 },
	{ "af33", IPTOS_DSCP_AF33 },
	{ "af41", IPTOS_DSCP_AF41 },
	{ "af42", IPTOS_DSCP_AF42 },
	{ "af43", IPTOS_DSCP_AF43 },
	{ "cs0", IPTOS_DSCP_CS0 },
	{ "cs1", IPTOS_DSCP_CS1 },
	{ "cs2", IPTOS_DSCP_CS2 },
	{ "cs3", IPTOS_DSCP_CS3 },
	{ "cs4", IPTOS_DSCP_CS4 },
	{ "cs5", IPTOS_DSCP_CS5 },
	{ "cs6", IPTOS_DSCP_CS6 },
	{ "cs7", IPTOS_DSCP_CS7 },
	{ "ef", IPTOS_DSCP_EF },
	{ "lowdelay", IPTOS_LOWDELAY },
	{ "throughput", IPTOS_THROUGHPUT },
	{ "reliability", IPTOS_RELIABILITY },
	{ NULL, -1 }
};

int
parse_qos(const char *cp)
{
	unsigned int i;
	char *ep = NULL;
	long val;

	if (cp == NULL)
		return -1;
	for (i = 0; ipqos[i].name != NULL; i++) {
		if (strcasecmp(cp, ipqos[i].name) == 0)
			return ipqos[i].value;
	}
	/* Try parsing as an integer */
	val = strtol(cp, &ep, 0);
	if (*cp == '\0' || *ep != '\0' || val < 0 || val > 255)
		return -1;
	return val;
}

const char *
iptos2str(int iptos)
{
	int i;
	static char iptos_str[sizeof "0xff"];
	if (iptos < 0 || iptos > 64) iptos = 0;
	for (i = 0; ipqos[i].name != NULL; i++) {
		if (ipqos[i].value == iptos)
			return ipqos[i].name;
	}
	snprintf(iptos_str, sizeof iptos_str, "0x%02x", iptos);
	return iptos_str;
}
