# $NetBSD: Makefile,v 1.31 2014/08/28 10:27:28 obache Exp $
#

DISTNAME=	ibus-handwrite-3.0.0
CATEGORIES=	inputmethod
MASTER_SITES=	https://github.com/microcai/ibus-handwrite/releases/download/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus-handwrite/
COMMENT=	Handwrite recognizer for ibus
LICENSE=	gnu-gpl-v3

DEPENDS+=	zinnia-tomoe-[0-9]*:../../inputmethod/zinnia-tomoe

FIND_PREFIX:=	ZINNIA_TOMOE_DIR=zinnia-tomoe
.include "../../mk/find-prefix.mk"

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-zinnia
CONFIGURE_ARGS+=	--with-zinnia-tomoe=${ZINNIA_TOMOE_DIR}/lib/zinnia/model/tomoe

SUBST_CLASSES+=		locale_dir
SUBST_STAGE.locale_dir=	pre-configure
SUBST_FILES.locale_dir=	src/main.c
SUBST_VARS.locale_dir=	_PKGLOCALEDIR

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/zinnia/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
