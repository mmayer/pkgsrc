# $NetBSD: Makefile,v 1.15 2014/05/31 07:28:57 obache Exp $
#

.include "../../databases/qdbm/Makefile.common"

PKGNAME=	p5-qdbm-1.0.0.${QDBM_VERSION}
CATEGORIES=	databases perl5

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://fallabs.com/qdbm/plspex.html
COMMENT=	Perl interface of QDBM
LICENSE=	gnu-lgpl-v2.1

MAKE_JOBS_SAFE=		no

MY_SUBDIR=perl
BUILD_DIRS=	${MY_SUBDIR}
CONFIGURE_DIRS=	${MY_SUBDIR}

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl
PERL5_CONFIGURE=	no
TEST_TARGET=		check

PERL5_PACKLIST= auto/Curia/.packlist auto/Depot/.packlist auto/Villa/.packlist
REPLACE_PERL=	${MY_SUBDIR}/curia/plcrtest ${MY_SUBDIR}/depot/pldptest \
		${MY_SUBDIR}/villa/plvltest

.include "../../databases/qdbm/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	${MY_SUBDIR}/configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
