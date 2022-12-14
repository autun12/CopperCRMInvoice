#include "crpch.h"
#include "CopperCRMRenderer/Utils/PlatformUtils.h"

#include <GLFW/glfw3.h>
#include "CopperCRMRenderer/Core/Application.h"

#define LINUX_PATH_MAX 4096 + 255 + 1

namespace CopperCRMRenderer {
bool FileDialogsUtilityCheck();

std::string FileDialogs::OpenFile(const char* filter) {
    if(!FileDialogsUtilityCheck()) {
        return "";
    }

    const char* file_extension = std::strchr(filter, 0) + 1;

    FILE *fp;
    char path[LINUX_PATH_MAX];

    std::string cmdline = std::string("zenity --file-selection --modal \"") + std::string(file_extension) + std::string("\" --title=\"Open File\"");
    fp = popen(cmdline.c_str(), "r");
    
    if (fp == NULL) {
        CR_CORE_ERROR("Null file pointer in FileDialogs::OpenFile().\n");
    }

    //Check for File dialog cancellation.
    if(fgets(path, LINUX_PATH_MAX, fp) == NULL) {
        pclose(fp);
        return "";
    }

    pclose(fp);

    std::string file_choice = std::string(path);
    
    int endline_pos = file_choice.find_first_of("\n");
    file_choice.resize(endline_pos);
    
    return file_choice;
}

bool FileDialogsUtilityCheck() {
    FILE *fp;
    char path[LINUX_PATH_MAX];

    fp = popen("which zenity", "r");
    
    if(fp == NULL) {
        CR_CORE_ERROR("Null file pointer in FileDialogs::OpenFile().\n");
    }

    if(fgets(path, LINUX_PATH_MAX, fp) == NULL) {
        CR_CORE_WARN("Zenity not found in path. See CopperCRM pre-requisites to install.");
        pclose(fp);
        return false;
    }

    pclose(fp);

    return true;
}
}