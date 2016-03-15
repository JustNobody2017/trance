#ifndef TRANCE_CREATOR_EXPORT_H
#define TRANCE_CREATOR_EXPORT_H

#pragma warning(push, 0)
#include <wx/frame.h>
#include <wx/slider.h>
#include <wx/spinctrl.h>
#pragma warning(pop)

namespace trance_pb {
  class System;
}
class CreatorFrame;
class ExportFrame : public wxFrame {
public:
  enum {
    ID_EXPORT = 1,
    ID_CANCEL = 2,
  };
  ExportFrame(CreatorFrame* parent, trance_pb::System& system,
              const std::string& executable_path,
              const std::string& default_path);

  bool Cancelled() const;

private:
  trance_pb::System& _system;
  std::string _executable_path;
  std::string _path;
  bool _cancelled;

  CreatorFrame* _parent;
  wxSpinCtrl* _width;
  wxSpinCtrl* _height;
  wxSpinCtrl* _fps;
  wxSpinCtrl* _length;
  wxSpinCtrl* _threads;
  wxSlider* _quality;

  void Export();
};

#endif