Name:           libiri
Version:	1.1
Release:	1
License:	BSD
Summary:	An IRI parsing library
Url:		http://code.google.com/p/libiri/
Group:		Libraries
Source:		%{name}-%{version}.tar.gz
BuildRequires:	autoconf, automake, libtool

%description
libiri is a simple toolkit for parsing Internationalized Resource Identifiers (IRIs).

For many intents and purposes, you can think of libiri as a “URL parser which supports Unicode”.

Specifically:

URLs are a subset of URIs
URIs are restricted to a portion of the ASCII character set
IRIs are a superset of URIs that are not restricted to ASCII characters
If something is a valid URL or URI, it's also a valid IRI.

%prep
%setup -q

%build
sh ./autogen.sh
%configure
make %{?_smp_mflags}

%install
%make_install



%files
%{_libdir}/*.so


%package devel
Summary:    An IRI parsing library - Development Files
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}

%description devel
libiri is a simple toolkit for parsing Internationalized Resource Identifiers (IRIs).

%files devel
%{_libdir}/pkgconfig/*.pc
%{_includedir}/*.h
/usr/bin/iri-config
