# $NetBSD: Makefile,v 1.14 2014/05/29 23:35:39 wiz Exp $

DISTNAME=	AutoLoader-5.74
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5aul
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AutoLoader/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AutoLoader/
COMMENT=	Perl automatic module loader
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/AutoLoader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
