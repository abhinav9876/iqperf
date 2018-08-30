
Summary
-------

iqperf is a tool for active measurements of the maximum achievable
bandwidth on IP networks.  It supports tuning of various parameters
related to timing, protocols, and buffers.  For each test it reports
the measured throughput / bitrate, loss, and other parameters.

This version, sometimes referred to as iqperf3, is a redesign of an
original version developed at NLANR/DAST.  iqperf3 is a new
implementation from scratch, with the goal of a smaller, simpler code
base, and a library version of the functionality that can be used in
other programs. iqperf3 also has a number of features found in other tools
such as nuttcp and netperf, but were missing from the original iqperf.
These include, for example, a zero-copy mode and optional JSON output.
Note that iqperf3 is *not* backwards compatible with the original iqperf.

Primary development for iqperf3 takes place on CentOS Linux, FreeBSD,
and macOS.  At this time, these are the only officially supported
platforms, however there have been some reports of success with
OpenBSD, NetBSD, Android, Solaris, and other Linux distributions.

Building iqperf3
---------------

### Prerequisites: ###

None.

### Building ###

    ./configure; make; make install

(Note: If configure fails, try running `./bootstrap.sh` first)

Invoking iqperf3
---------------

iqperf3 includes a manual page listing all of the command-line options.
The manual page is the most up-to-date reference to the various flags and parameters.


Using the default options, iqperf is meant to show typical well
designed application performance.  "Typical well designed application"
means avoiding artificial enhancements that work only for testing
(such as splice()'ing the data to /dev/null).  iqperf does also have
flags for "extreme best case" optimizations, but they must be
explicitly activated.

These flags include:

    -Z, --zerocopy            use a 'zero copy' sendfile() method of sending data
    -A, --affinity n/n,m      set CPU affinity


options:

    -V, --verbose             more detailed output than before
    -J, --json                output in JSON format
    -Z, --zerocopy            use a 'zero copy' sendfile() method of sending data
    -O, --omit N              omit the first n seconds (to ignore slowstart)
    -T, --title str           prefix every output line with this string
    -F, --file name           xmit/recv the specified file
    -A, --affinity n/n,m      set CPU affinity (Linux and FreeBSD only)
    -k, --blockcount #[KMG]   number of blocks (packets) to transmit (instead 
                              of -t or -n)
    -L, --flowlabel           set IPv6 flow label (Linux only)

Changed flags:

    -C, --linux-congestion    set congestion control algorithm (Linux only)
                              (-Z in iqperf2)


Deprecated options:

Not planning to support these iqperf2 flags. If you really miss these
options, please submit a request in the issue tracker:

    -d, --dualtest           Do a bidirectional test simultaneously
    -r, --tradeoff           Do a bidirectional test individually
    -T, --ttl                time-to-live, for multicast (default 1)
    -x, --reportexclude [CDMSV]   exclude C(connection) D(data) M(multicast) 
                                  S(settings) V(server) reports
    -y, --reportstyle C      report as a Comma-Separated Values

Also deprecated is the ability to set the options via environment
variables.


