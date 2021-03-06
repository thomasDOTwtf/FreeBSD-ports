# Created by: jseger@FreeBSD.org
# $FreeBSD$

PORTNAME=	freetype2
PORTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://savannah.nongnu.org/download/freetype/ \
		SF/freetype/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+\.[0-9]+).*/\1/}/ \
		http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/freetype2/ \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/freetype2/ \
		http://ftp.sunet.se/pub/text-processing/freetype/freetype2/ \
		ftp://ftp.freetype.org/freetype/freetype2/
DISTNAME=	${PORTNAME:S/2//}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Free and portable TrueType font rendering engine

LICENSE=	FTL GPLv2+
LICENSE_COMB=	dual
LICENSE_NAME_FTL=	The FreeType Project license
LICENSE_FILE_FTL=	${WRKSRC}/docs/FTL.TXT
LICENSE_FILE_GPLv2+ =	${WRKSRC}/docs/GPLv2.TXT
LICENSE_PERMS_FTL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe gmake libtool tar:bzip2
MAKE_ENV=	TOP=""
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-harfbuzz
CONFIGURE_WRKSRC=	${WRKSRC}/builds/unix

SUB_FILES=	pkg-message

PORTDOCS=	reference CHANGES formats.txt LICENSE.TXT raster.txt

CPE_PRODUCT=	freetype
CPE_VENDOR=	freetype

OPTIONS_DEFINE=		DEBUG DOCS LCD_FILTERING LONG_PCF_NAMES PNG \
		TABLE_VALIDATION
OPTIONS_GROUP=		SUBPIXEL_HINTING
OPTIONS_GROUP_SUBPIXEL_HINTING=	V38 V40
OPTIONS_RADIO=		SIZE_METRICS_CHOICE
OPTIONS_RADIO_SIZE_METRICS_CHOICE=	FIX_SIZE_METRICS TT_SIZE_METRICS
OPTIONS_DEFAULT=	LCD_FILTERING V40

PNG_DESC=		Png compressed OpenType embedded bitmaps support
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	png

TABLE_VALIDATION_DESC=	TrueType GX/AAT and OpenType table validation

SIZE_METRICS_CHOICE_DESC=	Size metrics for TrueType fonts
FIX_SIZE_METRICS_DESC=	Fix metrics on size request for scalable fonts (alternative method)
FIX_SIZE_METRICS_EXTRA_PATCHES=	${FILESDIR}/extra-patch-fix_size_metrics.diff
TT_SIZE_METRICS_DESC=	TrueType-like size metrics for 'light' auto-hinting

LCD_FILTERING_DESC?=	Sub-pixel rendering (patented)
LCD_FILTERING_CFLAGS=	-DFT_CONFIG_OPTION_SUBPIXEL_RENDERING

LONG_PCF_NAMES_DESC=	Enable long PCF family names

SUBPIXEL_HINTING_DESC=	Sub-pixel hinting support
V38_DESC=	v38 mode (Infinality code)
V38_VARS=	SUBPIXEL_HINTING_MODE+=1
V40_DESC=	v40 mode (minimal code, a.k.a. ClearType hinting, faster)
V40_VARS=	SUBPIXEL_HINTING_MODE+=2

.include <bsd.port.pre.mk>

SELECTED_MODE=	\
	r=0; \
	for m in ${SUBPIXEL_HINTING_MODE}; \
		do r=$$(($$r | $$m)); \
	done; \
	${ECHO_CMD} $$r

pre-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/builds/unix/install.mk

post-patch:
.if defined(SUBPIXEL_HINTING_MODE)
	@${REINPLACE_CMD} -i '.hinting.bak' \
		-e 's|^\(#define TT_CONFIG_OPTION_SUBPIXEL_HINTING\).*|\1 \
	${SELECTED_MODE:sh}|' \
		${WRKSRC}/include/freetype/config/ftoption.h
.else
	@${REINPLACE_CMD} -i '.hinting.bak' \
		-e 's|^\(#define TT_CONFIG_OPTION_SUBPIXEL_HINTING.*\)|/* \1 */|' \
		${WRKSRC}/include/freetype/config/ftoption.h
.endif

post-patch-DEBUG-on:
	@${REINPLACE_CMD} -i '.debug.bak' \
		-e 's|.*\(#define FT_DEBUG_LEVEL_TRACE\).*|\1|' \
		-e 's|.*\(#define FT_DEBUG_MEMORY\).*|\1|' \
		${WRKSRC}/include/freetype/config/ftoption.h

post-patch-LONG_PCF_NAMES-on:
	@${REINPLACE_CMD} -i '.names.bak' \
		-e 's|.*\(#define PCF_CONFIG_OPTION_LONG_FAMILY_NAMES\).*|\1|' \
		${WRKSRC}/include/freetype/config/ftoption.h

post-patch-TABLE_VALIDATION-on:
	@${REINPLACE_CMD} -e '/valid$$/s|#.*\(AUX_MODULES\)|\1|' \
		${WRKSRC}/modules.cfg

post-patch-TT_SIZE_METRICS-on:
	@${REINPLACE_CMD} -i '.metrics.bak' \
		-e 's|.*\(#define AF_CONFIG_OPTION_TT_SIZE_METRICS\).*|\1|' \
		${WRKSRC}/include/freetype/config/ftoption.h

post-configure:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} setup)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfreetype.so.*

post-install-DOCS-on:
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
