# $NetBSD: Makefile,v 1.2 2014/05/29 23:38:08 wiz Exp $

DISTNAME=	HTTP-HeaderParser-XS-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-HeaderParser-XS/
COMMENT=	XS extension for processing HTTP headers
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c++
PERL5_PACKLIST=		auto/HTTP/HeaderParser/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
