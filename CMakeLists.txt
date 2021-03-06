project(dolphin-plugins)

cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)

include(FeatureSummary)

set(QT_MIN_VERSION "5.8.0")
set(KF5_MIN_VERSION "5.0.0")

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
    Core
    Widgets
    Network
)

find_package(ECM ${KF5_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
    XmlGui
    I18n
    KIO
    TextWidgets
)

find_package(DolphinVcs)
set_package_properties(DolphinVcs PROPERTIES
    DESCRIPTION "the Dolphin version control plugin library"
    URL "https://kde.org/applications/system/org.kde.dolphin"
    TYPE REQUIRED
    PURPOSE "Provides the version control plugin interface."
)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)
include(ECMMarkNonGuiExecutable)
include(ECMOptionalAddSubdirectory)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_definitions(-DQT_NO_URL_CAST_FROM_STRING)

ecm_optional_add_subdirectory(svn)
ecm_optional_add_subdirectory(git)
ecm_optional_add_subdirectory(bazaar)
ecm_optional_add_subdirectory(dropbox)
ecm_optional_add_subdirectory(hg)

install(FILES org.kde.dolphin-plugins.metainfo.xml
        DESTINATION ${KDE_INSTALL_METAINFODIR})

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
