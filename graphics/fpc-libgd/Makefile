# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-libgd

COMMENT=	Free Pascal interface to libgd for producing graphics files

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBGD
LIBGD_DESC=	Install gd graphic library
OPTIONS_DEFAULT=	LIBGD

LIBGD_LIB_DEPENDS=	libgd.so:graphics/gd

.include "${MASTERDIR}/Makefile"
