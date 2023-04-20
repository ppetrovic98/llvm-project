#include "llvm/IR/DebugInfo.h"
#include "llvm/Transforms/Utils/DeleteDebugInstruction.h"
#include <vector>

using namespace llvm;

// Pozivamo sa:
// $ opt -passes=delete-dbg-inst <ime_fajla.ll > output
// $ llvm-dis output

PreservedAnalyses
DeleteDebugInstructionsPass::run(Function &F, FunctionAnalysisManager &AM) {
  bool changed = false;

  /* RESENJE 1 */

  //   std::vector<Instruction *> instsToDelete;
  //   for (auto &BB : F) {
  //     for (auto I = BB.begin(), E = BB.end(); I != E;) {
  //       if (isa<DbgInfoIntrinsic>(&I)) {
  //         instsToDelete.push_back(&I);
  //         changed = true;
  //       }
  //     }
  //   }

  //   for (auto inst : instsToDelete) {
  //     inst->eraseFromParent();
  //   }

  /* RESENJE 2 */
  for (auto &BB : F) {
    for (auto I = BB.begin(); I != BB.end();) {
      Instruction &inst = *I++;
      if (isa<DbgInfoIntrinsic>(inst)) {
        inst.eraseFromParent();
        changed = true;
      }
    }
  }

  if (changed) {
    return PreservedAnalyses::none();
  } else {
    return PreservedAnalyses::all();
  }
}