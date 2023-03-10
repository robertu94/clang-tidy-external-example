#include <clang-tidy/ClangTidyCheck.h>
#include <clang-tidy/ClangTidyModule.h>
#include <clang-tidy/ClangTidyModuleRegistry.h>

namespace clang {
namespace tidy {
namespace libpressio {

    using namespace clang::ast_matchers;

class LibPressioCompressCheck : public ClangTidyCheck {
public:
  LibPressioCompressCheck(StringRef Name, ClangTidyContext *Context)
      : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override {
      Finder->addMatcher(functionDecl(matchesName("^.*read_many_.+$")).bind("root"), this);
  }
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override {
      const auto* ptr = Result.Nodes.getNodeAs<FunctionDecl>("root");
      diag(ptr->getLocation(), "function %0 is insufficiently awesome")
      << ptr;
  }
};

} // namespace readability

class LibPressioModule : public ClangTidyModule {
 public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<libpressio::LibPressioCompressCheck>(
        "libpressio-compress");
  }
};
static ClangTidyModuleRegistry::Add<LibPressioModule> X("libpressio",
                                                "LibPressioChecks");

} // namespace tidy
} // namespace clang
