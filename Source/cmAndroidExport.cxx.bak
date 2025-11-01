#include "cmake.h"
#include "cmDocumentationEntry.h"
#include "cmSystemTools.h"
#include <vector>
#include <cstdlib>

extern "C" __attribute__((visibility("default")))
int cmake_main(int argc, char const* const* argv)
{
  // Check for CMAKE_ROOT environment variable
  const char* cmakeRoot = std::getenv("CMAKE_ROOT");
  if (cmakeRoot && cmakeRoot[0] != '\0') {
    cmSystemTools::PutEnv(std::string("CMAKE_ROOT=") + cmakeRoot);
  }
  
  // Convert to vector for cmake
  std::vector<std::string> args;
  args.reserve(argc);
  for (int i = 0; i < argc; ++i) {
    args.push_back(argv[i]);
  }
  
  // Create cmake instance
  cmake::Role const role = cmake::RoleInternal;
  cmake cm(role, cmState::Unknown);
  
  // Set home directories
  if (cmakeRoot && cmakeRoot[0] != '\0') {
    cm.SetCMakeRoot(cmakeRoot);
  }
  
  cm.SetHomeDirectory("");
  cm.SetHomeOutputDirectory("");
  
  // Run cmake with arguments
  int ret = cm.Run(args, false);
  
  return ret;
}