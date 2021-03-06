$NetBSD: patch-mozilla_xpcom_base_nsStackWalk.cpp,v 1.3 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/xpcom/base/nsStackWalk.cpp.orig	2014-06-13 00:46:13.000000000 +0000
+++ mozilla/xpcom/base/nsStackWalk.cpp
@@ -23,12 +23,18 @@ struct CriticalAddress {
 };
 static CriticalAddress gCriticalAddress;
 
-#if defined(HAVE_DLOPEN) || defined(XP_MACOSX)
+// for _Unwind_Backtrace from libcxxrt or libunwind
+// cxxabi.h from libcxxrt implicitly includes unwind.h first
+#if defined(HAVE__UNWIND_BACKTRACE) && !defined(_GNU_SOURCE)
+#define _GNU_SOURCE
+#endif
+
+#if defined(HAVE_DLOPEN) || defined(XP_DARWIN)
 #include <dlfcn.h>
 #endif
 
-#define NSSTACKWALK_SUPPORTS_MACOSX \
-    (defined(XP_MACOSX) && \
+#define NSSTACKWALK_SUPPORTS_DARWIN \
+    (defined(XP_DARWIN) && \
      (defined(__i386) || defined(__ppc__) || defined(HAVE__UNWIND_BACKTRACE)))
 
 #define NSSTACKWALK_SUPPORTS_LINUX \
@@ -36,11 +42,11 @@ static CriticalAddress gCriticalAddress;
      ((defined(__GNUC__) && (defined(__i386) || defined(PPC))) || \
       defined(HAVE__UNWIND_BACKTRACE)))
 
-#define NSSTACKWALK_SUPPORTS_SOLARIS \
+#define notNSSTACKWALK_SUPPORTS_SOLARIS \
     (defined(__sun) && \
      (defined(__sparc) || defined(sparc) || defined(__i386) || defined(i386)))
 
-#if NSSTACKWALK_SUPPORTS_MACOSX
+#if NSSTACKWALK_SUPPORTS_DARWIN
 #include <pthread.h>
 #include <CoreServices/CoreServices.h>
 
@@ -832,7 +838,7 @@ NS_FormatCodeAddressDetails(void *aPC, c
 
 // WIN32 x86 stack walking code
 // i386 or PPC Linux stackwalking code or Solaris
-#elif HAVE_DLADDR && (HAVE__UNWIND_BACKTRACE || NSSTACKWALK_SUPPORTS_LINUX || NSSTACKWALK_SUPPORTS_SOLARIS || NSSTACKWALK_SUPPORTS_MACOSX)
+#elif HAVE_DLADDR && (HAVE__UNWIND_BACKTRACE || NSSTACKWALK_SUPPORTS_LINUX || NSSTACKWALK_SUPPORTS_SOLARIS || NSSTACKWALK_SUPPORTS_DARWIN)
 
 #include <stdlib.h>
 #include <string.h>
@@ -1156,7 +1162,7 @@ FramePointerStackWalk(NS_WalkStackCallba
         (long(next) & 3)) {
       break;
     }
-#if (defined(__ppc__) && defined(XP_MACOSX)) || defined(__powerpc64__)
+#if (defined(__ppc__) && defined(XP_DARWIN)) || defined(__powerpc64__)
     // ppc mac or powerpc64 linux
     void *pc = *(bp+2);
     bp += 3;
@@ -1186,7 +1192,7 @@ FramePointerStackWalk(NS_WalkStackCallba
 }
 
 #define X86_OR_PPC (defined(__i386) || defined(PPC) || defined(__ppc__))
-#if X86_OR_PPC && (NSSTACKWALK_SUPPORTS_MACOSX || NSSTACKWALK_SUPPORTS_LINUX) // i386 or PPC Linux or Mac stackwalking code
+#if X86_OR_PPC && (NSSTACKWALK_SUPPORTS_DARWIN || NSSTACKWALK_SUPPORTS_LINUX) // i386 or PPC Linux or Mac stackwalking code
 
 EXPORT_XPCOM_API(nsresult)
 NS_StackWalk(NS_WalkStackCallback aCallback, uint32_t aSkipFrames,
@@ -1222,9 +1228,6 @@ NS_StackWalk(NS_WalkStackCallback aCallb
 #elif defined(HAVE__UNWIND_BACKTRACE)
 
 // libgcc_s.so symbols _Unwind_Backtrace@@GCC_3.3 and _Unwind_GetIP@@GCC_3.0
-#ifndef _GNU_SOURCE
-#define _GNU_SOURCE
-#endif
 #include <unwind.h>
 
 struct unwind_info {
