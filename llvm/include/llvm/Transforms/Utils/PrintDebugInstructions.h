#ifndef LLVM_TRANSFORMS_UTILS_PRINTDEBUGINSTRUCTIONS_H
#define LLVM_TRANSFORMS_UTILS_PRINTDEBUGINSTRUCTIONS_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class PrintDebugInstructionsPass
    : public PassInfoMixin<PrintDebugInstructionsPass> {
public:
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
};

} // namespace llvm

#endif