#include "llvm/Transforms/Utils/MyFirstPass.h"

using namespace llvm;

PreservedAnalyses MyFirstPass::run(Function &F, FunctionAnalysisManager &AM) {
  errs() << "Function name: " << F.getName()
         << "\n"; // errs() vraca referencu na raw_ostream za
                  // ispisivanje error poruka
  errs() << "Number of arguments: " << F.arg_size() << "\n";
  return PreservedAnalyses::all();
}