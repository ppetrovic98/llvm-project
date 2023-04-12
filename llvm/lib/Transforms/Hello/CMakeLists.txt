add_llvm_library( LLVMHello MODULE 
  Hello.cpp

  PLUGIN_TOOL
  opt
  )
