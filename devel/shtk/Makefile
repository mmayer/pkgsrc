# $NetBSD: Makefile,v 1.7 2014/08/14 13:48:21 jmmv Exp $

DISTNAME=	shtk-1.4
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jmmv/shtk/releases/download/${DISTNAME}/

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Application toolkit for POSIX-compliant shell scripts
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LANGUAGES=		# empty
USE_TOOLS=		pkg-config

CONFIGURE_ARGS+=	SHTK_SHELL="${SH}"

PKG_OPTIONS_VAR=	PKG_OPTIONS.shtk
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if $(PKG_OPTIONS:Mtests)
.  include "../../devel/atf/buildlink3.mk"
CONFIGURE_ARGS+=	--with-atf=yes
PLIST_SUBST+=		TESTS=
.else
CONFIGURE_ARGS+=	--with-atf=no
PLIST_SUBST+=		TESTS=@comment
.endif

.include "../../mk/bsd.pkg.mk"
