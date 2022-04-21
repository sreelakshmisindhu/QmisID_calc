// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME FTAna_d
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "FTAna.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_FTAna(void *p = 0);
   static void *newArray_FTAna(Long_t size, void *p);
   static void delete_FTAna(void *p);
   static void deleteArray_FTAna(void *p);
   static void destruct_FTAna(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::FTAna*)
   {
      ::FTAna *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::FTAna >(0);
      static ::ROOT::TGenericClassInfo 
         instance("FTAna", ::FTAna::Class_Version(), "FTAna.h", 20,
                  typeid(::FTAna), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::FTAna::Dictionary, isa_proxy, 4,
                  sizeof(::FTAna) );
      instance.SetNew(&new_FTAna);
      instance.SetNewArray(&newArray_FTAna);
      instance.SetDelete(&delete_FTAna);
      instance.SetDeleteArray(&deleteArray_FTAna);
      instance.SetDestructor(&destruct_FTAna);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::FTAna*)
   {
      return GenerateInitInstanceLocal((::FTAna*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::FTAna*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr FTAna::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *FTAna::Class_Name()
{
   return "FTAna";
}

//______________________________________________________________________________
const char *FTAna::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::FTAna*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int FTAna::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::FTAna*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *FTAna::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::FTAna*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *FTAna::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::FTAna*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void FTAna::Streamer(TBuffer &R__b)
{
   // Stream an object of class FTAna.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(FTAna::Class(),this);
   } else {
      R__b.WriteClassBuffer(FTAna::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_FTAna(void *p) {
      return  p ? new(p) ::FTAna : new ::FTAna;
   }
   static void *newArray_FTAna(Long_t nElements, void *p) {
      return p ? new(p) ::FTAna[nElements] : new ::FTAna[nElements];
   }
   // Wrapper around operator delete
   static void delete_FTAna(void *p) {
      delete ((::FTAna*)p);
   }
   static void deleteArray_FTAna(void *p) {
      delete [] ((::FTAna*)p);
   }
   static void destruct_FTAna(void *p) {
      typedef ::FTAna current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::FTAna

namespace {
  void TriggerDictionaryInitialization_FTAna_d_Impl() {
    static const char* headers[] = {
"FTAna.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/sft.cern.ch/lcg/releases/ROOT/v6.20.06-3f7fd/x86_64-centos7-gcc8-opt/include/",
"/afs/cern.ch/work/s/ssindhu/private/common-framework/split/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "FTAna_d dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$FTAna.h")))  FTAna;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "FTAna_d dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "FTAna.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"FTAna", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("FTAna_d",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_FTAna_d_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_FTAna_d_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_FTAna_d() {
  TriggerDictionaryInitialization_FTAna_d_Impl();
}
