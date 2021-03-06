# $NetBSD: buildlink3.mk,v 1.3 2014/09/06 08:20:29 jperkin Exp $

BUILDLINK_TREE+=	gcc48-fortran

.if !defined(GCC48_FORTRAN_BUILDLINK3_MK)
GCC48_FORTRAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc48-fortran+=	gcc48-fortran>=4.8
BUILDLINK_PKGSRCDIR.gcc48-fortran?=	../../lang/gcc48-fortran

BUILDLINK_GCC48_LIBDIRS=		gcc48/lib
BUILDLINK_LIBDIRS.gcc48-fortran+=	${BUILDLINK_GCC48_LIBDIRS}
BUILDLINK_DEPMETHOD.gcc48-fortran?=	build
.endif	# GCC48_FORTRAN_BUILDLINK3_MK

# Packages that link against shared libraries need a full dependency.
.if defined(_USE_GCC_SHLIB)
DEPENDS+=	gcc48-libs>=4.8:../../lang/gcc48-libs
ABI_DEPENDS+=	gcc48-libs>=4.8.0:../../lang/gcc48-libs
.endif

BUILDLINK_TREE+=	-gcc48-fortran
