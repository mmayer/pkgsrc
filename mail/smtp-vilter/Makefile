# $NetBSD: Makefile,v 1.7 2014/09/29 08:35:51 jperkin Exp $

DISTNAME=		smtp-vilter-1.3.8
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tgz
PKGREVISION=		3

MAINTAINER=		marc@msys.ch
HOMEPAGE=		http://www.etc.msys.ch/software/smtp-vilter/
COMMENT=		milter to scan messages for viruses and spam

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		lex yacc

PKG_GROUPS=		vilter
PKG_USERS=		vilter:vilter
PKG_GECOS.vilter=	SMTP vilter

INSTALLATION_DIRS=	etc sbin lib/smtp-vilter man/man5 man/man8

.include "../../mail/libmilter/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
