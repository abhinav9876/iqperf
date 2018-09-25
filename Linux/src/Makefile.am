lib_LTLIBRARIES         = libiqperf.la                                   # Build and install an iqperf library
bin_PROGRAMS            = iqperf3                                        # Build and install an iqperf binary
if ENABLE_PROFILING
noinst_PROGRAMS         = t_timer t_units t_uuid t_api iqperf3_profile   # Build, but don't install the test programs and a profiled version of iqperf3
else
noinst_PROGRAMS         = t_timer t_units t_uuid t_api                  # Build, but don't install the test programs
endif
include_HEADERS         = iqperf_api.h                                   # Defines the headers that get installed with the program


# Specify the source files and flags for the iqperf library
libiqperf_la_SOURCES     = \
                        cjson.c \
                        cjson.h \
                        flowlabel.h \
                        iqperf.h \
                        iqperf_api.c \
                        iqperf_api.h \
                        iqperf_error.c \
                        iqperf_auth.h \
                        iqperf_auth.c \
                        iqperf_client_api.c \
                        iqperf_locale.c \
                        iqperf_locale.h \
                        iqperf_server_api.c \
                        iqperf_tcp.c \
                        iqperf_tcp.h \
                        iqperf_udp.c \
                        iqperf_udp.h \
                        iqperf_sctp.c \
                        iqperf_sctp.h \
                        iqperf_util.c \
                        iqperf_util.h \
                        dscp.c \
                        net.c \
                        net.h \
                        portable_endian.h \
                        queue.h \
                        tcp_info.c \
                        timer.c \
                        timer.h \
                        units.c \
                        units.h \
                        version.h

# Specify the sources and various flags for the iqperf binary
iqperf3_SOURCES          = main.c
iqperf3_CFLAGS           = -g
iqperf3_LDADD            = libiqperf.la
iqperf3_LDFLAGS          = -g

if ENABLE_PROFILING
# If the iqperf-profiled-binary is enabled (and this condition is true by default)
# Specify the sources and various flags for the profiled iqperf binary. This
# binary recompiles all the source files to make sure they are all profiled.
iqperf3_profile_SOURCES  = main.c \
                          $(libiqperf_la_SOURCES)

iqperf3_profile_CFLAGS   = -pg -g
iqperf3_profile_LDADD    = libiqperf.la
iqperf3_profile_LDFLAGS  = -pg -g
endif

# Specify the sources and various flags for the test cases
t_timer_SOURCES         = t_timer.c
t_timer_CFLAGS          = -g
t_timer_LDFLAGS         =
t_timer_LDADD           = libiqperf.la

t_units_SOURCES         = t_units.c
t_units_CFLAGS          = -g
t_units_LDFLAGS         =
t_units_LDADD           = libiqperf.la

t_uuid_SOURCES          = t_uuid.c
t_uuid_CFLAGS           = -g
t_uuid_LDFLAGS          =
t_uuid_LDADD            = libiqperf.la

t_api_SOURCES           = t_api.c
t_api_CFLAGS            = -g
t_api_LDFLAGS           =
t_api_LDADD             = libiqperf.la



# Specify which tests to run during a "make check"
TESTS                   = \
                        t_timer \
                        t_units \
                        t_uuid  \
                        t_api

dist_man_MANS          = iqperf3.1 libiqperf.3
