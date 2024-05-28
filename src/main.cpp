#include "clang/AST/AST.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/FrontendPluginRegistry.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Basic/Diagnostic.h"
#include "llvm/Support/Regex.h"

using namespace clang;

namespace {

class FunctionVisitor : public RecursiveASTVisitor<FunctionVisitor> {
public:
    explicit FunctionVisitor(ASTContext *Context) : Context(Context) {}

    bool VisitFunctionDecl(FunctionDecl *F) {
        StringRef Name = F->getName();
        llvm::Regex SnakeCase("^[a-z]+(_[a-z]+)*$");

        if (!SnakeCase.match(Name)) {
            DiagnosticsEngine &Diag = Context->getDiagnostics();
            unsigned ID = Diag.getCustomDiagID(DiagnosticsEngine::Warning,
                                               "Function name '%0' is not in snake_case");
            Diag.Report(F->getLocation(), ID) << Name;
        }

        return true;
    }

private:
    ASTContext *Context;
};

class FunctionASTConsumer : public ASTConsumer {
public:
    explicit FunctionASTConsumer(ASTContext *Context) : Visitor(Context) {}

    void HandleTranslationUnit(ASTContext &Context) override {
        Visitor.TraverseDecl(Context.getTranslationUnitDecl());
    }

private:
    FunctionVisitor Visitor;
};

class FunctionFrontendAction : public PluginASTAction {
public:
    FunctionFrontendAction() {
        llvm::errs() << "c-style plugin loaded\n";
    }

protected:
    std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI, llvm::StringRef) override {
        return std::make_unique<FunctionASTConsumer>(&CI.getASTContext());
    }

    bool ParseArgs(const CompilerInstance &CI, const std::vector<std::string> &args) override {
        return true;
    }
};

}

static FrontendPluginRegistry::Add<FunctionFrontendAction> X("hello", "c-style-project created");
