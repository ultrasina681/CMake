#include "cmake.h"
#include "cmDocumentationEntry.h"
#include <vector>

extern "C" __attribute__((visibility("default")))
int cmake_main(int argc, char const* const* argv)
{
  cmake cm(cmake::RoleInternal, cmState::Unknown);
  cm.SetHomeDirectory("");
  cm.SetHomeOutputDirectory("");
  
  std::vector<std::string> args;
  for (int i = 0; i < argc; ++i) {
    args.push_back(argv[i]);
  }
  
  return cm.Run(args);
}