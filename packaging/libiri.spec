Name:    libiri
Summary: a simple library for parsing Internationalized Resource Identifiers (IRIs)
Version: 1.7
Release: 1
Group:   Development/Libraries
License: TO_BE_FILLED
Source0: %{name}-%{version}.tar.gz
BuildRequires: pkgconfig(dlog)

%description
a simple library for parsing Internationalized Resource Identifiers (IRIs)


%package devel
Summary:    a simple library for parsing Internationalized Resource Identifiers (IRIs) (Developement)
Group:      Development/Libraries
Requires:   %{name} = %{version}

%description devel
a simple library for parsing Internationalized Resource Identifiers (IRIs) (Developement)

%prep
%setup -q

%build
./autogen.sh --prefix=/usr
make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
mkdir -p %{buildroot}/usr/share/license
cp LICENSE %{buildroot}/usr/share/license/%{name}
%make_install

%clean
rm -rf %{buildroot}

%post

%postun


%files
%manifest libiri.manifest
%defattr(-,root,root,-)
%{_libdir}/libiri.so
%{_bindir}/iri-config
%{_datadir}/license/%{name}

%files devel
%defattr(-,root,root,-)
%{_includedir}/iri.h
%{_libdir}/pkgconfig/libiri.pc
