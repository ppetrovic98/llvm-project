#ifndef LLVM_TRANSFORMS_UTILS_MYFIRSTPASS_H
#define LLVM_TRANSFORMS_UTILS_MYFIRSTPASS_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class MyFirstPass : public PassInfoMixin<MyFirstPass> {
public:
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
  static bool isRequired() {
    return true;
  }; // bez ovoga pass ce preskociti funkcije sa optnone atributom (bar bi trebalo ?)
};

} // namespace llvm

#endif // LLVM_TRANSFORMS_UTILS_MYFIRSTPASS_H