# $NetBSD: Makefile,v 1.21 2014/05/29 23:38:00 wiz Exp $

DISTNAME=	CGI-FastTemplate-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
SVR4_PKGNAME=	p5cgf
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-FastTemplate
COMMENT=	Perl5 extension for managing templates
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CGI/FastTemplate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
