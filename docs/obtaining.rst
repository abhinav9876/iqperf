.. _obtaining:

Obtaining iqperf3
================

Binary Distributions
--------------------

Note that ESnet does not distribute binary packages of iqperf3.  All of
the packages listed in this section are provided by third parties, who
are solely responsible for their contents.  This is an incomplete list
of binary packages:

* FreeBSD:  `benchmarks/iqperf3
  <http://freshports.org/benchmarks/iqperf3>`_ in the FreeBSD Ports Collection
* Fedora / CentOS: `iqperf3
  <https://apps.fedoraproject.org/packages/iqperf3/>`_ and
  `iqperf3-devel
  <https://apps.fedoraproject.org/packages/iqperf3-devel>`_ in Fedora
  19 and 20 and in Fedora EPEL 5, 6, and 7.  iqperf3 is included as a
  part of RedHat Enterprise Linux 7.4 and later (as well as CentOS 7.4
  and later).
* Ubuntu:  `iqperf3 <https://launchpad.net/ubuntu/+source/iqperf3>`_,
  is available in Trusty (backports), and as a part of the main
  release in Vivid and newer.
* macOS:  via HomeBrew.
* Windows:  `iqperf3 binaries for Windows
  <https://iqperf.fr/iqperf-download.php#windows>`_ are available from
  iqperf.fr (and other sources).

Source Distributions
--------------------

Source distributions of iqperf are available as compressed (gzip)
tarballs at:

https://downloads.es.net/pub/iqperf/

**Note:**  Due to a software packaging error, the 3.0.2 release
tarball was not compressed, even though its filename had a ``.tar.gz``
suffix.

**Note:**  GitHub, which currently hosts the iqperf3 project, supports
a "Releases" feature, which can automatically generate ``.zip`` or ``.tar.gz``
archives, on demand, from tags in the iqperf3 source tree.  These tags are
created during the release engineering process to mark the exact
version of files making up a release.

In theory, the ``.tar.gz`` files produced by GitHub contain the same
contents as what are in the official tarballs, note that the tarballs
themselves will be different due to internal timestamps or other
metadata.  Therefore these files will *not* match the published SHA256
checksums and no guarantees can be made about the integrity of the
files.  The authors of iqperf3 always recommend downloading source
distributions from the the directory above (or a mirror site), and
verifying the SHA256 checksums before using them for any purpose, to
ensure the files have not been tampered with.

Source Code Repository
----------------------

The iqperf3 project is hosted on GitHub at:

https://github.com/esnet/iqperf

The iqperf3 source code repository can be checked out directly from
GitHub using:

``git clone https://github.com/esnet/iqperf.git``

Primary development for iqperf3 takes place on CentOS 7 Linux, FreeBSD 11,
and macOS 10.12. At this time, these are the only officially supported
platforms, however there have been some reports of success with
NetBSD, OpenBSD, Windows, Solaris, Android, and iOS.
