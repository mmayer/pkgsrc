$NetBSD: patch-libvncserver_minilzo.h,v 1.1 2014/08/11 21:22:15 markd Exp $

Update LZO to version 2.07 in libvncserver. 

Temporary fix for CVE-2014-4607 for 4.14.

--- libvncserver/minilzo.h
+++ libvncserver/minilzo.h
@@ -2,21 +2,7 @@
 
    This file is part of the LZO real-time data compression library.
 
-   Copyright (C) 2010 Markus Franz Xaver Johannes Oberhumer
-   Copyright (C) 2009 Markus Franz Xaver Johannes Oberhumer
-   Copyright (C) 2008 Markus Franz Xaver Johannes Oberhumer
-   Copyright (C) 2007 Markus Franz Xaver Johannes Oberhumer
-   Copyright (C) 2006 Markus Franz Xaver Johannes Oberhumer
-   Copyright (C) 2005 Markus Franz Xaver Johannes Oberhumer
-   Copyright (C) 2004 Markus Franz Xaver Johannes Oberhumer
-   Copyright (C) 2003 Markus Franz Xaver Johannes Oberhumer
-   Copyright (C) 2002 Markus Franz Xaver Johannes Oberhumer
-   Copyright (C) 2001 Markus Franz Xaver Johannes Oberhumer
-   Copyright (C) 2000 Markus Franz Xaver Johannes Oberhumer
-   Copyright (C) 1999 Markus Franz Xaver Johannes Oberhumer
-   Copyright (C) 1998 Markus Franz Xaver Johannes Oberhumer
-   Copyright (C) 1997 Markus Franz Xaver Johannes Oberhumer
-   Copyright (C) 1996 Markus Franz Xaver Johannes Oberhumer
+   Copyright (C) 1996-2014 Markus Franz Xaver Johannes Oberhumer
    All Rights Reserved.
 
    The LZO library is free software; you can redistribute it and/or
@@ -49,7 +35,7 @@
 #ifndef __MINILZO_H
 #define __MINILZO_H 1
 
-#define MINILZO_VERSION         0x2040
+#define MINILZO_VERSION         0x2070
 
 #ifdef __LZOCONF_H
 #  error "you cannot use both LZO and miniLZO"
@@ -77,7 +63,7 @@
  */
 
 #define LZO1X_MEM_COMPRESS      LZO1X_1_MEM_COMPRESS
-#define LZO1X_1_MEM_COMPRESS    ((lzo_uint32) (16384L * lzo_sizeof_dict_t))
+#define LZO1X_1_MEM_COMPRESS    ((lzo_uint32_t) (16384L * lzo_sizeof_dict_t))
 #define LZO1X_MEM_DECOMPRESS    (0)
 
 

