#include "src/Application.h"
#include "src/Log.h"

int main(void) {
  Core::Log::Inizialize();
  auto app = Core::Application::GetInstance();
  LOG_CORE_INFO("App run");

  app->Run();
  delete app;

  return 0;
}
