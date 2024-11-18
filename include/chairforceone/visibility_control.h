#ifndef CHAIRFORCEONE__VISIBILITY_CONTROL_H_
#define CHAIRFORCEONE__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define CHAIRFORCEONE_EXPORT __attribute__ ((dllexport))
    #define CHAIRFORCEONE_IMPORT __attribute__ ((dllimport))
  #else
    #define CHAIRFORCEONE_EXPORT __declspec(dllexport)
    #define CHAIRFORCEONE_IMPORT __declspec(dllimport)
  #endif
  #ifdef CHAIRFORCEONE_BUILDING_LIBRARY
    #define CHAIRFORCEONE_PUBLIC CHAIRFORCEONE_EXPORT
  #else
    #define CHAIRFORCEONE_PUBLIC CHAIRFORCEONE_IMPORT
  #endif
  #define CHAIRFORCEONE_PUBLIC_TYPE CHAIRFORCEONE_PUBLIC
  #define CHAIRFORCEONE_LOCAL
#else
  #define CHAIRFORCEONE_EXPORT __attribute__ ((visibility("default")))
  #define CHAIRFORCEONE_IMPORT
  #if __GNUC__ >= 4
    #define CHAIRFORCEONE_PUBLIC __attribute__ ((visibility("default")))
    #define CHAIRFORCEONE_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define CHAIRFORCEONE_PUBLIC
    #define CHAIRFORCEONE_LOCAL
  #endif
  #define CHAIRFORCEONE_PUBLIC_TYPE
#endif
#endif  // CHAIRFORCEONE__VISIBILITY_CONTROL_H_
// Generated 18-Nov-2024 10:35:09
// Copyright 2019-2020 The MathWorks, Inc.
