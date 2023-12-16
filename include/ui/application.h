#pragma once
#include "imgui/imgui.h"
#include "renderer.h"
#include "specification.h"

namespace Ui {
class Application {
private:
  Specification Info;

public:
  Application(Specification &Spec);
  ~Application();

  CVector2 GetWindowSize();

  // Returns the active thememode
  eTheme GetTheme();

  // Sets the current theme
  void SetTheme(eTheme theme);

  // Start the application loop
  void Run();

  // Set the poup function
  void SetPopup(std::function<void()> Func);

  void CallDropHandler(const char *path);
};
} // namespace Ui
