#ifndef RAY_UTIL_VISIBILITY_H
#define RAY_UTIL_VISIBILITY_H

#if defined(_WIN32) || defined(__CYGWIN__)
#if defined(_MSC_VER)
#pragma warning(disable : 4251)
#else
#pragma GCC diagnostic ignored "-Wattributes"
#endif

#ifdef RAY_STATIC
#define RAY_EXPORT
#elif defined(RAY_EXPORTING)
#define RAY_EXPORT __declspec(dllexport)
#else
#define RAY_EXPORT __declspec(dllimport)
#endif

#define RAY_NO_EXPORT
#else  // Not Windows
#ifndef RAY_EXPORT
#define RAY_EXPORT __attribute__((visibility("default")))
#endif
#ifndef RAY_NO_EXPORT
#define RAY_NO_EXPORT __attribute__((visibility("hidden")))
#endif
#endif  // Non-Windows

// gcc and clang disagree about how to handle template visibility when you have
// explicit specializations https://llvm.org/bugs/show_bug.cgi?id=24815

#if defined(__clang__)
#define RAY_EXTERN_TEMPLATE extern template class RAY_EXPORT
#else
#define RAY_EXTERN_TEMPLATE extern template class
#endif

// This is a complicated topic, some reading on it:
// http://www.codesynthesis.com/~boris/blog/2010/01/18/dll-export-cxx-templates/
#if defined(_MSC_VER) || defined(__clang__)
#define RAY_TEMPLATE_EXPORT RAY_EXPORT
#else
#define RAY_TEMPLATE_EXPORT
#endif

#endif  // RAY_UTIL_VISIBILITY_H
