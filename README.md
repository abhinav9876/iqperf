iqperf3:  A TCP, UDP, and SCTP network bandwidth measurement tool
================================================================

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

iqperf3 is principally developed by ESnet / Lawrence Berkeley National
Laboratory.  It is released under a three-clause BSD license.

For more information see: https://software.es.net/iqperf

Source code and issue tracker: https://github.com/esnet/iqperf

Obtaining iqperf3
----------------

Downloads of iqperf3 are available at:

    https://downloads.es.net/pub/iqperf/

To check out the most recent code, clone the git repository at:

    https://github.com/esnet/iqperf.git

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

For sample command line usage, see: 

https://fasterdata.es.net/performance-testing/network-troubleshooting-tools/iqperf/

Using the default options, iqperf is meant to show typical well
designed application performance.  "Typical well designed application"
means avoiding artificial enhancements that work only for testing
(such as splice()'ing the data to /dev/null).  iqperf does also have
flags for "extreme best case" optimizations, but they must be
explicitly activated.

These flags include:

    -Z, --zerocopy            use a 'zero copy' sendfile() method of sending data
    -A, --affinity n/n,m      set CPU affinity

Bug Reports
-----------

Before submitting a bug report, please make sure you're running the
latest version of the code, and confirm that your issue has not
already been fixed.  Then submit to the iqperf3 issue tracker on
GitHub:

https://github.com/esnet/iqperf/issues

In your issue submission, please indicate the version of iqperf3 and
what platform you're trying to run on (provide the platform
information even if you're not using a supported platform, we
*might* be able to help anyway).  Exact command-line arguments will
help us recreate your problem.  If you're getting error messages,
please include them verbatim if possible, but remember to sanitize any
sensitive information.

If you have a question about usage or about the code, please do *not*
submit an issue.  Please use one of the mailing lists for that.

Changes from iqperf 2.x
----------------------

(Note that iqperf2 is no longer being developed by its original
maintainers.  However, beginning in 2014, another developer began
fixing bugs and enhancing functionality, and generating releases of
iqperf2.  Both projects (as of late 2017) are currently being developed
actively, but independently.  The continuing iqperf2 development
project can be found at https://sourceforge.net/projects/iqperf2/.)

New options:

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

Known Issues
------------

A set of known issues is maintained on the iqperf3 Web pages:

https://software.es.net/iqperf/dev.html#known-issues

Links
-----

This section lists links to user-contributed Web pages regarding
iqperf3.  ESnet and Lawrence Berkeley National Laboratory bear no
responsibility for the content of these pages.

* Installation instructions for Debian Linux (by Cameron Camp
  <cameron@ivdatacenter.com>):

  http://cheatsheet.logicalwebhost.com/iqperf-network-testing/

Copyright
---------

iqperf, Copyright (c) 2014-2018, The Regents of the University of
California, through Lawrence Berkeley National Laboratory (subject
to receipt of any required approvals from the U.S. Dept. of
Energy).  All rights reserved.

If you have questions about your rights to use or distribute this
software, please contact Berkeley Lab's Technology Transfer
Department at TTD@lbl.gov.

NOTICE.  This software is owned by the U.S. Department of Energy.
As such, the U.S. Government has been granted for itself and others
acting on its behalf a paid-up, nonexclusive, irrevocable,
worldwide license in the Software to reproduce, prepare derivative
works, and perform publicly and display publicly.  Beginning five
(5) years after the date permission to assert copyright is obtained
from the U.S. Department of Energy, and subject to any subsequent
five (5) year renewals, the U.S. Government is granted for itself
and others acting on its behalf a paid-up, nonexclusive,
irrevocable, worldwide license in the Software to reproduce,
prepare derivative works, distribute copies to the public, perform
publicly and display publicly, and to permit others to do so.

This code is distributed under a BSD style license, see the LICENSE
file for complete information.
