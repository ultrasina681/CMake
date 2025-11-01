#include "cmake.h"
#include "cmDocumentationEntry.h"
#include "cmSystemTools.h"
#include <vector>
#include <cstdlib>

extern "C" __attribute__((visibility("default")))
int cmake_main(int argc, char const* const* argv)
{
  // Read CMAKE_ROOT from environment and set it
  const char* cmakeRoot = std::getenv("CMAKE_ROOT");
  if (cmakeRoot && cmakeRoot[0] != '\0') {
    cmSystemTools::s_ForceUnixPaths = true;
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
  cm.SetHomeDirectory("");
  cm.SetHomeOutputDirectory("");
  
  // Add CMAKE_ROOT to cache if provided
  if (cmakeRoot && cmakeRoot[0] != '\0') {
    std::string cacheEntry = "CMAKE_ROOT:INTERNAL=" + std::string(cmakeRoot);
    cm.GetCurrentSnapshot().SetDefinition("CMAKE_ROOT", cmakeRoot);
  }
  
  // Run cmake with arguments
  int ret = cm.Run(args, false);
  
  return ret;
}