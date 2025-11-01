#include "cmake.h"
#include "cmDocumentationEntry.h"
#include "cmSystemTools.h"
#include <vector>

extern "C" __attribute__((visibility("default")))
int cmake_main(int argc, char const* const* argv)
{
  cmSystemTools::EnsureStdPipes();
  
  // Convert to vector for cmake
  std::vector<std::string> args;
  args.reserve(argc);
  for (int i = 0; i < argc; ++i) {
    args.push_back(argv[i]);
  }
  
  // Create cmake instance
  cmake::Role const role = cmake::RoleInternal;
  cmake cm(role, cmState::Unknown);
  cm.SetHomeDirectory("");
  cm.SetHomeOutputDirectory("");
  
  // Run cmake with arguments
  int ret = cm.Run(args, false);
  
  return ret;
}