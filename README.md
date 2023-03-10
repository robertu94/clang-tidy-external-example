# Example of external clang-tidy check

Fully-working external clang-tidy module example!
It's not a very useful check, but I wrote this quickly as a proof of concept.

Dependencies (tested Fedora 37):

- clang-devel (or equivelent)
- clang-tools-extra-devel (or equivelent)

When this was written `clang-tools-extra-devel` was in the testing repo (should be in the primary repos soon and for Fedora 38), and may need to be installed with `sudo dnf install --enablerepo=updates-testing --refresh --advisory=FEDORA-2023-8a08ac5d70 clang-tools-extra-devel` depending on when you read this.

## test if the check was loaded

```bash
 clang-tidy --checks=-*,*libpressio* -list-checks -load ./build/libmyclang_tidy.so
```

## run the check on some source code

```bash
clang-tidy -p build --checks=-*,*libpressio* -load ~/git/play/clang-tidy-external/build/libmyclang_tidy.so src/*.cc
```
