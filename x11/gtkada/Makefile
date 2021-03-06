# $NetBSD: Makefile,v 1.29 2014/09/02 08:32:36 jperkin Exp $
#

DISTNAME=	gtkada-${GTKADA_VERSION}
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	http://downloads.dragonlace.net/src/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	gtkada-rm-${GTKADA_VERSION}${EXTRACT_SUFX}

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://libre.adacore.com/libre/tools/gtkada/
COMMENT=	Ada graphical toolkit based on Gtk+
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl pkg-config
USE_LANGUAGES=		c ada c++ fortran

GTKADA_VERSION=		2.24.4.0
PKGCONFIG_OVERRIDE+=	projects/gtkada.pc.in
CONFIGURE_ARGS+=	--enable-nls \
			--with-GL=no
MAKE_ENV+=		PROCESSORS=${MAKE_JOBS}

SUBST_CLASSES+= 	docs lgnat
SUBST_STAGE.docs=	post-patch
SUBST_FILES.docs=	Makefile.in
SUBST_SED.docs=		-e 's/^all: \(.*\)/all: \1 docs/g'
SUBST_STAGE.lgnat=	post-patch
SUBST_FILES.lgnat=	src/tools/Makefile.in testgtk/Makefile.in
SUBST_SED.lgnat=	-e 's|-largs|-largs -lgnat|'

GENERATE_PLIST=	cd ${DESTDIR}${PREFIX}; \
		${FIND} * \( -type f -or -type l \) | ${SORT};

GTK2PC=		${BUILDLINK_DIR}/lib/pkgconfig/gtk+-2.0.pc

post-wrapper:
	# This hack works around missing gmodule entry in gtk2
	# pkgconfig file.  Remove it when gtk2 is properly fixed
	${CAT} ${GTK2PC} | ${SED} '/^Req/ s/$$/ gmodule-2.0/' > ${GTK2PC}.tmp
	${RM} ${GTK2PC}
	${MV} ${GTK2PC}.tmp ${GTK2PC}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MY_CONFIGURE_ENV} \
		./configure ${CONFIGURE_ARGS}

do-build:
	# This target is recreated because -j cannot be set, but
	# MAKE_JOBS_SAFE=yes is needed for PROCESSORS value
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gmake all

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/share/doc/gtkada/gtkada_ug/_sources

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
