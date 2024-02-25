// #include "src/Application.h"
// #include "src/Log.h"
#include "src/Macro.h"

int main(void) {
  Core::Log::Inizialize();
  // auto app = Core::Application::GetInstance();
  // LOG_CORE_INFO("App run");

  // app->Run();
  // delete app;
  CORE_ASSERT(false, "ciao!");

  return 0;
}
