#include "llvm/Transforms/Utils/PrintDebugInstructions.h"
#include "llvm/IR/DebugInfo.h"

using namespace llvm;

PreservedAnalyses PrintDebugInstructionsPass::run(Function &F,
                                                  FunctionAnalysisManager &AM) {
  size_t dbgValueCount{0};
  size_t dbgDeclareCount{0};
  size_t dbgAssignCount{0};

  for (auto &BB : F) {
    errs() << "Function: " << F.getName() << "\n";
    for (auto &I : BB) {
      if (dyn_cast<DbgValueInst>(&I)) {
        dbgValueCount++;
      } else if (dyn_cast<DbgDeclareInst>(&I)) {
        dbgDeclareCount++;
      } else if (dyn_cast<DbgAssignIntrinsic>(&I)) {
        dbgAssignCount++;
      }
    }
  }

  errs() << "\t" << "llvm.dbg.values: " << dbgValueCount << "\n";
  errs() << "\t" << "llvm.dbg.declare: " << dbgDeclareCount << "\n";
  errs() << "\t" << "llvm.dbg.assign: " << dbgAssignCount << "\n";

  return PreservedAnalyses::all();
}