# $NetBSD: Makefile,v 1.8 2014/05/29 23:36:12 wiz Exp $
#

DISTNAME=	Perl-PrereqScanner-1.016
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Perl-PrereqScanner/
COMMENT=	Tool to scan your Perl code for its prerequisites
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	{perl>=5.16.0,p5-CPAN-Meta-Requirements>=2.120.630}:../../devel/p5-CPAN-Meta-Requirements
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Module-Path-[0-9]*:../../filesystems/p5-Module-Path
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-PPI>=1.205:../../devel/p5-PPI
DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util
DEPENDS+=	p5-String-RewritePrefix>=0.005:../../textproc/p5-String-RewritePrefix
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

BUILD_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

PERL5_PACKLIST=	auto/Perl/PrereqScanner/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
