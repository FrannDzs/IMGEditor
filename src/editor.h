#pragma once
#include "ui/application.h"
#include "imgmgr.h"
#include "SimpleIni.h"

class Editor
{
private:
    static inline std::vector<IMGArchive> ArchiveList {  IMGArchive("Untitled", true) };
    static inline IMGArchive* pSelectedArchive;         // pointer to the selected archive in editor
    static inline EntryInfo *pContextEntry = nullptr;  // pointer to the selected archive entry in editor
    static inline Ui::Application *pApp = nullptr;
    static inline CSimpleIniA Config;

    // Popups
    static void AboutPopUp();
    static void WelcomePopup();

    static void ProcessContextMenu();
    static void ProcessMenuBar();
    static void ProcessWindow();

public:

    // Adds a new archive to the list
    static void AddArchiveEntry(IMGArchive &&archive);

    // Returns true if archive with the given name already exists
    static bool DoesArchiveExist(const std::string &name);

    // Initializes & runs the IMGEditor
    static void Run();

    // Does cleanup for the editor
    static void Shutdown();
};