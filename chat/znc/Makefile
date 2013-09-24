# $NetBSD$

DISTNAME=	znc-1.0
CATEGORIES=	chat
MASTER_SITES=	http://znc.in/releases/

MAINTAINER=	code@mmayer.net
HOMEPAGE=	http://znc.in/releases/
COMMENT=	ZNC is an advanced IRC bouncer
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

# OS X doesn't like stripping shared objects
.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=YES
.endif

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	znc.pc.in

.include "../../mk/bsd.pkg.mk"
