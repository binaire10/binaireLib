#pragma once
/*
#ifdef __WIN32__
#   if defined(BINAIRELIB_LIBRARY)
#       define BINAIRELIBSHARED_EXPORT __declspec(dllexport)
#   else
#       define BINAIRELIBSHARED_EXPORT __declspec(dllimport)
#   endif
#elif defined(__linux__)
#   if defined(BINAIRELIB_LIBRARY)
#       define BINAIRELIBSHARED_EXPORT __attribute__((visibility("default")))
#   else
#       define BINAIRELIBSHARED_EXPORT
#   endif
#endif
*/

#define BINAIRELIBSHARED_EXPORT
