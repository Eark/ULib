// ============================================================================
//
// = LIBRARY
//    ULib - c++ library
//
// = FILENAME
//    mod_rpc.h
//
// = AUTHOR
//    Stefano Casazza
//
// ============================================================================

#ifndef U_MOD_RPC_H
#define U_MOD_RPC_H 1

#include <ulib/net/server/server_plugin.h>

class URPCParser;

class U_EXPORT URpcPlugIn : public UServerPlugIn {
public:

   // Check for memory error
   U_MEMORY_TEST

   // COSTRUTTORI

   URpcPlugIn()
      {
      U_TRACE_REGISTER_OBJECT(0, URpcPlugIn, "", 0)
      }

   virtual ~URpcPlugIn();

   // define method VIRTUAL of class UServerPlugIn

   // Server-wide hooks

   virtual int handlerConfig(UFileConfig& cfg) U_DECL_FINAL;
   virtual int handlerInit() U_DECL_FINAL __pure;

   // Connection-wide hooks

   virtual int handlerREAD() U_DECL_FINAL;
   virtual int handlerRequest() U_DECL_FINAL;

   // DEBUG

#if defined(U_STDCPP_ENABLE) && defined(DEBUG)
   const char* dump(bool reset) const;
#endif

protected:
   static bool is_rpc_msg;
   static URPCParser* rpc_parser;

private:
#ifdef U_COMPILER_DELETE_MEMBERS
   URpcPlugIn(const URpcPlugIn&) = delete;
   URpcPlugIn& operator=(const URpcPlugIn&) = delete;
#else
   URpcPlugIn(const URpcPlugIn&) : UServerPlugIn() {}
   URpcPlugIn& operator=(const URpcPlugIn&)        { return *this; }
#endif
};

#endif
