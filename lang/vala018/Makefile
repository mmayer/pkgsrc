# $NetBSD: Makefile,v 1.5 2014/08/09 22:11:02 wiz Exp $

DISTNAME=	vala-0.18.1
PKGNAME=	vala018-0.18.1
PKGREVISION=	1
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vala/0.18/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Vala
COMMENT=	Compiler for the GObject type system (0.18 branch)
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --enable-vapigen
CONFIGURE_ARGS+= --disable-unversioned
USE_LIBTOOL=	yes
USE_TOOLS+=		bison flex gmake pkg-config

PKGCONFIG_OVERRIDE+=	libvala.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
BUILDLINK_DEPMETHOD.libxslt=			build

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
