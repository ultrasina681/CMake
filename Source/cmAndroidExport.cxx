#include "cmake.h"
#include "cmSystemTools.h"
#include "cmDocumentationEntry.h"
#include "cmState.h"
#include <vector>

extern "C" __attribute__((visibility("default")))
int cmake_main(int argc, char const* const* argv)
{
  // Ensure CMAKE_ROOT is found from environment
  cmSystemTools::FindCMakeResources(argv[0]);
  
  // Convert to vector for cmake
  std::vector<std::string> args;
  args.reserve(argc);
  for (int i = 0; i < argc; ++i) {
    args.push_back(argv[i]);
  }
  
  // Create cmake instance with proper role
  cmake::Role const role = cmake::RoleProject;
  cmake cm(role, cmState::Project);
  
  // Initialize
  cm.SetHomeDirectory("");
  cm.SetHomeOutputDirectory("");
  
  // Run cmake with arguments
  int ret = cm.Run(args, false);
  
  return ret;
}